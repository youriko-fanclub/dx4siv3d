#include "AssetManager.hpp"

#include <Siv3D/FontAsset.hpp>

namespace dx {
namespace app {


/* ---------- AssetManager ---------- */

// static ----------------------------------------
// public function -------------------------------
void AssetManager::initialize() {
  // 使用するフォントアセットを登録
  s3d::FontAsset::Register(U"Title", 120, U"example/font/AnnyantRoman/AnnyantRoman.ttf");
  s3d::FontAsset::Register(U"Menu", 30, s3d::Typeface::Regular);
  s3d::FontAsset::Register(U"Score", 36, s3d::Typeface::Bold);
}

// private function ------------------------------
// ctor/dtor -------------------------------------


}
}
