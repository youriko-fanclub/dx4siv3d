#include "TomlAssetRepository.hpp"
#include <Siv3D/FileSystem.hpp>
#include "TomlAsset.hpp"

using namespace s3d::Literals::FormatLiterals;

namespace dx {
namespace toml {

/* ---------- TomlAssetRepository ---------- */

// static ----------------------------------------
// public function -------------------------------
bool TomlAssetRepository::load(const s3d::String& filename, const app::Path& directory, bool is_hotreload) {
    if (!is_loaded(filename)) {
        m_tomls.insert(std::make_pair(filename, std::make_shared<TomlAssetImpl>(filename, directory)));
        return true;
    }
    const auto key = (directory / filename).full();
    if (!m_watchers.contains(key)) {
        m_watchers.insert(std::make_pair(key, std::make_unique<s3d::DirectoryWatcher>()));
    }
    return false;
}

void TomlAssetRepository::unload(const s3d::String& filename) {
    if (is_loaded(filename)) {
        m_tomls.erase(filename);
    }
}

void TomlAssetRepository::update() {
    for (const auto& watcher : m_watchers) {
        for (const auto& change : watcher.second->retrieveChanges()) {
            if (change.second != s3d::FileAction::Added
            && change.second != s3d::FileAction::Modified) {
                continue;
            }
            const auto filename = s3d::FileSystem::FileName(change.first);
            // TOML ファイルが更新されたら再読み込み
            std::cout << U"file was changed:{}:{}"_fmt(
                dx::denum::toString(change.second),
                filename) << std::endl;
            if (m_tomls.contains(filename)) {
                m_tomls.at(filename)->load();
            }
        }
    }
}

#if false
void TomlAssetRepository::subscribe(const s3d::String& key, std::shared_ptr<TomlAssetImpl> toml) {
    if (m_tomls.contains(key)) {
        m_tomls.at(key) = toml;
    }
    else {
        m_tomls.insert(std::make_pair(key, toml));
    }
}

void TomlAssetRepository::unsubscribe(const s3d::String& key) {
    if (m_tomls.contains(key)) {
        m_tomls.erase(key);
    }
}
#endif

// private function ------------------------------
// ctor/dtor -------------------------------------
TomlAssetRepository::TomlAssetRepository() {}

}

#if false
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
#endif
}
