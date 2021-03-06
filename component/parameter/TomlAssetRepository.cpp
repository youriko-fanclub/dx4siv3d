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
    if (!isLoaded(filename)) {
        m_tomls.emplace(filename, std::make_shared<TomlAssetImpl>(filename, directory));
        const auto key = directory.full();
        if (!m_watchers.contains(key)) {
            m_watchers.emplace(key, s3d::DirectoryWatcher(directory.full()));
        }
        return true;
    }
    return false;
}

void TomlAssetRepository::unload(const s3d::String& filename) {
    if (isLoaded(filename)) {
        m_tomls.erase(filename);
    }
}

void TomlAssetRepository::update() {
    for (const auto& watcher : m_watchers) {
        for (const auto& change : watcher.second.retrieveChanges()) {
            if (change.second != s3d::FileAction::Added
            && change.second != s3d::FileAction::Modified) {
                continue;
            }
            const auto filename = s3d::FileSystem::FileName(change.first);
            // TOML ファイルが更新されたら再読み込み
            std::cout << U"file was changed:{}:{}"_fmt(
                dx::denum::toString(change.second),
                filename) << std::endl;
            const s3d::String stem = filename.removed(U".toml");
            if (m_tomls.contains(stem)) {
                m_tomls.at(stem)->load();
            }
        }
    }
}

// private function ------------------------------
// ctor/dtor -------------------------------------

}

namespace denum {

template <>
s3d::Array<s3d::FileAction> elems() {
    return s3d::Array<s3d::FileAction>({
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
