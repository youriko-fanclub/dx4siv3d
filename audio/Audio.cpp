#include "Audio.hpp"
#include "AudioProxy.hpp"
#include "AudioSource.hpp"
#include "Siv3D/AudioAsset.hpp"
#include "FilePath.hpp"

namespace {

const s3d::String generatePath(dx::aud::AudioType type, const s3d::String& short_path) {
    static const s3d::String extention = U".mp3";
    return dx::app::FilePath::asset_audio + dx::denum::toString(type) + U"/" + short_path + extention;
}

}

namespace dx {
namespace aud {


/* ---------- AudioMgr ---------- */

// static ----------------------------------------
// public function -------------------------------
void AudioMgr::Register(const AudioDesc& desc) {
    AudioProxy proxy(desc);
    s3d::AudioAsset::Register(
        proxy.key,
        generatePath(desc.type, desc.path));
}
IAudioSource* AudioMgr::source(const s3d::String& key) {
    return m_master_source->source(key);
}
IAudioSource* AudioMgr::source(const std::vector<s3d::String>& keys) {
    IAudioSource* ret = m_master_source.get();
    for (const auto& key : keys) {
        ret = ret->source(key);
        if (!ret) { return nullptr; }
    }
    return ret;
}
void AudioMgr::finalize() {
    m_master_source->finalize();
    m_master_source.reset();
}
// void Audio::stopAll() { }
// void Audio::setMasterVolume() { }
// private function ------------------------------
// ctor/dtor -------------------------------------
AudioMgr::AudioMgr(double master_volume, bool is_mute) :
m_master_source(std::make_shared<AudioSource>(nullptr, master_volume, is_mute)) {}


}
}
