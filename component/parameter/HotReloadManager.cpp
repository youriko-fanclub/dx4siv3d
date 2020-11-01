#include "HotReloadManager.hpp"
#include <Siv3D/FileSystem.hpp>
#include "FilePath.hpp"

using namespace s3d::Literals::FormatLiterals;

namespace dx {
namespace cmp {

/* ---------- HotReloadManager ---------- */

// static ----------------------------------------
// public function -------------------------------
void HotReloadManager::update() {
    for (const auto& change : m_watcher.retrieveChanges()) {
        if (change.second != s3d::FileAction::Added
        && change.second != s3d::FileAction::Modified) {
            continue;
        }
        const auto filename = s3d::FileSystem::FileName(change.first);
        // TOML ファイルが更新されたら再読み込み
        std::cout << U"file was changed:{}:{}"_fmt(
            dx::denum::toString(change.second),
            filename) << std::endl;
        if (m_paramList.contains(filename)) {
            m_paramList.at(filename)->load();
        }
    }
}

void HotReloadManager::registrate(const s3d::String& key, HotReloadableParameters* params) {
    if (m_paramList.contains(key)) {
        m_paramList.at(key) = params;
    }
    else {
        m_paramList.insert(std::make_pair(key, params));
    }
}

void HotReloadManager::unregistrate(const s3d::String& key) {
    if (m_paramList.contains(key)) {
        m_paramList.erase(key);
    }
}

// private function ------------------------------
// ctor/dtor -------------------------------------
HotReloadManager::HotReloadManager() :
m_directory(s3d::FileSystem::FullPath(app::FilePath::asset_toml + U"toml/")),
m_watcher(m_directory)
{}

}
}
