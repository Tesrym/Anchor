using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

namespace Tesrym.AnchorSystem {
    [CustomEditor(typeof(Anchor))]
    public class OriginEditor : Editor {

        Anchor anchor;

        private SerializedProperty threshold;
        private SerializedProperty offset;
        private SerializedProperty offsetEvent;

        private SerializedProperty showAnchor;
        private SerializedProperty showOrigin;
        private SerializedProperty timer;

        private static Vector3 offsetAccumulation = Vector3.zero;
        public static bool IsSceneWindowVisible => SceneView.lastActiveSceneView != null;
        private static bool WasVisible = true;
        private static bool SceneViewNeedsUpdate {
            get {
                if (!WasVisible && IsSceneWindowVisible)
                    return true;
                return false;
            }
        }

        private void OnEnable() {
            anchor = target as Anchor;

            threshold = serializedObject.FindProperty("radius");
            offset = serializedObject.FindProperty("_worldOrigin");
            offsetEvent = serializedObject.FindProperty("offsetEvent");

            showAnchor = serializedObject.FindProperty("showAnchor");
            showOrigin = serializedObject.FindProperty("showOrigin");
            timer = serializedObject.FindProperty("frameTime");

        }

        [InitializeOnEnterPlayMode]
        public static void OnEnterPlaymodeInEditor() {
            Anchor.OnOffsetEvent += MoveEditorCamera;
            EditorApplication.update += Update;

        }

        public static void Update() {
            if (SceneViewNeedsUpdate) {
                MoveEditorCamera(Vector3.zero);
            }
            WasVisible = IsSceneWindowVisible;

            if (!EditorApplication.isPlaying) {
                Anchor.OnOffsetEvent -= MoveEditorCamera;
                EditorApplication.update -= Update;
            }
        }

        public override void OnInspectorGUI() {
            serializedObject.UpdateIfRequiredOrScript();

            GUIStyle style = EditorStyles.helpBox;
            style.alignment = TextAnchor.MiddleCenter;
            style.richText = true;
            //style.fontSize = 16;

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

            float defaultLabelWidth = EditorGUIUtility.labelWidth;
            EditorGUIUtility.labelWidth = 50;
            float totalWidth = EditorGUIUtility.currentViewWidth;
            GUILayoutOption[] leftOptions = new GUILayoutOption[] {
                GUILayout.MaxWidth(totalWidth * .75f)
            };
            GUILayoutOption[] rightOptions = new GUILayoutOption[] {
                GUILayout.MaxWidth(totalWidth * .25f)
            };

            EditorGUILayout.BeginVertical();
            EditorGUILayout.BeginHorizontal();
            EditorGUI.BeginChangeCheck();
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

            EditorGUI.BeginChangeCheck();
            EditorGUILayout.PropertyField(offsetEvent);
            if (EditorGUI.EndChangeCheck()) {
                serializedObject.ApplyModifiedProperties();
            }

        }

        private static void MoveEditorCamera(Vector3 offset) {
            offsetAccumulation += offset;
            if (IsSceneWindowVisible) {
                SceneView.lastActiveSceneView.pivot -= offsetAccumulation;
                offsetAccumulation = Vector3.zero;
            }
        }

    }
}
