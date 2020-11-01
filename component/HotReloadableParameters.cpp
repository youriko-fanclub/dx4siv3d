#include "HotReloadableParameters.hpp"
#include <Siv3D/FileSystem.hpp>
#include <Siv3D/TOMLReader.hpp>
#include "FilePath.hpp"

using namespace s3d::Literals::FormatLiterals;

namespace dx {
namespace cmp {

/* ---------- Param ---------- */

// static ----------------------------------------
// public function -------------------------------
void Param::update() {
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

void Param::load() {  // TOML ファイルからデータを読み込む
    const s3d::TOMLReader toml(m_path);
    if (!toml) { // もし読み込みに失敗したら
        throw s3d::Error(U"Failed to load `config.toml`");
    }
    // 要素のパスで値を取得
    force_horizontal = toml[U"chara.force.horizontal"].get<double>();
    force_jump       = toml[U"chara.force.jump"].get<double>();
    chara_friction   = toml[U"chara.friction"].get<double>();
    air_resistance   = toml[U"chara.air_resistance"].get<double>();
    floor_friction   = toml[U"floor.friction"].get<double>();
    wall_friction    = toml[U"wall.friction"].get<double>();
}

// private function ------------------------------
// ctor/dtor -------------------------------------
Param::Param() :
m_path(s3d::FileSystem::FullPath(app::FilePath::asset_toml + U"hot/" + file + U".toml")),
m_watcher(s3d::FileSystem::ParentPath(m_path)) {
    load();
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
