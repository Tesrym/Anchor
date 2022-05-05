using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Tesrym.AnchorSystem {
    public static class AnchorExtensions {

        /// <summary>
        /// Translate the current engine position to origin real world position
        /// </summary>
        /// <param name="value">the current position, often use transform.position</param>
        /// <returns>the real world position after translation</returns>
        public static Vector3 ToOriginalSpace(this Vector3 value) {
            return value + Anchor.WorldOrigin;
        }

    }
}
