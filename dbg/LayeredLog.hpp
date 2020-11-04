#if false
using UnityEngine;
using System.Collections.Generic;
using static du.Ex.ExDictionary;
using UniRx;


namespace du.Test {

    /// <summary>
    /// グループ分けされたログ
    /// - グループごとに色付け、表示有無切り替え可能
    /// </summary>
    public interface ILogLayer {
        /// <summary> 普通のログ </summary>
        void Log         (object message);
        /// <summary> エラーログ </summary>
        void LogError    (object message);
        /// <summary> 警告ログ </summary>
        void LogAssertion(object message);
        /// <summary> 文字色指定の普通のログ </summary>
        void Log         (string colorTag, object message);
        /// <summary> 文字色赤の普通のログ </summary>
        void LogR        (object message);

        /// <summary> ログを出しつつ値をそのまま流す </summary>
        T TL<T>(T obj);
        /// <summary> ログを出しつつ値をそのまま流す </summary>
        T TL<T>(T obj, string foreword);
        /// <summary> ログを出しつつ値をそのまま流す </summary>
        T TL<T>(T obj, string foreword, string afterword);
    }

    /// <summary>
    /// グループ分けされたログ
    /// - アクティブフラグの切り替えインタフェース
    /// </summary>
    public interface IOperableLogLayer : ILogLayer {
        void SetActive(bool isActive);
    }

    /// <summary>
    /// グループ分けされたログ
    /// - グループごとに色付け、表示有無切り替え可能
    /// </summary>
    public class LogLayer : IOperableLogLayer {
        #region field
        /// <value> グループ名 </value>
        string Label { get; }
        /// <value> グループ名の表示色 </value>
        string ColorTag { get; }
        /// <summary> アクティブか </summary>
        bool m_isActive = true;
        #endregion

        #region ctor
        public LogLayer(string label, string colorTag, bool isActive = true) {
            Label = label;
            ColorTag = colorTag;
            m_isActive = isActive;
        }
        #endregion

        #region public
        public void SetActive(bool isActive) => m_isActive = isActive;
        public void Log         (object message) {
            if (m_isActive) { Debug.Log         ($"<b>[<color={ColorTag}>{Label}</color>]</b>::{message}"); }
        }
        public void LogError    (object message) {
            if (m_isActive) { Debug.LogError    ($"<b>[<color={ColorTag}>{Label}</color>]</b>::{message}"); }
        }
        public void LogAssertion(object message) {
            if (m_isActive) { Debug.LogAssertion($"<b>[<color={ColorTag}>{Label}</color>]</b>::{message}"); }
        }
        public void LogR        (object message) {
            if (m_isActive) { Log("red", message); }
        }
        public void Log(string colorTag, object message) {
            if (m_isActive) { Debug.Log ($"<b>[<color={ColorTag}>{Label}</color>]</b>::<color={colorTag}>{message}</color>"); }
        }

        public T TL<T>(T obj) {
            Log(obj);
            return obj;
        }
        public T TL<T>(T obj, string foreword) {
            Log(foreword + obj.ToString());
            return obj;
        }
        public T TL<T>(T obj, string foreword, string afterword) {
            Log(foreword + obj.ToString() + afterword);
            return obj;
        }
        #endregion
    }

    /// <summary>
    /// グループ分けされたログを統括管理
    /// </summary>
    public static class LayeredLog {
        #region static_field
        /// <summary> グループ分けされたログ群 </summary>
        static IDictionary<string, IOperableLogLayer> m_layers;
        #endregion

        #region public
        /// <summary> 規定のグループを一気に生成 </summary>
        public static void Initialize(bool isActiveDefault = true) {
            if (m_layers == null) {
                m_layers = new Dictionary<string, IOperableLogLayer>();
                Add("LLOG"     , "black" , isActiveDefault);

                Add("BOOT"     , "purple", isActiveDefault);
                Add("dUTIL"    , "brown" , isActiveDefault);
                Add("DEBUG"    , "red"   , isActiveDefault);
                Add("AUDIO"    , "orange", isActiveDefault);
                Add("MISC"     , "gray"  , isActiveDefault);
                Add("MAIN:BOOT", "green" , isActiveDefault);
                Add("MAIN:MEM" , "green" , isActiveDefault);
                Add("EXPM"     , "blue"  , isActiveDefault);
                LLog.Boot.Log("LayeredLog booted.");
            }
        }
        /// <summary> 各グループの表示有無を変更 </summary>
        public static void SetActive(string layerLabel, bool isActive) {
            m_layers.At(layerLabel)?.SetActive(isActive);
        }
        /// <summary> 全グループの表示有無を変更 </summary>
        public static void SetActiveAll(bool isActive) {
            foreach (var i in m_layers.Values) { i.SetActive(isActive); }
        }
        /// <summary> 特定のグループにアクセス </summary>
        public static ILogLayer At(string layerLabel) {
            if (m_layers.ContainsKey(layerLabel)) {
                return m_layers[layerLabel];
            }
            else {
                Debug.LogError($"Layer \"{layerLabel}\" doesn't exist.");
                return null;
            }
        }
        #endregion

        #region private
        /// <summary> ロググループを追加 </summary>
        private static void Add(string label, string colorTag, bool isActive = true) {
            if (m_layers.ContainsKey(label)) { SetActive(label, isActive); }
            else { m_layers.Add(label, new LogLayer(label, colorTag, isActive)); }
        }
        #endregion
    }

    public static class LLog {
        #region property
        private static ILogLayer Llog  => LayeredLog.At("LLOG" );

        public static ILogLayer Boot  => LayeredLog.At("BOOT" );
        public static ILogLayer dUtil => LayeredLog.At("dUTIL");
        public static ILogLayer Debug => LayeredLog.At("DEBUG");
        public static ILogLayer Audio => LayeredLog.At("AUDIO");
        public static ILogLayer Misc  => LayeredLog.At("MISC" );
        public static ILogLayer MBoot => LayeredLog.At("MAIN:BOOT");
        public static ILogLayer MIAct => LayeredLog.At("MAIN:IACT");
        public static ILogLayer MMem => LayeredLog.At("MAIN:MEM");
        public static ILogLayer Expm  => LayeredLog.At("EXPM");
        #endregion

        #region public
        public static void Separator() => Llog.Log("------------------------------");
        public static void Separator(string msg) => Llog.Log($"<{msg}>------------------------------");
        #endregion
    }

}

#endif
