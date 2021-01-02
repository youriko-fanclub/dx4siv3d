#include "TomlAssetRepository.hpp"
#include <Siv3D/FileSystem.hpp>
#include "Path.hpp"

using namespace s3d::Literals::FormatLiterals;

namespace dx {
namespace cmp {

/* ---------- TomlAssetRepository ---------- */

// static ----------------------------------------
// public function -------------------------------
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
