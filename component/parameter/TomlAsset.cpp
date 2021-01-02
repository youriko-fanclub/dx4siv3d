#include "TomlAsset.hpp"
#include "TomlAssetRepository.hpp"
#include "Log.hpp"

namespace dx {
namespace cmp {

/* ---------- TomlKey ---------- */

// static ----------------------------------------
const s3d::String TomlKey::delimiter = U".";
// public function -------------------------------
// private function ------------------------------
// ctor/dtor -------------------------------------



/* ---------- TomlAssetImpl ---------- */

// static ----------------------------------------
// public function -------------------------------
void TomlAssetImpl::load() { // TOML ファイルからデータを読み込む
    const auto full_path = m_path / (m_filename + U".toml");
    const s3d::TOMLReader toml(full_path.full());
    dbg::Log::debug(U"Toml", full_path.full());
    if (!toml) { // もし読み込みに失敗したら
        throw s3d::Error(U"Failed to load " + full_path.full());
    }
    m_reader = toml;
}
// private function ------------------------------
// ctor/dtor -------------------------------------
TomlAssetImpl::TomlAssetImpl(const s3d::String& filename, const app::Path& path) :
m_filename(filename),
m_path(path) {
    load();
}
TomlAssetImpl::~TomlAssetImpl() {}


/* ---------- TomlAsset ---------- */

// static ----------------------------------------
bool TomlAsset::load(const s3d::String& name, const app::Path& path) {
    return TomlAssetRepository::instance()->load(name, path);
}

void TomlAsset::unload(const s3d::String& name) {
    TomlAssetRepository::instance()->unload(name);
}

bool TomlAsset::is_loaded(const s3d::String& name) {
    return TomlAssetRepository::instance()->is_loaded(name);
}

// public function -------------------------------
// private function ------------------------------
// ctor/dtor -------------------------------------
TomlAsset::TomlAsset(const s3d::String& filename) :
    m_impl(TomlAssetRepository::instance()->get(filename)) {}
TomlAsset::~TomlAsset() {}

}
}
