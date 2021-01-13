using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.Events;
using UnityEngine.Profiling;
#if UNITY_EDITOR
using System;
using System.Diagnostics;
using Debug = UnityEngine.Debug;
#endif

namespace Tesrym.AnchorSystem {
    [DefaultExecutionOrder(-100)]
    public class Anchor : MonoBehaviour {

        public static Anchor Instance {
            get; private set;
        } = null;

        [SerializeField]
        private float radius = 1000;
        public static float Radius {
            get {
                if (Instance != null) {
                    return Instance.radius;
                } else {
                    Debug.LogWarning("Something is trying to use the floating origin system, but does not exist!");
                    return float.MaxValue;
                }
            }
            set {
                if (Instance != null) {
                    Instance.radius = value;
                } else {
                    Debug.LogWarning("Something is trying to use the floating origin system, but does not exist!");
                    //Do nothing
                }
            }
        }

        [SerializeField]
        private Vector3 _worldOrigin = Vector3.zero;
        public static Vector3 WorldOrigin {
            get {
                if (Instance != null) {
                    return Instance._worldOrigin;
                } else {
                    Debug.LogWarning("Something is trying to use the floating origin system, but does not exist!");
                    return Vector3.zero;
                }
            }
            set {
                if (Instance != null) {
                    Instance._worldOrigin = value;
                } else {
                    Debug.LogWarning("Something is trying to use the floating origin system, but does not exist!");
                    //Do nothing
                }
            }
        }

        public UnityEvent<Vector3> offsetEvent;
        public UnityEvent<Vector3> originEvent;

        public static event Action<Vector3> OnOffsetEvent = (offset) => {};

#if UNITY_EDITOR
        [SerializeField]
        private bool showAnchor = false;
        [SerializeField]
        private bool showOrigin = false;
        private Stopwatch timer = new Stopwatch();
        [SerializeField]
        private double frameTime;
#endif

        private void OnEnable() {
            Instance = this;
            Run();

        }

        private void LateUpdate() {
            Run();

        }

        private void OnDisable() {
            Stop();
            Instance = null;

        }

        private void OnDrawGizmos() {
            //Selection radius
            float selection = .99f - (1 - Mathf.Sin(Time.time * 5)) * .1f;

            if (showAnchor) {
                Gizmos.color = Color.blue;
                if (Application.isPlaying && Instance != null) {
                    Gizmos.DrawWireSphere(Vector3.zero, radius);
                    Gizmos.color = Color.green - new Color(0, 0, 0, .85f);
                    Gizmos.DrawWireSphere(Vector3.zero, radius * selection);
                    Gizmos.DrawRay(transform.position, -transform.position);
                    Gizmos.DrawWireSphere(Vector3.zero, 10);
                }
            }

            if (showOrigin) {
                Gizmos.color = Color.red;
                if (Application.isPlaying && Instance != null) {
                    Gizmos.DrawRay(transform.position, WorldOrigin - transform.position);
                    Gizmos.DrawWireSphere(WorldOrigin, radius);
                } else {
                    Gizmos.DrawRay(transform.position, -transform.position);
                    Gizmos.DrawWireSphere(Vector3.zero, radius);
                    Gizmos.color = Color.green - new Color(0, 0, 0, .5f);
                    Gizmos.DrawWireSphere(Vector3.zero, radius * selection);
                }
            }
        }

        private void Run() {
            Vector3 offset = transform.position;

            if (offset.magnitude > Radius) {
#if UNITY_EDITOR
                timer.Restart();
#endif
                Profiler.BeginSample("Anchor reposition", this);
                
                MoveRootGameObjects(offset);
                MoveTrailRenderers(offset);
                MoveLineRenderers(offset);
                MoveParticles(offset);
                OnOffsetEvent(offset);

                Profiler.EndSample();

                offsetEvent.Invoke(offset);
                WorldOrigin -= offset;
                originEvent.Invoke(WorldOrigin);

#if UNITY_EDITOR
                timer.Stop();
                double nanoSeconds = 1000000000.0 * timer.ElapsedTicks / Stopwatch.Frequency;
                double milliSeconds = nanoSeconds / 1000000.0;
                frameTime = milliSeconds;
#endif
            }
            
        }

        private void Stop() {
            Vector3 offset = WorldOrigin;
            Profiler.BeginSample("Anchor stop", this);
            
            MoveRootGameObjects(offset);
            MoveTrailRenderers(offset);
            MoveLineRenderers(offset);
            MoveParticles(offset);
            OnOffsetEvent(offset);

            Profiler.EndSample();

            offsetEvent.Invoke(offset);
            WorldOrigin = Vector3.zero;
            originEvent.Invoke(WorldOrigin);

        }

        private void MoveRootGameObjects(Vector3 offset) {
            for (int i = 0; i < SceneManager.sceneCount; i++) {
                foreach (GameObject gameObject in SceneManager.GetSceneAt(i).GetRootGameObjects())
                    gameObject.transform.position -= offset;

            }
        }

        private void MoveTrailRenderers(Vector3 offset) {
            TrailRenderer[] trailRenderers = FindObjectsOfType<TrailRenderer>();
            foreach (TrailRenderer trailRenderer in trailRenderers) {
                Vector3[] positions = new Vector3[trailRenderer.positionCount];

                int positionCount = trailRenderer.GetPositions(positions);
                for (int i = 0; i < positionCount; ++i)
                    positions[i] -= offset;

                trailRenderer.SetPositions(positions);
            }
        }

        private void MoveLineRenderers(Vector3 offset) {
            LineRenderer[] lineRenderers = FindObjectsOfType<LineRenderer>();
            foreach (LineRenderer line in lineRenderers) {
                Vector3[] positions = new Vector3[line.positionCount];

                int positionCount = line.GetPositions(positions);
                for (int i = 0; i < positionCount; ++i)
                    positions[i] -= offset;

                line.SetPositions(positions);
            }
        }

        private void MoveParticles(Vector3 offset) {
            ParticleSystem[] particleSystems = FindObjectsOfType<ParticleSystem>();
            foreach (ParticleSystem particleSystem in particleSystems) {
                if (particleSystem.main.simulationSpace != ParticleSystemSimulationSpace.World)
                    continue;

                int particlesNeeded = particleSystem.main.maxParticles;

                if (particlesNeeded <= 0)
                    continue;

                bool wasPaused = particleSystem.isPaused;
                bool wasPlaying = particleSystem.isPlaying;

                if (!wasPaused)
                    particleSystem.Pause();

                ParticleSystem.Particle[] parts = new ParticleSystem.Particle[particlesNeeded];
                int num = particleSystem.GetParticles(parts);

                for (int i = 0; i < num; i++) {
                    parts[i].position -= offset;
                }

                particleSystem.SetParticles(parts, num);

                if (wasPlaying)
                    particleSystem.Play();
            }
        }

    }
}
