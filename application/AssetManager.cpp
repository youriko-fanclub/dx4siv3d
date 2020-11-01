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
  const std::vector<FontDesc>& fontDescs,
  const std::vector<TextureDesc>& textureDescs) {
  
  // 使用するフォントアセットを登録
  for (const auto& desc : fontDescs) {
    if (!desc.typefaceString.empty()) {
      s3d::FontAsset::Register(desc.key, desc.size, FilePath::asset_font + desc.typefaceString);
    }
    else {
      s3d::FontAsset::Register(desc.key, desc.size, desc.typeface);
    }
  }
  
  for (const s3d::String textureExtension = U".png";
      const auto& desc : textureDescs) {
    s3d::TextureAsset::Register(desc.key, FilePath::asset_texture + desc.path + textureExtension);
  }
}

// private function ------------------------------
// ctor/dtor -------------------------------------


}
}
