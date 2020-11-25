#include "AssetManager.hpp"

#include <Siv3D/FontAsset.hpp>
#include <Siv3D/TextureAsset.hpp>
#include "FilePath.hpp"

namespace dx {
namespace app {


/* ---------- AssetManager ---------- */

// static ----------------------------------------
// public function -------------------------------
void AssetManager::initialize(
    const std::vector<FontDesc>& font_descs,
    const std::vector<TextureDesc>& texture_descs) {
    
    // 使用するフォントアセットを登録
    for (const auto& desc : font_descs) {
        if (!desc.typeface_string.empty()) {
            s3d::FontAsset::Register(desc.key, desc.size, FilePath::asset_font + desc.typeface_string);
        }
        else {
            s3d::FontAsset::Register(desc.key, desc.size, desc.typeface);
        }
    }
    
    for (const s3d::String textureExtension = U".png"; const auto& desc : texture_descs) {
        s3d::TextureAsset::Register(desc.key, FilePath::asset_texture + desc.path + textureExtension);
    }
}

// private function ------------------------------
// ctor/dtor -------------------------------------


}
}
