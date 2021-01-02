#pragma once
#include <Siv3D/DirectoryWatcher.hpp>
#include <Siv3D/TOMLReader.hpp>
#include "Path.hpp"

namespace dx {
namespace cmp {

// データ/ファイルの実体
class TomlAssetImpl {
public: // static_const/enum
public: // static
public: // getter
    const s3d::String& filename() const { return m_filename; }
    s3d::TOMLValue operator [](const s3d::String& path) const {
        return m_reader[path];
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

    [[nodiscard]] s3d::TOMLValue operator [](const s3d::String& path) const {
        return (*m_impl)[path];
    }
    // s3d::Vec2 getVec2(const s3d::String& key) const;
    // s3d::Size getSize(const s3d::String& key) const;
    // s3d::ColorF getColorF(const s3d::String& key) const;
    // s3d::Font getFont(const s3d::String& key) const;
    // std::shared_ptr<s3d::Font> getFontPtr(const s3d::String& key) const;
private: // field
    const std::shared_ptr<TomlAssetImpl> m_impl;
private: // private function
public: // ctor/dtor
    TomlAsset(const s3d::String& filename);
    virtual ~TomlAsset();
};


}
}
