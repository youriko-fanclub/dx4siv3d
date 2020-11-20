#include "HotReloadableParameters.hpp"
#include <Siv3D/FileSystem.hpp>
#include <Siv3D/Vector2D.hpp>
#include <Siv3D/Font.hpp>
#include "FilePath.hpp"
#include "HotReloadManager.hpp"

using namespace s3d::Literals::FormatLiterals;

namespace dx {
namespace cmp {

/* ---------- Param ---------- */

// static ----------------------------------------
// public function -------------------------------
void HotReloadableParameters::load() {  // TOML ファイルからデータを読み込む
    const s3d::TOMLReader toml(m_path);
    if (!toml) { // もし読み込みに失敗したら
        throw s3d::Error(U"Failed to load `config.toml`");
    }
    m_reader = toml;
    loadImpl(m_reader);
}

s3d::Vec2 HotReloadableParameters::getVec2(const s3d::String& key) const {
    return s3d::Vec2(
        m_reader[key + U".x"].get<float>(),
        m_reader[key + U".y"].get<float>());
}
s3d::Size HotReloadableParameters::getSize(const s3d::String& key) const {
    return s3d::Size(
        m_reader[key + U".w"].get<int>(),
        m_reader[key + U".h"].get<int>());
}
s3d::ColorF HotReloadableParameters::getColorF(const s3d::String& key) const {
    const float a =
        m_reader[key].hasMember(U"a")
        ? m_reader[key + U".a"].get<float>()
        : 1.f;
    return s3d::ColorF(
        m_reader[key + U".r"].get<float>(),
        m_reader[key + U".g"].get<float>(),
        m_reader[key + U".b"].get<float>(), a);
}
std::shared_ptr<s3d::Font> HotReloadableParameters::getFontPtr(const s3d::String& key) const {
    return std::make_shared<s3d::Font>(
        m_reader[key + U".size"].get<int>(),
        dx::app::FilePath::asset_font + m_reader[key + U".name"].getString());
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
