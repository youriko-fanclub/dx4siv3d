#pragma once

#include <string>
#include <vector>
#include <Siv3D/String.hpp>
#include <Siv3D/Font.hpp>
#include "Singleton.hpp"

namespace dx {
namespace app {

class AssetManager final : public cmp::Singleton<AssetManager> {
public: // static_const/enum
    struct FontDesc {
    public:
        const s3d::String key;
        const unsigned size;
        const s3d::String typeface_string = U"";
        const s3d::Typeface typeface = s3d::Typeface::Regular;
    public:
        FontDesc(
            const s3d::String& key,
            unsigned size,
            const s3d::String& typeface) :
        key(key), size(size), typeface_string(typeface) {}
        FontDesc(
            const s3d::String& key,
            unsigned size,
            const s3d::Typeface& typeface) :
        key(key), size(size), typeface(typeface) {}
    };
    
    struct TextureDesc {
    public:
        const s3d::String key;
        const s3d::String path;
    public:
        TextureDesc(
            const s3d::String& key,
            const s3d::String& path) :
        key(key), path(path) {}
    };
public: // static
public: // public function
    void initialize(
            const std::vector<FontDesc>& font_descs,
            const std::vector<TextureDesc>& texture_descs);
    
private: // field
private: // private function
public: // ctor/dtor
};

}
}


