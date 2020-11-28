#include "AssetManager.hpp"
#include <unordered_map>
#include <Siv3D/FontAsset.hpp>
#include <Siv3D/TextureAsset.hpp>
#include <Siv3D/AudioAsset.hpp>
#include "FilePath.hpp"

namespace dx {
namespace app {


/* ---------- AssetManager ---------- */

// static ----------------------------------------
// public function -------------------------------
void AssetManager::initialize(
    const std::vector<FontDesc>& font_descs,
    const std::vector<TextureDesc>& texture_descs,
    const std::vector<AudioDesc>& audio_descs) {
    
    // Font
    for (const auto& desc : font_descs) {
        if (!desc.typeface_string.empty()) {
            s3d::FontAsset::Register(desc.key, desc.size, FilePath::asset_font + desc.typeface_string);
        }
        else {
            s3d::FontAsset::Register(desc.key, desc.size, desc.typeface);
        }
    }
    
    // Texture
    for (const s3d::String extension = U".png"; const auto& desc : texture_descs) {
        s3d::TextureAsset::Register(desc.key, FilePath::asset_texture + desc.path + extension);
    }
    
    // Audio
    std::unordered_map<AudioDesc::Type, s3d::String> types{
        { AudioDesc::Type::BGM, U"BGM" },
        { AudioDesc::Type::SE, U"SE" },
    };
    for (const s3d::String extension = U".mp3"; const auto& desc : audio_descs) {
        const auto key = types.at(desc.type) + U"::" + desc.key;
        const auto path = FilePath::asset_audio + types.at(desc.type) + U"/" + desc.path + extension;
        s3d::AudioAsset::Register(
            types.at(desc.type) + U"::" + desc.key,
            FilePath::asset_audio + types.at(desc.type) + U"/" + desc.path + extension);
    }
}

// private function ------------------------------
// ctor/dtor -------------------------------------


}
}
