#include "AssetManager.hpp"
#include <unordered_map>
#include <Siv3D/FontAsset.hpp>
#include <Siv3D/TextureAsset.hpp>
#include <Siv3D/AudioAsset.hpp>
#include <Siv3D/FileSystem.hpp>
#include <Siv3D/TOMLReader.hpp>
#include "Path.hpp"
#include "Audio.hpp"

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
std::vector<AssetManager::AudioDesc> AudioDesc::loadFromToml() {
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
    std::vector<AudioDesc> descs;
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
// public function -------------------------------
void AssetManager::initialize(
    const std::vector<FontDesc>& font_descs,
    const std::vector<TextureDesc>& texture_descs,
    const std::vector<AudioDesc>& audio_descs) {
    
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
}

// private function ------------------------------
// ctor/dtor -------------------------------------


}
}
