using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Tesrym.AnchorSystem {
    public static class AnchorExtensions {

        public static Vector3 ToOriginalSpace(this Vector3 value) {
            return value + Anchor.WorldOrigin;
        }

    }
}
