#if false
using UnityEngine;


namespace du.Test {

    public static class Misc {
        public static void IsNull(object obj) => IsNull(obj, "This");
        public static void IsNull(object obj, string name) {
            if (obj is null) { Debug.LogError($"{name} is null."); }
            else { Debug.LogError($"{name} is not null."); }
        }
    }

    public static class Log {

        public static bool IsNull(object obj, string name) {
            if (obj == null) {
                Debug.Log(name + " is null!!");
                return true;
            }
            else {
                Debug.Log(name + " is not null.");
                return false;
            }
        }

        public static T TL<T>(this T obj, string layerLabel) {
            Debug.Log(obj);
            return obj;
        }
        public static T TL<T>(this T obj, string layerLabel, string foreword) {
            Debug.Log(foreword + obj.ToString());
            return obj;
        }
        public static T TL<T>(this T obj, string layerLabel, string foreword, string afterword) {
            Debug.Log(foreword + obj.ToString() + afterword);
            return obj;
        }

        public static T TLC<T>(this T obj, string layerLabel, string colorTag) {
            return obj.TL("<color=" + colorTag + ">", "</color>");
        }
        public static T TLC<T>(this T obj, string layerLabel, string colorTag, string foreword) {
            return obj.TL("<color=" + colorTag + ">" + foreword, "</color>");
        }
        public static T TLC<T>(this T obj, string layerLabel, string colorTag, string foreword, string afterword) {
            return obj.TL("<color=" + colorTag + ">" + foreword, afterword + "</color>");
        }

        public static T TLCRed<T>(this T obj, string layerLabel) {
            return obj.TL("<color=red>", "</color>");
        }
        public static T TLCRed<T>(this T obj, string layerLabel, string foreword) {
            return obj.TL("<color=red>" + foreword, "</color>");
        }
        public static T TLCRed<T>(this T obj, string layerLabel, string foreword, string afterword) {
            return obj.TL("<color=red>" + foreword, afterword + "</color>");
        }


    }

}

#endif
