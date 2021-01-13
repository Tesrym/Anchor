using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Tesrym.AnchorSystem {
    public static class AnchorExtensions {

        public static Vector3 OriginWorldPosition(this Transform transform) {
            return Anchor.WorldOrigin;
        }

        public static Vector3 OriginLocalPosition(this Transform transform) {
            return transform.position;
        }

        public static Vector3 ToOriginSpace(this Vector3 vector3) {
            return vector3 + Anchor.WorldOrigin;
        }

        public static Vector3 ToShitSpace(this Vector3 vector3) {
            return vector3 - Anchor.WorldOrigin;
        }

    }
}
