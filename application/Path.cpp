#include "Path.hpp"

namespace dx {
namespace app {

/* ---------- Path ---------- */

// static ----------------------------------------
const s3d::String Path::delimiter = U"/";

// .appファイルからの相対パス
const Path Path::asset         = Path(U"..") / U"KANJI-asset";
const Path Path::asset_font    = asset / U"font";
const Path Path::asset_texture = asset / U"texture";
const Path Path::asset_audio   = asset / U"audio" / U"mp3";
const Path Path::asset_toml    = asset / U"toml";
const Path Path::asset_schema  = asset / U"schema";

// public function -------------------------------
// private function ------------------------------
// ctor/dtor -------------------------------------

}
}
