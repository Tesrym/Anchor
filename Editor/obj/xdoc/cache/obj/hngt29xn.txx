id: cs.temp.dll
language: CSharp
name:
  Default: cs.temp.dll
qualifiedName:
  Default: cs.temp.dll
type: Assembly
modifiers: {}
items:
- id: Tesrym.AnchorSystem
  commentId: N:Tesrym.AnchorSystem
  language: CSharp
  name:
    CSharp: Tesrym.AnchorSystem
    VB: Tesrym.AnchorSystem
  nameWithType:
    CSharp: Tesrym.AnchorSystem
    VB: Tesrym.AnchorSystem
  qualifiedName:
    CSharp: Tesrym.AnchorSystem
    VB: Tesrym.AnchorSystem
  type: Namespace
  assemblies:
  - cs.temp.dll
  modifiers: {}
  items:
  - id: Tesrym.AnchorSystem.Anchor
    commentId: T:Tesrym.AnchorSystem.Anchor
    language: CSharp
    name:
      CSharp: Anchor
      VB: Anchor
    nameWithType:
      CSharp: Anchor
      VB: Anchor
    qualifiedName:
      CSharp: Tesrym.AnchorSystem.Anchor
      VB: Tesrym.AnchorSystem.Anchor
    type: Class
    assemblies:
    - cs.temp.dll
    namespace: Tesrym.AnchorSystem
    source:
      id: Anchor
      path: ''
      startLine: 12
    syntax:
      content:
        CSharp: 'public class Anchor : MonoBehaviour'
        VB: >-
          Public Class Anchor

              Inherits MonoBehaviour
    inheritance:
    - System.Object
    modifiers:
      CSharp:
      - public
      - class
      VB:
      - Public
      - Class
    items:
    - id: Tesrym.AnchorSystem.Anchor.Instance
      commentId: P:Tesrym.AnchorSystem.Anchor.Instance
      language: CSharp
      name:
        CSharp: Instance
        VB: Instance
      nameWithType:
        CSharp: Anchor.Instance
        VB: Anchor.Instance
      qualifiedName:
        CSharp: Tesrym.AnchorSystem.Anchor.Instance
        VB: Tesrym.AnchorSystem.Anchor.Instance
      type: Property
      assemblies:
      - cs.temp.dll
      namespace: Tesrym.AnchorSystem
      source:
        id: Instance
        path: ''
        startLine: 18
      summary: "\nAnchor singleton\n"
      example: []
      syntax:
        content:
          CSharp: public static Anchor Instance { get; }
          VB: Public Shared ReadOnly Property Instance As Anchor
        parameters: []
        return:
          type: Tesrym.AnchorSystem.Anchor
      overload: Tesrym.AnchorSystem.Anchor.Instance*
      modifiers:
        CSharp:
        - public
        - static
        - get
        VB:
        - Public
        - Shared
        - ReadOnly
    - id: Tesrym.AnchorSystem.Anchor.Radius
      commentId: P:Tesrym.AnchorSystem.Anchor.Radius
      language: CSharp
      name:
        CSharp: Radius
        VB: Radius
      nameWithType:
        CSharp: Anchor.Radius
        VB: Anchor.Radius
      qualifiedName:
        CSharp: Tesrym.AnchorSystem.Anchor.Radius
        VB: Tesrym.AnchorSystem.Anchor.Radius
      type: Property
      assemblies:
      - cs.temp.dll
      namespace: Tesrym.AnchorSystem
      source:
        id: Radius
        path: ''
        startLine: 33
      syntax:
        content:
          CSharp: public static float Radius { get; set; }
          VB: Public Shared Property Radius As Single
        parameters: []
        return:
          type: System.Single
      overload: Tesrym.AnchorSystem.Anchor.Radius*
      modifiers:
        CSharp:
        - public
        - static
        - get
        - set
        VB:
        - Public
        - Shared
    - id: Tesrym.AnchorSystem.Anchor.WorldOrigin
      commentId: P:Tesrym.AnchorSystem.Anchor.WorldOrigin
      language: CSharp
      name:
        CSharp: WorldOrigin
        VB: WorldOrigin
      nameWithType:
        CSharp: Anchor.WorldOrigin
        VB: Anchor.WorldOrigin
      qualifiedName:
        CSharp: Tesrym.AnchorSystem.Anchor.WorldOrigin
        VB: Tesrym.AnchorSystem.Anchor.WorldOrigin
      type: Property
      assemblies:
      - cs.temp.dll
      namespace: Tesrym.AnchorSystem
      source:
        id: WorldOrigin
        path: ''
        startLine: 57
      syntax:
        content:
          CSharp: public static Vector3 WorldOrigin { get; set; }
          VB: Public Shared Property WorldOrigin As Vector3
        parameters: []
        return:
          type: Vector3
      overload: Tesrym.AnchorSystem.Anchor.WorldOrigin*
      modifiers:
        CSharp:
        - public
        - static
        - get
        - set
        VB:
        - Public
        - Shared
    - id: Tesrym.AnchorSystem.Anchor.offsetUnityEvent
      commentId: F:Tesrym.AnchorSystem.Anchor.offsetUnityEvent
      language: CSharp
      name:
        CSharp: offsetUnityEvent
        VB: offsetUnityEvent
      nameWithType:
        CSharp: Anchor.offsetUnityEvent
        VB: Anchor.offsetUnityEvent
      qualifiedName:
        CSharp: Tesrym.AnchorSystem.Anchor.offsetUnityEvent
        VB: Tesrym.AnchorSystem.Anchor.offsetUnityEvent
      type: Field
      assemblies:
      - cs.temp.dll
      namespace: Tesrym.AnchorSystem
      source:
        id: offsetUnityEvent
        path: ''
        startLine: 81
      summary: "\nCall the event when offsetting the scene, pass in the offset Vector\n"
      example: []
      syntax:
        content:
          CSharp: public UnityEvent<Vector3> offsetUnityEvent
          VB: Public offsetUnityEvent As UnityEvent(Of Vector3)
        return:
          type: UnityEvent{Vector3}
      modifiers:
        CSharp:
        - public
        VB:
        - Public
    - id: Tesrym.AnchorSystem.Anchor.originUnityEvent
      commentId: F:Tesrym.AnchorSystem.Anchor.originUnityEvent
      language: CSharp
      name:
        CSharp: originUnityEvent
        VB: originUnityEvent
      nameWithType:
        CSharp: Anchor.originUnityEvent
        VB: Anchor.originUnityEvent
      qualifiedName:
        CSharp: Tesrym.AnchorSystem.Anchor.originUnityEvent
        VB: Tesrym.AnchorSystem.Anchor.originUnityEvent
      type: Field
      assemblies:
      - cs.temp.dll
      namespace: Tesrym.AnchorSystem
      source:
        id: originUnityEvent
        path: ''
        startLine: 85
      summary: "\nCall the event when offsetting the scene, pass in the new world origin Vector\n"
      example: []
      syntax:
        content:
          CSharp: public UnityEvent<Vector3> originUnityEvent
          VB: Public originUnityEvent As UnityEvent(Of Vector3)
        return:
          type: UnityEvent{Vector3}
      modifiers:
        CSharp:
        - public
        VB:
        - Public
    - id: Tesrym.AnchorSystem.Anchor.OffsetEvent
      commentId: E:Tesrym.AnchorSystem.Anchor.OffsetEvent
      language: CSharp
      name:
        CSharp: OffsetEvent
        VB: OffsetEvent
      nameWithType:
        CSharp: Anchor.OffsetEvent
        VB: Anchor.OffsetEvent
      qualifiedName:
        CSharp: Tesrym.AnchorSystem.Anchor.OffsetEvent
        VB: Tesrym.AnchorSystem.Anchor.OffsetEvent
      type: Event
      assemblies:
      - cs.temp.dll
      namespace: Tesrym.AnchorSystem
      source:
        id: OffsetEvent
        path: ''
        startLine: 89
      syntax:
        content:
          CSharp: public static event Action<Vector3> OffsetEvent
          VB: Public Shared Event OffsetEvent As Action(Of Vector3)
        return:
          type: Action{Vector3}
      modifiers:
        CSharp:
        - public
        - static
        VB:
        - Public
        - Shared
  - id: Tesrym.AnchorSystem.AnchorExtensions
    commentId: T:Tesrym.AnchorSystem.AnchorExtensions
    language: CSharp
    name:
      CSharp: AnchorExtensions
      VB: AnchorExtensions
    nameWithType:
      CSharp: AnchorExtensions
      VB: AnchorExtensions
    qualifiedName:
      CSharp: Tesrym.AnchorSystem.AnchorExtensions
      VB: Tesrym.AnchorSystem.AnchorExtensions
    type: Class
    assemblies:
    - cs.temp.dll
    namespace: Tesrym.AnchorSystem
    source:
      id: AnchorExtensions
      path: ''
      startLine: 326
    syntax:
      content:
        CSharp: public static class AnchorExtensions
        VB: Public Module AnchorExtensions
    inheritance:
    - System.Object
    inheritedMembers:
    - System.Object.Equals(System.Object)
    - System.Object.Equals(System.Object,System.Object)
    - System.Object.GetHashCode
    - System.Object.GetType
    - System.Object.MemberwiseClone
    - System.Object.ToString
    - System.Object.ReferenceEquals(System.Object,System.Object)
    modifiers:
      CSharp:
      - public
      - static
      - class
      VB:
      - Public
      - Module
    items:
    - isExtensionMethod: true
      id: Tesrym.AnchorSystem.AnchorExtensions.ToOriginalSpace(Vector3)
      commentId: M:Tesrym.AnchorSystem.AnchorExtensions.ToOriginalSpace(Vector3)
      language: CSharp
      name:
        CSharp: ToOriginalSpace(Vector3)
        VB: ToOriginalSpace(Vector3)
      nameWithType:
        CSharp: AnchorExtensions.ToOriginalSpace(Vector3)
        VB: AnchorExtensions.ToOriginalSpace(Vector3)
      qualifiedName:
        CSharp: Tesrym.AnchorSystem.AnchorExtensions.ToOriginalSpace(Vector3)
        VB: Tesrym.AnchorSystem.AnchorExtensions.ToOriginalSpace(Vector3)
      type: Method
      assemblies:
      - cs.temp.dll
      namespace: Tesrym.AnchorSystem
      source:
        id: ToOriginalSpace
        path: ''
        startLine: 328
      syntax:
        content:
          CSharp: public static Vector3 ToOriginalSpace(this Vector3 value)
          VB: >-
            <ExtensionAttribute>

            Public Shared Function ToOriginalSpace(value As Vector3) As Vector3
        parameters:
        - id: value
          type: Vector3
        return:
          type: Vector3
      overload: Tesrym.AnchorSystem.AnchorExtensions.ToOriginalSpace*
      modifiers:
        CSharp:
        - public
        - static
        VB:
        - Public
        - Shared
  - id: Tesrym.AnchorSystem.OriginEditor
    commentId: T:Tesrym.AnchorSystem.OriginEditor
    language: CSharp
    name:
      CSharp: OriginEditor
      VB: OriginEditor
    nameWithType:
      CSharp: OriginEditor
      VB: OriginEditor
    qualifiedName:
      CSharp: Tesrym.AnchorSystem.OriginEditor
      VB: Tesrym.AnchorSystem.OriginEditor
    type: Class
    assemblies:
    - cs.temp.dll
    namespace: Tesrym.AnchorSystem
    source:
      id: OriginEditor
      path: ''
      startLine: 339
    syntax:
      content:
        CSharp: 'public class OriginEditor : Editor'
        VB: >-
          Public Class OriginEditor

              Inherits Editor
    inheritance:
    - System.Object
    modifiers:
      CSharp:
      - public
      - class
      VB:
      - Public
      - Class
    items:
    - id: Tesrym.AnchorSystem.OriginEditor.IsSceneWindowVisible
      commentId: P:Tesrym.AnchorSystem.OriginEditor.IsSceneWindowVisible
      language: CSharp
      name:
        CSharp: IsSceneWindowVisible
        VB: IsSceneWindowVisible
      nameWithType:
        CSharp: OriginEditor.IsSceneWindowVisible
        VB: OriginEditor.IsSceneWindowVisible
      qualifiedName:
        CSharp: Tesrym.AnchorSystem.OriginEditor.IsSceneWindowVisible
        VB: Tesrym.AnchorSystem.OriginEditor.IsSceneWindowVisible
      type: Property
      assemblies:
      - cs.temp.dll
      namespace: Tesrym.AnchorSystem
      source:
        id: IsSceneWindowVisible
        path: ''
        startLine: 358
      syntax:
        content:
          CSharp: public static bool IsSceneWindowVisible { get; }
          VB: Public Shared ReadOnly Property IsSceneWindowVisible As Boolean
        parameters: []
        return:
          type: System.Boolean
      overload: Tesrym.AnchorSystem.OriginEditor.IsSceneWindowVisible*
      modifiers:
        CSharp:
        - public
        - static
        - get
        VB:
        - Public
        - Shared
        - ReadOnly
    - id: Tesrym.AnchorSystem.OriginEditor.OnEnterPlaymodeInEditor
      commentId: M:Tesrym.AnchorSystem.OriginEditor.OnEnterPlaymodeInEditor
      language: CSharp
      name:
        CSharp: OnEnterPlaymodeInEditor()
        VB: OnEnterPlaymodeInEditor()
      nameWithType:
        CSharp: OriginEditor.OnEnterPlaymodeInEditor()
        VB: OriginEditor.OnEnterPlaymodeInEditor()
      qualifiedName:
        CSharp: Tesrym.AnchorSystem.OriginEditor.OnEnterPlaymodeInEditor()
        VB: Tesrym.AnchorSystem.OriginEditor.OnEnterPlaymodeInEditor()
      type: Method
      assemblies:
      - cs.temp.dll
      namespace: Tesrym.AnchorSystem
      source:
        id: OnEnterPlaymodeInEditor
        path: ''
        startLine: 387
      syntax:
        content:
          CSharp: public static void OnEnterPlaymodeInEditor()
          VB: Public Shared Sub OnEnterPlaymodeInEditor
      overload: Tesrym.AnchorSystem.OriginEditor.OnEnterPlaymodeInEditor*
      modifiers:
        CSharp:
        - public
        - static
        VB:
        - Public
        - Shared
    - id: Tesrym.AnchorSystem.OriginEditor.Update
      commentId: M:Tesrym.AnchorSystem.OriginEditor.Update
      language: CSharp
      name:
        CSharp: Update()
        VB: Update()
      nameWithType:
        CSharp: OriginEditor.Update()
        VB: OriginEditor.Update()
      qualifiedName:
        CSharp: Tesrym.AnchorSystem.OriginEditor.Update()
        VB: Tesrym.AnchorSystem.OriginEditor.Update()
      type: Method
      assemblies:
      - cs.temp.dll
      namespace: Tesrym.AnchorSystem
      source:
        id: Update
        path: ''
        startLine: 397
      syntax:
        content:
          CSharp: public static void Update()
          VB: Public Shared Sub Update
      overload: Tesrym.AnchorSystem.OriginEditor.Update*
      modifiers:
        CSharp:
        - public
        - static
        VB:
        - Public
        - Shared
    - id: Tesrym.AnchorSystem.OriginEditor.OnInspectorGUI
      commentId: M:Tesrym.AnchorSystem.OriginEditor.OnInspectorGUI
      language: CSharp
      name:
        CSharp: OnInspectorGUI()
        VB: OnInspectorGUI()
      nameWithType:
        CSharp: OriginEditor.OnInspectorGUI()
        VB: OriginEditor.OnInspectorGUI()
      qualifiedName:
        CSharp: Tesrym.AnchorSystem.OriginEditor.OnInspectorGUI()
        VB: Tesrym.AnchorSystem.OriginEditor.OnInspectorGUI()
      type: Method
      assemblies:
      - cs.temp.dll
      namespace: Tesrym.AnchorSystem
      source:
        id: OnInspectorGUI
        path: ''
        startLine: 409
      syntax:
        content:
          CSharp: public override void OnInspectorGUI()
          VB: Public Overrides Sub OnInspectorGUI
      overload: Tesrym.AnchorSystem.OriginEditor.OnInspectorGUI*
      modifiers:
        CSharp:
        - public
        - override
        VB:
        - Public
        - Overrides
