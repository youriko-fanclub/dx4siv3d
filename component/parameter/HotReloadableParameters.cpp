#include "HotReloadableParameters.hpp"
#include <Siv3D/FileSystem.hpp>
#include <Siv3D/TOMLReader.hpp>
#include "FilePath.hpp"
#include "HotReloadManager.hpp"

using namespace s3d::Literals::FormatLiterals;

namespace dx {
namespace cmp {

/* ---------- Param ---------- */

// static ----------------------------------------
// public function -------------------------------
void HotReloadableParameters::update() {
    for (const auto& change : m_watcher.retrieveChanges()) {
        // TOML ファイルが更新されたら再読み込み
        std::cout << U"file was changed:{}:{}"_fmt(
            dx::denum::toString(change.second),
            s3d::FileSystem::FileName(change.first)) << std::endl;
        if (change.first == m_path
        && (change.second == s3d::FileAction::Added || change.second == s3d::FileAction::Modified)) {
            load();
        }
    }
}

void HotReloadableParameters::load() {  // TOML ファイルからデータを読み込む
    const s3d::TOMLReader toml(m_path);
    if (!toml) { // もし読み込みに失敗したら
        throw s3d::Error(U"Failed to load `config.toml`");
    }
    m_reader = toml;
    loadImpl(m_reader);
}

// private function ------------------------------
// ctor/dtor -------------------------------------
HotReloadableParameters::HotReloadableParameters(const s3d::String& filename) :
m_filename(filename + U".toml"),
m_path(s3d::FileSystem::FullPath(app::FilePath::asset_toml + U"hot/" + m_filename)),
m_watcher(s3d::FileSystem::ParentPath(m_path)) {}

HotReloadableParameters::~HotReloadableParameters() {
    const auto& instance = HotReloadManager::instance();
    if (instance != nullptr) {
        instance->unsubscribe(m_filename);
    }
}

}

namespace denum {

template <>
std::vector<s3d::FileAction> elems() {
    return std::vector<s3d::FileAction>({
        s3d::FileAction::Unknown,
        s3d::FileAction::Added,
        s3d::FileAction::Removed,
        s3d::FileAction::Modified,
    });
}
template <>
s3d::String toString(s3d::FileAction value) {
    switch (value) {
    case s3d::FileAction::Unknown : return U"Unknown";
    case s3d::FileAction::Added   : return U"Added";
    case s3d::FileAction::Removed : return U"Removed";
    case s3d::FileAction::Modified: return U"Modified";
    }
}

}
}
