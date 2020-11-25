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
        if (m_param_list.contains(filename)) {
            m_param_list.at(filename)->load();
        }
    }
}

void HotReloadManager::subscribe(const s3d::String& key, std::shared_ptr<HotReloadableParameters> params) {
    if (m_param_list.contains(key)) {
        m_param_list.at(key) = params;
    }
    else {
        m_param_list.insert(std::make_pair(key, params));
    }
}

void HotReloadManager::unsubscribe(const s3d::String& key) {
    if (m_param_list.contains(key)) {
        m_param_list.erase(key);
    }
}

// private function ------------------------------
// ctor/dtor -------------------------------------
HotReloadManager::HotReloadManager() :
m_directory(s3d::FileSystem::FullPath(app::FilePath::asset_toml)),
m_watcher(m_directory)
{}

}
}
