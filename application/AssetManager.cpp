#include "AssetManager.hpp"

#include <Siv3D/FontAsset.hpp>
#include <Siv3D/TextureAsset.hpp>

namespace dx {
namespace app {


/* ---------- AssetManager ---------- */

// static ----------------------------------------
// public function -------------------------------
void AssetManager::initialize(
  const std::vector<FontDesc>& fontDescs,
  const std::vector<TextureDesc>& textureDescs) {
  
  const s3d::String assetPath = U"../asset/";
  
  // 使用するフォントアセットを登録
  for (const s3d::String fontPath = assetPath + U"font/";
    const auto& desc : fontDescs) {
    if (!desc.typefaceString.empty()) {
      s3d::FontAsset::Register(desc.key, desc.size, fontPath + desc.typefaceString);
    }
    else {
      s3d::FontAsset::Register(desc.key, desc.size, desc.typeface);
    }
  }
  
  const s3d::String texturePath = assetPath + U"texture/";
  const s3d::String textureExtension = U".png";
  for (const auto& desc : textureDescs) {
    s3d::TextureAsset::Register(desc.key, texturePath + desc.path + textureExtension);
  }
}

// private function ------------------------------
// ctor/dtor -------------------------------------


}
}
