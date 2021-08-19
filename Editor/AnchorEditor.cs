using UnityEngine;
using UnityEditor;

namespace Tesrym.AnchorSystem {
    [CustomEditor(typeof(Anchor))]
    public class OriginEditor : Editor {

        private Anchor anchor;

        private SerializedProperty replace;
        private SerializedProperty threshold;
        private SerializedProperty offset;

#if UNITY_2020_1_OR_NEWER
        private SerializedProperty offsetEvent;
        private SerializedProperty originEvent;
#endif

        private SerializedProperty showAnchor;
        private SerializedProperty showOrigin;
        private SerializedProperty timer;

        private static Vector3 offsetAccumulation = Vector3.zero;
        public static bool IsSceneWindowVisible => SceneView.lastActiveSceneView != null;
        private static bool WasVisible = true;
        //A simple "scene window was not active previous frame, but now it is".
        private static bool SceneViewNeedsUpdate {
            get {
                if (!WasVisible && IsSceneWindowVisible)
                    return true;
                return false;
            }
        }

        private void OnEnable() {
            anchor = target as Anchor;

            replace = serializedObject.FindProperty("_replaceSceneWhenDisable");
            threshold = serializedObject.FindProperty("_radius");
            offset = serializedObject.FindProperty("_worldOrigin");

#if UNITY_2020_1_OR_NEWER
            offsetEvent = serializedObject.FindProperty("offsetUnityEvent");
            originEvent = serializedObject.FindProperty("originUnityEvent");
#endif

            showAnchor = serializedObject.FindProperty("showAnchor");
            showOrigin = serializedObject.FindProperty("showOrigin");
            timer = serializedObject.FindProperty("frameTime");

        }

        [InitializeOnEnterPlayMode]
        public static void OnEnterPlaymodeInEditor() {
            Anchor.OffsetEvent += MoveEditorCamera;
            //Editor script needs its own update.
            //When scene window is inactive due to for example fullscreen game window, the editor script cannot move scene camera.
            //Instead we accumulate the offset and apply it immediately when scene window is visible again.
            EditorApplication.update += Update;

        }

        public static void Update() {
            if (SceneViewNeedsUpdate) {
                MoveEditorCamera(Vector3.zero);
            }
            WasVisible = IsSceneWindowVisible;

            if (!EditorApplication.isPlaying) {
                Anchor.OffsetEvent -= MoveEditorCamera;
                EditorApplication.update -= Update;
            }
        }

        public override void OnInspectorGUI() {
            serializedObject.UpdateIfRequiredOrScript();

            GUIStyle style = EditorStyles.helpBox;
            style.alignment = TextAnchor.MiddleCenter;

            if (Application.isPlaying) {
                GUILayout.BeginVertical(timer.doubleValue.ToString() + "ms.", style);
            } else {
                GUILayout.BeginVertical("Not running.", style);
            }
            EditorGUILayout.Space(EditorGUIUtility.singleLineHeight);
            GUILayout.EndVertical();

            if (!anchor.enabled) {
                EditorGUILayout.HelpBox("Anchor is disabled.", MessageType.Info);
                if (GUILayout.Button("Start")) {
                    anchor.enabled = true;
                }
                return;
            }

            float totalWidth = EditorGUIUtility.currentViewWidth;
            GUILayoutOption[] leftOptions = new GUILayoutOption[] {
                GUILayout.MaxWidth(totalWidth * .75f)
            };
            GUILayoutOption[] rightOptions = new GUILayoutOption[] {
                GUILayout.MaxWidth(totalWidth * .25f)
            };

            EditorGUILayout.BeginVertical();
            EditorGUI.BeginChangeCheck();
            EditorGUIUtility.labelWidth = totalWidth - 55;
            EditorGUILayout.PropertyField(replace);
            
            EditorGUIUtility.labelWidth = 50;
            EditorGUILayout.BeginHorizontal();
            threshold.floatValue = EditorGUILayout.FloatField("Radius", threshold.floatValue, leftOptions);
            showAnchor.boolValue = EditorGUILayout.Toggle("Show", showAnchor.boolValue, rightOptions);
            if (EditorGUI.EndChangeCheck()) {
                serializedObject.ApplyModifiedProperties();
            }
            EditorGUILayout.EndHorizontal();

            EditorGUILayout.BeginHorizontal();
            EditorGUI.BeginDisabledGroup(true);
            EditorGUILayout.LabelField("Origin", offset.vector3Value.ToString(), leftOptions);
            EditorGUI.EndDisabledGroup();
            EditorGUI.BeginChangeCheck();
            showOrigin.boolValue = EditorGUILayout.Toggle("Show", showOrigin.boolValue, rightOptions);
            if (EditorGUI.EndChangeCheck()) {
                serializedObject.ApplyModifiedProperties();
            }
            EditorGUILayout.EndHorizontal();
            EditorGUILayout.EndVertical();

#if UNITY_2020_1_OR_NEWER
            EditorGUI.BeginChangeCheck();
            EditorGUILayout.PropertyField(offsetEvent);
            EditorGUILayout.PropertyField(originEvent);
            if (EditorGUI.EndChangeCheck()) {
                serializedObject.ApplyModifiedProperties();
            }
#endif

        }

        private static void MoveEditorCamera(Vector3 offset) {
            offsetAccumulation += offset;
            if (IsSceneWindowVisible) {
                SceneView.lastActiveSceneView.pivot -= offsetAccumulation;
                offsetAccumulation = Vector3.zero;
            } //Else accumulate offset
        }

    }
}
