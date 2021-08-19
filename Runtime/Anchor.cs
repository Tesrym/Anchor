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

        /// <summary>
        /// Anchor singleton
        /// </summary>
        public static Anchor Instance {
            get; private set;
        } = null;

        /// <summary>
        /// If Anchor need to replace the scene back to original place when disabled
        /// </summary>
        [SerializeField]
        private bool _replaceSceneWhenDisable;

        /// <summary>
        /// The min radius for Anchor to offset the scene
        /// </summary>
        [SerializeField]
        private float _radius = 1000;
        public static float Radius {
            get {
                if (Instance != null) {
                    return Instance._radius;
                } else {
                    Debug.LogWarning("Something is trying to use the floating origin system, but does not exist!");
                    return float.MaxValue;
                }
            }
            set {
                if (Instance != null) {
                    Instance._radius = value;
                } else {
                    Debug.LogWarning("Something is trying to use the floating origin system, but does not exist!");
                    //Do nothing
                }
            }
        }

        /// <summary>
        /// The current real world origin coordinate relative to the scene origin
        /// </summary>
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

        //Unity events for simplicity
        
        /// <summary>
        /// Call the event when offsetting the scene, pass in the offset Vector
        /// </summary>
        public UnityEvent<Vector3> offsetUnityEvent;
        /// <summary>
        /// Call the event when offsetting the scene, pass in the new world origin Vector
        /// </summary>
        public UnityEvent<Vector3> originUnityEvent;

        //Required for editor script and initially not intended for builds.
        //But leaving it for builds anyway.
        public static event Action<Vector3> OffsetEvent = (offset) => {};

#if UNITY_EDITOR
        /// <summary>
        /// If show the current Anchor detect region.
        /// </summary>
        [SerializeField]
        private bool showAnchor = false;
        /// <summary>
        /// If show the real world orgin position
        /// </summary>
        [SerializeField]
        private bool showOrigin = false;
        /// <summary>
        /// Timer for performance statistic
        /// </summary>
        private Stopwatch timer = new Stopwatch();
        [SerializeField]
        private double frameTime;
#endif

        private void OnEnable() {
            // initialize singleton
            Instance = this;
            Run();
        }

        // Run the anchor update in Fixed update for better performance and prevent some physics error.
        // Also friendly for some position-relevant logic run in FixedUpdate() of other MonoBehaviour
        private void FixedUpdate() {
            Run();
        }

        private void OnDisable() {
            // No need for running the anchor offset logic again when Disable
            // When disable the Anchor,
            // some missing method in the offset and origin event may cause exception
            if (_replaceSceneWhenDisable)
            {
                Stop();
            }
            Instance = null;
        }

        private void OnDrawGizmos() {
            //Animated selection radius for the user in green.
            //Shows which mode is used, anchor (blue) or scene origin (red).
            float selection = .99f - (1 - Mathf.Sin(Time.time * 5)) * .1f;

            if (showAnchor) {
                Gizmos.color = Color.blue;
                if (Application.isPlaying && Instance != null) {
                    Gizmos.DrawWireSphere(Vector3.zero, _radius);
                    Gizmos.color = Color.green - new Color(0, 0, 0, .85f);
                    Gizmos.DrawWireSphere(Vector3.zero, _radius * selection);
                    Gizmos.DrawRay(transform.position, -transform.position);
                    Gizmos.DrawWireSphere(Vector3.zero, 10);
                }
            }

            if (showOrigin) {
                Gizmos.color = Color.red;
                if (Application.isPlaying && Instance != null) {
                    Gizmos.DrawRay(transform.position, WorldOrigin - transform.position);
                    Gizmos.DrawWireSphere(WorldOrigin, _radius);
                } else {
                    Gizmos.DrawRay(transform.position, -transform.position);
                    Gizmos.DrawWireSphere(Vector3.zero, _radius);
                    Gizmos.color = Color.green - new Color(0, 0, 0, .5f);
                    Gizmos.DrawWireSphere(Vector3.zero, _radius * selection);
                }
            }
        }

        /// <summary>
        /// The main logic of Anchor scene offset
        /// </summary>
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
                OffsetEvent(offset);

                Profiler.EndSample();

                offsetUnityEvent?.Invoke(offset);
                WorldOrigin -= offset;
                originUnityEvent?.Invoke(WorldOrigin);

#if UNITY_EDITOR
                timer.Stop();
                double nanoSeconds = 1000000000.0 * timer.ElapsedTicks / Stopwatch.Frequency;
                double milliSeconds = nanoSeconds / 1000000.0;
                frameTime = milliSeconds;
#endif

            }
            
        }

        /// <summary>
        /// When running Stop method,
        /// Anchor will force replace the scene back to the original position
        /// </summary>
        private void Stop() {
            Vector3 offset = WorldOrigin;

#if UNITY_EDITOR
            timer.Restart();
#endif

            Profiler.BeginSample("Anchor stop", this);
            
            MoveRootGameObjects(offset);
            MoveTrailRenderers(offset);
            MoveLineRenderers(offset);
            MoveParticles(offset);
            OffsetEvent(offset);

            Profiler.EndSample();

            offsetUnityEvent?.Invoke(offset);
            WorldOrigin = Vector3.zero;
            originUnityEvent?.Invoke(WorldOrigin);

#if UNITY_EDITOR
            timer.Stop();
            double nanoSeconds = 1000000000.0 * timer.ElapsedTicks / Stopwatch.Frequency;
            double milliSeconds = nanoSeconds / 1000000.0;
            frameTime = milliSeconds;
#endif

        }

        /// <summary>
        /// Call this method to offset all the root GameObjects
        /// </summary>
        /// <param name="offset">the Vector3 to offset</param>
        private void MoveRootGameObjects(Vector3 offset) {
            for (int i = 0; i < SceneManager.sceneCount; i++) {
                foreach (GameObject gameObject in SceneManager.GetSceneAt(i).GetRootGameObjects())
                    gameObject.transform.position -= offset;

            }
        }

        /// <summary>
        /// Call this method to offset all the TrailRenderers
        /// </summary>
        /// <param name="offset">the Vector3 to offset</param>
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

        /// <summary>
        /// Call this method to offset all the LineRenderers
        /// </summary>
        /// <param name="offset">the Vector3 to offset</param>
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

        /// <summary>
        /// Call this method to offset all the Particles
        /// </summary>
        /// <param name="offset">the Vector3 to offset</param>
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

                // TODO: When particle trail API is available, add the particle trail offset here
                // relative link: https://forum.unity.com/threads/is-it-possible-to-alter-particle-system-trail-parameters-from-a-trigger-collider.942292/

                if (wasPlaying)
                    particleSystem.Play();
            }
        }

    }
}
