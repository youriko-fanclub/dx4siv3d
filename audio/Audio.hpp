#pragma once
#include "AudioSource.hpp"

namespace dx {
namespace aud {

using AudioDesc = app::AssetManager::AudioDesc;


class AudioMgr : public dx::cmp::Singleton<AudioMgr> {
public: // static_const/enum
    using Tag = s3d::String;
public: // static
public: // public function
    void Register(const AudioDesc& desc);
    const std::shared_ptr<IAudioSource>& masterSource() {
        return m_master_source;
    }
    IAudioSource* source(const s3d::String& key);
    IAudioSource* source(const std::vector<s3d::String>& keys);
    void finalize() override;
    // static void stopAll();
    // static void setMasterVolume();
    // static void mute() { s_is_mute = true; }
    // static bool isMute() { return s_is_mute; }
private: // field
    std::shared_ptr<IAudioSource> m_master_source;

private: // private function
public: // ctor/dtor
    AudioMgr(double master_volume = 1.0, bool is_mute = false);
};

class Audio {
public: // static_const/enum
    using Tag = s3d::String;
public: // static
    static void Register(const AudioDesc& desc) {
        AudioMgr::instance()->Register(desc);
    }
    static const std::shared_ptr<IAudioSource>& masterSource() {
        return AudioMgr::instance()->masterSource();
    }

    static IAudioSource* source(const s3d::String& key) {
        return AudioMgr::instance()->source(key);
    }
    static IAudioSource* source(const std::vector<s3d::String>& keys) {
        return AudioMgr::instance()->source(keys);
    }
    static void Finalize() {
        AudioMgr::instance()->finalize();
    }
public: // ctor/dtor
    Audio() = delete;
};


}
}
