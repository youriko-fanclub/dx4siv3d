#pragma once
#include <Siv3D/DirectoryWatcher.hpp>
#include <Siv3D/TOMLReader.hpp>
#include <Siv3D/Vector2D.hpp>
#include <Siv3D/Font.hpp>
#include "Path.hpp"

namespace dx {
namespace toml {

class TomlKey {
public: // static_const/enum
    static const s3d::String delimiter;
public: // static
public: // public function
    TomlKey operator + (const TomlKey& child) const { return TomlKey(m_impl + delimiter + child.m_impl); }
    TomlKey operator + (const s3d::String& child) const { return TomlKey(m_impl + delimiter + child); }
    TomlKey& operator += (const TomlKey& child) {
        m_impl += delimiter + child.m_impl;
        return *this;
    }
    TomlKey& operator += (const s3d::String& child) {
        m_impl += delimiter + child;
        return *this;
    }
    
    s3d::String full() const { return m_impl; }
private: // field
    s3d::String m_impl;
private: // private function
public: // ctor/dtor
    TomlKey(const s3d::String& key) :
    m_impl(key) {}
};
#if false
    s3d::String full() const {
        auto key = m_keys.front();
        for (int i = 1; i < m_keys.size(); ++i) {
            key += delimiter + m_keys.at(1);
        }
        return key;
    }
private: // field
    std::vector<s3d::String> m_keys;
private: // private function
public: // ctor/dtor
    TomlKey(const s3d::String& key) :
        m_keys({ key }) {}
    TomlKey(const std::initializer_list<s3d::String>& keys) :
        m_keys(keys) {}
};
#endif


// データ/ファイルの実体
class TomlAssetImpl {
public: // static_const/enum
public: // static
public: // getter
    const s3d::String& filename() const { return m_filename; }
    s3d::TOMLValue operator [](const TomlKey& key) const {
        return m_reader[key.full()];
    }
public: // setter
    void load();
private: // field
    const s3d::String m_filename;
    app::Path m_path;
    s3d::DirectoryWatcher m_watcher;
    s3d::TOMLReader m_reader;
private: // private function
public: // ctor/dtor
    TomlAssetImpl(const s3d::String& filename, const app::Path& path);
    virtual ~TomlAssetImpl();
};


// TomlデータへのProxy
class TomlAsset {
public: // static_const/enum
public: // static
    static bool load(const s3d::String& name, const app::Path& path);
    static void unload(const s3d::String& name);
    [[nodiscard]] static bool is_loaded(const s3d::String& name);
public: // public function
    const s3d::String& filename() const { return m_impl->filename(); }

    [[nodiscard]] s3d::TOMLValue operator [](const TomlKey& key) const {
        return (*m_impl)[key];
    }
    
private: // field
    const TomlAssetImpl* const m_impl;
private: // private function
public: // ctor/dtor
    TomlAsset(const s3d::String& filename);
    virtual ~TomlAsset();
};


inline int getInt(const s3d::TOMLValue& toml) { return toml.get<int>(); }
inline float getFloat(const s3d::TOMLValue& toml) { return toml.get<float>(); }
inline double getDouble(const s3d::TOMLValue& toml) { return toml.get<double>(); }
s3d::Vec2 vec2(const s3d::TOMLValue& toml);
s3d::Size size(const s3d::TOMLValue& toml);
s3d::ColorF colorF(const s3d::TOMLValue& toml);
s3d::Font font(const s3d::TOMLValue& toml);

}
}
