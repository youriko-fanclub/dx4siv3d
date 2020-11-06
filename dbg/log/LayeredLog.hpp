#pragma once

namespace dx {
namespace dbg {

using ColorTag = s3d::String;

/// <summary>
/// グループ分けされたログ
/// - グループごとに色付け、表示有無切り替え可能
/// </summary>
class ILogLayer {
    virtual void log      (const s3d::String& message) = 0;
    virtual void logError (const s3d::String& message) = 0;
    virtual void logAssert(const s3d::String& message) = 0;

    /// <summary> ログを出しつつ値をそのまま流す </summary>
    template<typename T>
    virtual T tl<T>(T obj) = 0;
    /// <summary> ログを出しつつ値をそのまま流す </summary>
    template<typename T>
    virtual T tl<T>(T obj, const s3d::String& foreword) = 0;
    /// <summary> ログを出しつつ値をそのまま流す </summary>
    template<typename T>
    virtual T tl<T>(T obj, const s3d::String& foreword, string afterword) = 0;
    
    void setActive(bool isActive);
}

/// <summary>
/// グループ分けされたログ
/// - グループごとに色付け、表示有無切り替え可能
/// </summary>
class LogLayer final : public ILogLayer {
public: // static_const/enum
private: // static
    static void logImpl(const s3d::String& massage) {
        s3d::Print << message;
        std::cout << message << std::endl;
    }
    static s3d::String s_log_template;

public: // public function
    void initialize() {
        s_log_template = "<b>[<color={}>{}</color>]</b>::"_fmt(m_colorTag, m_name);
    }
    void setActive(const bool isActive) override {
        m_isActive = isActive;
    }
    void log         (const s3d::String& message) const {
        if (m_isActive) { logImpl(s_log_template + message); }
    }
    void logError    (const s3d::String& message) const {
        if (m_isActive) { logImpl(s_log_template + message); }
    }
    void logAssertion(const s3d::String& message) const {
        if (m_isActive) { logImpl(s_log_template + message); }
    }

    T tl<T>(T obj) {
        Log(obj);
        return obj;
    }
    T tl<T>(T obj, string foreword) {
        Log(foreword + obj.ToString());
        return obj;
    }
    T tl<T>(T obj, string foreword, string afterword) {
        Log(foreword + obj.ToString() + afterword);
        return obj;
    }
private: // private function
private: // field
    s3d::String m_name;
    ColorTag m_colorTag;
    bool m_isActive;
public: // ctor/dtor
    LogLayer(const s3d::String& name, const ColorTag& colorTag, bool isActive = true) {
        m_name = name;
        m_colorTag = colorTag;
        m_isActive = isActive;
    }
}

/// <summary>
/// グループ分けされたログを統括管理
/// </summary>
public static class LayeredLog {
    /// <summary> グループ分けされたログ群 </summary>
    static IDictionary<string, IOperableLogLayer> m_layers;

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
}
