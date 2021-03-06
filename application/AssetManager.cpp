#include "AssetManager.hpp"
#include <Siv3D/FontAsset.hpp>
#include <Siv3D/TextureAsset.hpp>
#include <Siv3D/AudioAsset.hpp>
#include <Siv3D/FileSystem.hpp>
#include <Siv3D/TOMLReader.hpp>
#include "Path.hpp"
#include "Audio.hpp"
#include "TomlAsset.hpp"

namespace {

using AudioDesc = dx::app::AssetManager::AudioDesc;
AudioDesc get(const s3d::TOMLReader& toml, dx::aud::AudioType type, const s3d::String& toml_key) {
    const auto t = toml[U"asset.audio." + dx::denum::toLower(type) + U"." + toml_key];
    auto key = t[U"key"].getString();
    auto path = key;
    if (t.hasMember(U"path")) {
        path = t[U"path"].getString();
    }
    auto is_loop = false;
    if (t.hasMember(U"is_loop")) {
        is_loop = t[U"is_loop"].get<bool>();
    }
    return AudioDesc(type, key, path, is_loop);
}

}

namespace dx {
namespace app {


/* ---------- AudioDesc ---------- */

// static ----------------------------------------
s3d::Array<AssetManager::AudioDesc> AudioDesc::loadFromToml() {
    const s3d::TOMLReader toml((app::Path::asset_toml / U"hot" / U"AudioAsset.toml").full());
    if (!toml) { // もし読み込みに失敗したら
        throw s3d::Error(U"Failed to load `AudioAsset.toml`");
    }
    const std::initializer_list<s3d::String> bgm_list = {
        U"title", U"menu", U"battle01", U"battle02", U"battle03", U"result",
    };
    const std::initializer_list<s3d::String> se_list = {
        U"system.decide",
        U"system.cancel",
        U"system.choose",
        U"battle.game.game_start",
        U"battle.game.game_set",
        U"battle.chara.appear",
        U"battle.chara.burn_out",
        U"battle.chara.chara_rotation",
        U"battle.chara.damage",
        U"battle.chara.get_radical_simple",
        U"battle.chara.get_radical_gorgeous",
        U"battle.move.normal",
        U"battle.move.normal_with_radical",
        U"battle.move.special",
        U"battle.move.special.aburu",
        U"battle.move.special.arashi",
        U"battle.move.special.hoshi",
        U"battle.move.special.ikaduchi",
        U"battle.move.special.katamari_rolling",
        U"battle.move.special.katamari_scrape",
        U"battle.move.special.kiri",
        U"battle.move.special.komainu_bark",
        U"battle.move.special.komainu_growl",
        U"battle.move.special.kuruu",
        U"battle.move.special.noroi",
        U"battle.move.special.tagane",
        U"battle.move.special.toki",
        U"battle.chara.damage",
        U"battle.chara.move.kobushi",
    };
    const std::initializer_list<s3d::String> voice_list = {
        U"system.decide",
    };
    s3d::Array<AudioDesc> descs;
    descs.reserve(bgm_list.size() + se_list.size() + voice_list.size());
    for (const auto& key : bgm_list) {
        descs.push_back(get(toml, aud::AudioType::BGM, key));
    }
    for (const auto& key : se_list) {
        descs.push_back(get(toml, aud::AudioType::SE, key));
    }
    for (const auto& key : voice_list) {
        descs.push_back(get(toml, aud::AudioType::VOICE, key));
    }
    return descs;
}
// public function -------------------------------
// private function ------------------------------
// ctor/dtor -------------------------------------



/* ---------- AssetManager ---------- */

// static ----------------------------------------
struct TomlDesc {
    const s3d::String file_name;
    const dx::app::Path path;
    TomlDesc(const s3d::String& file_name, const dx::app::Path& path) :
    file_name(file_name),
    path(path) {}
};
// public function -------------------------------
void AssetManager::initialize(
    const s3d::Array<FontDesc>& font_descs,
    const s3d::Array<TextureDesc>& texture_descs,
    const s3d::Array<AudioDesc>& audio_descs) {
    
    // Font
    for (const auto& desc : font_descs) {
        if (!desc.typeface_string.empty()) {
            s3d::FontAsset::Register(desc.key, desc.size, Path::asset_font / desc.typeface_string);
        }
        else {
            s3d::FontAsset::Register(desc.key, desc.size, desc.typeface);
        }
    }
    
    // Texture
    for (const s3d::String extension = U".png"; const auto& desc : texture_descs) {
        s3d::TextureAsset::Register(desc.key, Path::asset_texture / (desc.path + extension));
    }
    
    // Audio
    for (const auto& desc : audio_descs) {
        aud::Audio::Register(desc);
    }
    
    // Toml
    const auto hot_toml = dx::app::Path::asset_toml / U"hot";
    const auto md       = dx::app::Path::asset_schema / U"master" / U"class";
    const auto md_kanji = dx::app::Path::asset_schema / U"master" / U"class" / U"kanji";
    for (const auto& desc : {
        // misc
        TomlDesc(U"System" , hot_toml),
        TomlDesc(U"Battle" , hot_toml),
        TomlDesc(U"Physics", hot_toml),
        TomlDesc(U"Develop", hot_toml),
        // masterdata
        TomlDesc(U"KanjiParam"       , md_kanji),
        TomlDesc(U"KanjiDictionary"  , md_kanji),
        TomlDesc(U"RadicalParam"     , md_kanji),
        TomlDesc(U"RadicalDictionary", md_kanji),
        TomlDesc(U"KanjiConsist"     , md_kanji),
        TomlDesc(U"Stage"            , md),
    }) {
        dx::toml::TomlAsset::load(desc.file_name, desc.path);
    }
}

// private function ------------------------------
// ctor/dtor -------------------------------------


}
}
