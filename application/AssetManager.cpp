#include "AssetManager.hpp"

#include <Siv3D/FontAsset.hpp>

namespace dx {
namespace app {


/* ---------- AssetManager ---------- */

// static ----------------------------------------
// public function -------------------------------
void AssetManager::initialize(const std::vector<FontDesc>& descs) {
  // 使用するフォントアセットを登録
  const s3d::String fontPath = U"../asset/font/";
  for (const auto& desc : descs) {
    if (!desc.typefaceString.empty()) {
      s3d::FontAsset::Register(desc.key, desc.size, fontPath + desc.typefaceString);
    }
    else {
      s3d::FontAsset::Register(desc.key, desc.size, desc.typeface);
    }
  }
}

// private function ------------------------------
// ctor/dtor -------------------------------------


}
}
