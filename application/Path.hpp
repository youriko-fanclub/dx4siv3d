#pragma once
#include <Siv3D/String.hpp>
#include <Siv3D/StringView.hpp>
#include <Siv3D/FileSystem.hpp>

namespace dx {
namespace app {

class Path {
public: // static_const/enum
    static const s3d::String delimiter;
    
    static const Path asset;
    static const Path asset_font;
    static const Path asset_texture;
    static const Path asset_audio;
    static const Path asset_toml;
    static const Path asset_schema;

public: // static
public: // public function
    operator s3d::FilePath() const { return m_path; }
    operator s3d::FilePathView() const { return m_path; }
    Path operator / (const Path& child) const { return Path(m_path + delimiter + child.m_path); }
    Path operator / (const s3d::String& child) const { return Path(m_path + delimiter + child); }
    
    s3d::FilePath full() const {
        return s3d::FileSystem::FullPath(*this);
    }
private: // field
    s3d::String m_path;
private: // private function
public: // ctor/dtor
    Path(const s3d::String& path) :
    m_path(path) {}
};

}
}
