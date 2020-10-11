#include "AssetManager.hpp"

#include <Siv3D/FontAsset.hpp>

namespace dx {
namespace app {


/* ---------- AssetManager ---------- */

// static ----------------------------------------
// public function -------------------------------
void AssetManager::initialize(const std::vector<FontDesc>& descs) {
  // 使用するフォントアセットを登録
  for (const auto& desc : descs) {
    if (desc.typefaceString.empty()) {
      s3d::FontAsset::Register(desc.key, desc.size, desc.typeface);
    }
    else {
      s3d::FontAsset::Register(desc.key, desc.size, desc.typefaceString);
    }
  }
}

// private function ------------------------------
// ctor/dtor -------------------------------------


}
}
