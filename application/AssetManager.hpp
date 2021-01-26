#pragma once

#include <Siv3D/String.hpp>
#include <Siv3D/Font.hpp>
#include "Singleton.hpp"
#include "AudioType.hpp"

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

    struct AudioDesc {
    public:
        static s3d::Array<AudioDesc> loadFromToml();
    public:
        const aud::AudioType type;
        const s3d::String key;
        const s3d::String path;
        const bool is_loop;
    public:
        AudioDesc(
            aud::AudioType type,
            const s3d::String& key,
            const s3d::String& path,
            const bool is_loop = false) :
        type(type), key(key), path(path), is_loop(is_loop) {}
        AudioDesc(
            aud::AudioType type,
            const s3d::String& key_path,
            const bool is_loop = false) :
        type(type), key(key_path), path(key_path), is_loop(is_loop) {}
    };
public: // static
public: // public function
    void initialize(
        const s3d::Array<FontDesc>& font_descs,
        const s3d::Array<TextureDesc>& texture_descs,
        const s3d::Array<AudioDesc>& audio_descs);
    
private: // field
private: // private function
public: // ctor/dtor
};

}
}