references:
  Tesrym.AnchorSystem:
    name:
      CSharp:
      - name: Tesrym.AnchorSystem
        nameWithType: Tesrym.AnchorSystem
        qualifiedName: Tesrym.AnchorSystem
      VB:
      - name: Tesrym.AnchorSystem
        nameWithType: Tesrym.AnchorSystem
        qualifiedName: Tesrym.AnchorSystem
    isDefinition: true
    commentId: N:Tesrym.AnchorSystem
  Tesrym.AnchorSystem.Anchor:
    name:
      CSharp:
      - id: Tesrym.AnchorSystem.Anchor
        name: Anchor
        nameWithType: Anchor
        qualifiedName: Tesrym.AnchorSystem.Anchor
      VB:
      - id: Tesrym.AnchorSystem.Anchor
        name: Anchor
        nameWithType: Anchor
        qualifiedName: Tesrym.AnchorSystem.Anchor
    isDefinition: true
    parent: Tesrym.AnchorSystem
    commentId: T:Tesrym.AnchorSystem.Anchor
  Tesrym.AnchorSystem.Anchor.Instance*:
    name:
      CSharp:
      - id: Tesrym.AnchorSystem.Anchor.Instance*
        name: Instance
        nameWithType: Anchor.Instance
        qualifiedName: Tesrym.AnchorSystem.Anchor.Instance
      VB:
      - id: Tesrym.AnchorSystem.Anchor.Instance*
        name: Instance
        nameWithType: Anchor.Instance
        qualifiedName: Tesrym.AnchorSystem.Anchor.Instance
    isDefinition: true
    commentId: Overload:Tesrym.AnchorSystem.Anchor.Instance
  System:
    name:
      CSharp:
      - name: System
        nameWithType: System
        qualifiedName: System
        isExternal: true
      VB:
      - name: System
        nameWithType: System
        qualifiedName: System
    isDefinition: true
    commentId: N:System
  System.Single:
    name:
      CSharp:
      - id: System.Single
        name: Single
        nameWithType: Single
        qualifiedName: System.Single
        isExternal: true
      VB:
      - id: System.Single
        name: Single
        nameWithType: Single
        qualifiedName: System.Single
        isExternal: true
    isDefinition: true
    parent: System
    commentId: T:System.Single
  Tesrym.AnchorSystem.Anchor.Radius*:
    name:
      CSharp:
      - id: Tesrym.AnchorSystem.Anchor.Radius*
        name: Radius
        nameWithType: Anchor.Radius
        qualifiedName: Tesrym.AnchorSystem.Anchor.Radius
      VB:
      - id: Tesrym.AnchorSystem.Anchor.Radius*
        name: Radius
        nameWithType: Anchor.Radius
        qualifiedName: Tesrym.AnchorSystem.Anchor.Radius
    isDefinition: true
    commentId: Overload:Tesrym.AnchorSystem.Anchor.Radius
  Vector3:
    name:
      CSharp:
      - id: Vector3
        name: Vector3
        nameWithType: Vector3
        qualifiedName: Vector3
        isExternal: true
      VB:
      - id: Vector3
        name: Vector3
        nameWithType: Vector3
        qualifiedName: Vector3
        isExternal: true
    isDefinition: true
  Tesrym.AnchorSystem.Anchor.WorldOrigin*:
    name:
      CSharp:
      - id: Tesrym.AnchorSystem.Anchor.WorldOrigin*
        name: WorldOrigin
        nameWithType: Anchor.WorldOrigin
        qualifiedName: Tesrym.AnchorSystem.Anchor.WorldOrigin
      VB:
      - id: Tesrym.AnchorSystem.Anchor.WorldOrigin*
        name: WorldOrigin
        nameWithType: Anchor.WorldOrigin
        qualifiedName: Tesrym.AnchorSystem.Anchor.WorldOrigin
    isDefinition: true
    commentId: Overload:Tesrym.AnchorSystem.Anchor.WorldOrigin
  UnityEvent`1:
    name:
      CSharp:
      - id: UnityEvent`1
        name: UnityEvent
        nameWithType: UnityEvent
        qualifiedName: UnityEvent
        isExternal: true
      - name: <
        nameWithType: <
        qualifiedName: <
      - name: ''
        nameWithType: ''
        qualifiedName: ''
      - name: '>'
        nameWithType: '>'
        qualifiedName: '>'
      VB:
      - id: UnityEvent`1
        name: UnityEvent
        nameWithType: UnityEvent
        qualifiedName: UnityEvent
        isExternal: true
      - name: '(Of '
        nameWithType: '(Of '
        qualifiedName: '(Of '
      - name: ''
        nameWithType: ''
        qualifiedName: ''
      - name: )
        nameWithType: )
        qualifiedName: )
    isDefinition: true
  UnityEvent{Vector3}:
    name:
      CSharp:
      - id: UnityEvent`1
        name: UnityEvent
        nameWithType: UnityEvent
        qualifiedName: UnityEvent
        isExternal: true
      - name: <
        nameWithType: <
        qualifiedName: <
      - id: Vector3
        name: Vector3
        nameWithType: Vector3
        qualifiedName: Vector3
        isExternal: true
      - name: '>'
        nameWithType: '>'
        qualifiedName: '>'
      VB:
      - id: UnityEvent`1
        name: UnityEvent
        nameWithType: UnityEvent
        qualifiedName: UnityEvent
        isExternal: true
      - name: '(Of '
        nameWithType: '(Of '
        qualifiedName: '(Of '
      - id: Vector3
        name: Vector3
        nameWithType: Vector3
        qualifiedName: Vector3
        isExternal: true
      - name: )
        nameWithType: )
        qualifiedName: )
    isDefinition: false
    definition: UnityEvent`1
    commentId: '!:UnityEvent{Vector3}'
  Action`1:
    name:
      CSharp:
      - id: Action`1
        name: Action
        nameWithType: Action
        qualifiedName: Action
        isExternal: true
      - name: <
        nameWithType: <
        qualifiedName: <
      - name: ''
        nameWithType: ''
        qualifiedName: ''
      - name: '>'
        nameWithType: '>'
        qualifiedName: '>'
      VB:
      - id: Action`1
        name: Action
        nameWithType: Action
        qualifiedName: Action
        isExternal: true
      - name: '(Of '
        nameWithType: '(Of '
        qualifiedName: '(Of '
      - name: ''
        nameWithType: ''
        qualifiedName: ''
      - name: )
        nameWithType: )
        qualifiedName: )
    isDefinition: true
    commentId: '!:Action`1'
  Action{Vector3}:
    name:
      CSharp:
      - id: Action`1
        name: Action
        nameWithType: Action
        qualifiedName: Action
        isExternal: true
      - name: <
        nameWithType: <
        qualifiedName: <
      - id: Vector3
        name: Vector3
        nameWithType: Vector3
        qualifiedName: Vector3
        isExternal: true
      - name: '>'
        nameWithType: '>'
        qualifiedName: '>'
      VB:
      - id: Action`1
        name: Action
        nameWithType: Action
        qualifiedName: Action
        isExternal: true
      - name: '(Of '
        nameWithType: '(Of '
        qualifiedName: '(Of '
      - id: Vector3
        name: Vector3
        nameWithType: Vector3
        qualifiedName: Vector3
        isExternal: true
      - name: )
        nameWithType: )
        qualifiedName: )
    isDefinition: false
    definition: Action`1
    commentId: '!:Action{Vector3}'
  System.Object:
    name:
      CSharp:
      - id: System.Object
        name: Object
        nameWithType: Object
        qualifiedName: System.Object
        isExternal: true
      VB:
      - id: System.Object
        name: Object
        nameWithType: Object
        qualifiedName: System.Object
        isExternal: true
    isDefinition: true
    parent: System
    commentId: T:System.Object
  System.Object.Equals(System.Object):
    name:
      CSharp:
      - id: System.Object.Equals(System.Object)
        name: Equals
        nameWithType: Object.Equals
        qualifiedName: System.Object.Equals
        isExternal: true
      - name: (
        nameWithType: (
        qualifiedName: (
      - id: System.Object
        name: Object
        nameWithType: Object
        qualifiedName: System.Object
        isExternal: true
      - name: )
        nameWithType: )
        qualifiedName: )
      VB:
      - id: System.Object.Equals(System.Object)
        name: Equals
        nameWithType: Object.Equals
        qualifiedName: System.Object.Equals
        isExternal: true
      - name: (
        nameWithType: (
        qualifiedName: (
      - id: System.Object
        name: Object
        nameWithType: Object
        qualifiedName: System.Object
        isExternal: true
      - name: )
        nameWithType: )
        qualifiedName: )
    isDefinition: true
    parent: System.Object
    commentId: M:System.Object.Equals(System.Object)
  System.Object.Equals(System.Object,System.Object):
    name:
      CSharp:
      - id: System.Object.Equals(System.Object,System.Object)
        name: Equals
        nameWithType: Object.Equals
        qualifiedName: System.Object.Equals
        isExternal: true
      - name: (
        nameWithType: (
        qualifiedName: (
      - id: System.Object
        name: Object
        nameWithType: Object
        qualifiedName: System.Object
        isExternal: true
      - name: ', '
        nameWithType: ', '
        qualifiedName: ', '
      - id: System.Object
        name: Object
        nameWithType: Object
        qualifiedName: System.Object
        isExternal: true
      - name: )
        nameWithType: )
        qualifiedName: )
      VB:
      - id: System.Object.Equals(System.Object,System.Object)
        name: Equals
        nameWithType: Object.Equals
        qualifiedName: System.Object.Equals
        isExternal: true
      - name: (
        nameWithType: (
        qualifiedName: (
      - id: System.Object
        name: Object
        nameWithType: Object
        qualifiedName: System.Object
        isExternal: true
      - name: ', '
        nameWithType: ', '
        qualifiedName: ', '
      - id: System.Object
        name: Object
        nameWithType: Object
        qualifiedName: System.Object
        isExternal: true
      - name: )
        nameWithType: )
        qualifiedName: )
    isDefinition: true
    parent: System.Object
    commentId: M:System.Object.Equals(System.Object,System.Object)
  System.Object.GetHashCode:
    name:
      CSharp:
      - id: System.Object.GetHashCode
        name: GetHashCode
        nameWithType: Object.GetHashCode
        qualifiedName: System.Object.GetHashCode
        isExternal: true
      - name: (
        nameWithType: (
        qualifiedName: (
      - name: )
        nameWithType: )
        qualifiedName: )
      VB:
      - id: System.Object.GetHashCode
        name: GetHashCode
        nameWithType: Object.GetHashCode
        qualifiedName: System.Object.GetHashCode
        isExternal: true
      - name: (
        nameWithType: (
        qualifiedName: (
      - name: )
        nameWithType: )
        qualifiedName: )
    isDefinition: true
    parent: System.Object
    commentId: M:System.Object.GetHashCode
  System.Object.GetType:
    name:
      CSharp:
      - id: System.Object.GetType
        name: GetType
        nameWithType: Object.GetType
        qualifiedName: System.Object.GetType
        isExternal: true
      - name: (
        nameWithType: (
        qualifiedName: (
      - name: )
        nameWithType: )
        qualifiedName: )
      VB:
      - id: System.Object.GetType
        name: GetType
        nameWithType: Object.GetType
        qualifiedName: System.Object.GetType
        isExternal: true
      - name: (
        nameWithType: (
        qualifiedName: (
      - name: )
        nameWithType: )
        qualifiedName: )
    isDefinition: true
    parent: System.Object
    commentId: M:System.Object.GetType
  System.Object.MemberwiseClone:
    name:
      CSharp:
      - id: System.Object.MemberwiseClone
        name: MemberwiseClone
        nameWithType: Object.MemberwiseClone
        qualifiedName: System.Object.MemberwiseClone
        isExternal: true
      - name: (
        nameWithType: (
        qualifiedName: (
      - name: )
        nameWithType: )
        qualifiedName: )
      VB:
      - id: System.Object.MemberwiseClone
        name: MemberwiseClone
        nameWithType: Object.MemberwiseClone
        qualifiedName: System.Object.MemberwiseClone
        isExternal: true
      - name: (
        nameWithType: (
        qualifiedName: (
      - name: )
        nameWithType: )
        qualifiedName: )
    isDefinition: true
    parent: System.Object
    commentId: M:System.Object.MemberwiseClone
  System.Object.ToString:
    name:
      CSharp:
      - id: System.Object.ToString
        name: ToString
        nameWithType: Object.ToString
        qualifiedName: System.Object.ToString
        isExternal: true
      - name: (
        nameWithType: (
        qualifiedName: (
      - name: )
        nameWithType: )
        qualifiedName: )
      VB:
      - id: System.Object.ToString
        name: ToString
        nameWithType: Object.ToString
        qualifiedName: System.Object.ToString
        isExternal: true
      - name: (
        nameWithType: (
        qualifiedName: (
      - name: )
        nameWithType: )
        qualifiedName: )
    isDefinition: true
    parent: System.Object
    commentId: M:System.Object.ToString
  System.Object.ReferenceEquals(System.Object,System.Object):
    name:
      CSharp:
      - id: System.Object.ReferenceEquals(System.Object,System.Object)
        name: ReferenceEquals
        nameWithType: Object.ReferenceEquals
        qualifiedName: System.Object.ReferenceEquals
        isExternal: true
      - name: (
        nameWithType: (
        qualifiedName: (
      - id: System.Object
        name: Object
        nameWithType: Object
        qualifiedName: System.Object
        isExternal: true
      - name: ', '
        nameWithType: ', '
        qualifiedName: ', '
      - id: System.Object
        name: Object
        nameWithType: Object
        qualifiedName: System.Object
        isExternal: true
      - name: )
        nameWithType: )
        qualifiedName: )
      VB:
      - id: System.Object.ReferenceEquals(System.Object,System.Object)
        name: ReferenceEquals
        nameWithType: Object.ReferenceEquals
        qualifiedName: System.Object.ReferenceEquals
        isExternal: true
      - name: (
        nameWithType: (
        qualifiedName: (
      - id: System.Object
        name: Object
        nameWithType: Object
        qualifiedName: System.Object
        isExternal: true
      - name: ', '
        nameWithType: ', '
        qualifiedName: ', '
      - id: System.Object
        name: Object
        nameWithType: Object
        qualifiedName: System.Object
        isExternal: true
      - name: )
        nameWithType: )
        qualifiedName: )
    isDefinition: true
    parent: System.Object
    commentId: M:System.Object.ReferenceEquals(System.Object,System.Object)
  Tesrym.AnchorSystem.AnchorExtensions.ToOriginalSpace*:
    name:
      CSharp:
      - id: Tesrym.AnchorSystem.AnchorExtensions.ToOriginalSpace*
        name: ToOriginalSpace
        nameWithType: AnchorExtensions.ToOriginalSpace
        qualifiedName: Tesrym.AnchorSystem.AnchorExtensions.ToOriginalSpace
      VB:
      - id: Tesrym.AnchorSystem.AnchorExtensions.ToOriginalSpace*
        name: ToOriginalSpace
        nameWithType: AnchorExtensions.ToOriginalSpace
        qualifiedName: Tesrym.AnchorSystem.AnchorExtensions.ToOriginalSpace
    isDefinition: true
    commentId: Overload:Tesrym.AnchorSystem.AnchorExtensions.ToOriginalSpace
  Tesrym.AnchorSystem.AnchorExtensions:
    name:
      CSharp:
      - id: Tesrym.AnchorSystem.AnchorExtensions
        name: AnchorExtensions
        nameWithType: AnchorExtensions
        qualifiedName: Tesrym.AnchorSystem.AnchorExtensions
      VB:
      - id: Tesrym.AnchorSystem.AnchorExtensions
        name: AnchorExtensions
        nameWithType: AnchorExtensions
        qualifiedName: Tesrym.AnchorSystem.AnchorExtensions
    isDefinition: true
    commentId: T:Tesrym.AnchorSystem.AnchorExtensions
  System.Boolean:
    name:
      CSharp:
      - id: System.Boolean
        name: Boolean
        nameWithType: Boolean
        qualifiedName: System.Boolean
        isExternal: true
      VB:
      - id: System.Boolean
        name: Boolean
        nameWithType: Boolean
        qualifiedName: System.Boolean
        isExternal: true
    isDefinition: true
    parent: System
    commentId: T:System.Boolean
  Tesrym.AnchorSystem.OriginEditor.IsSceneWindowVisible*:
    name:
      CSharp:
      - id: Tesrym.AnchorSystem.OriginEditor.IsSceneWindowVisible*
        name: IsSceneWindowVisible
        nameWithType: OriginEditor.IsSceneWindowVisible
        qualifiedName: Tesrym.AnchorSystem.OriginEditor.IsSceneWindowVisible
      VB:
      - id: Tesrym.AnchorSystem.OriginEditor.IsSceneWindowVisible*
        name: IsSceneWindowVisible
        nameWithType: OriginEditor.IsSceneWindowVisible
        qualifiedName: Tesrym.AnchorSystem.OriginEditor.IsSceneWindowVisible
    isDefinition: true
    commentId: Overload:Tesrym.AnchorSystem.OriginEditor.IsSceneWindowVisible
  Tesrym.AnchorSystem.OriginEditor.OnEnterPlaymodeInEditor*:
    name:
      CSharp:
      - id: Tesrym.AnchorSystem.OriginEditor.OnEnterPlaymodeInEditor*
        name: OnEnterPlaymodeInEditor
        nameWithType: OriginEditor.OnEnterPlaymodeInEditor
        qualifiedName: Tesrym.AnchorSystem.OriginEditor.OnEnterPlaymodeInEditor
      VB:
      - id: Tesrym.AnchorSystem.OriginEditor.OnEnterPlaymodeInEditor*
        name: OnEnterPlaymodeInEditor
        nameWithType: OriginEditor.OnEnterPlaymodeInEditor
        qualifiedName: Tesrym.AnchorSystem.OriginEditor.OnEnterPlaymodeInEditor
    isDefinition: true
    commentId: Overload:Tesrym.AnchorSystem.OriginEditor.OnEnterPlaymodeInEditor
  Tesrym.AnchorSystem.OriginEditor.Update*:
    name:
      CSharp:
      - id: Tesrym.AnchorSystem.OriginEditor.Update*
        name: Update
        nameWithType: OriginEditor.Update
        qualifiedName: Tesrym.AnchorSystem.OriginEditor.Update
      VB:
      - id: Tesrym.AnchorSystem.OriginEditor.Update*
        name: Update
        nameWithType: OriginEditor.Update
        qualifiedName: Tesrym.AnchorSystem.OriginEditor.Update
    isDefinition: true
    commentId: Overload:Tesrym.AnchorSystem.OriginEditor.Update
  Tesrym.AnchorSystem.OriginEditor.OnInspectorGUI*:
    name:
      CSharp:
      - id: Tesrym.AnchorSystem.OriginEditor.OnInspectorGUI*
        name: OnInspectorGUI
        nameWithType: OriginEditor.OnInspectorGUI
        qualifiedName: Tesrym.AnchorSystem.OriginEditor.OnInspectorGUI
      VB:
      - id: Tesrym.AnchorSystem.OriginEditor.OnInspectorGUI*
        name: OnInspectorGUI
        nameWithType: OriginEditor.OnInspectorGUI
        qualifiedName: Tesrym.AnchorSystem.OriginEditor.OnInspectorGUI
    isDefinition: true
    commentId: Overload:Tesrym.AnchorSystem.OriginEditor.OnInspectorGUI
  Tesrym.AnchorSystem.OriginEditor:
    name:
      CSharp:
      - id: Tesrym.AnchorSystem.OriginEditor
        name: OriginEditor
        nameWithType: OriginEditor
        qualifiedName: Tesrym.AnchorSystem.OriginEditor
      VB:
      - id: Tesrym.AnchorSystem.OriginEditor
        name: OriginEditor
        nameWithType: OriginEditor
        qualifiedName: Tesrym.AnchorSystem.OriginEditor
    isDefinition: true
    commentId: T:Tesrym.AnchorSystem.OriginEditor
