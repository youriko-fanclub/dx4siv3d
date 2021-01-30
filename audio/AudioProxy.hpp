#pragma once
#include <Siv3D/AudioAsset.hpp>
#include "AssetManager.hpp"

namespace dx {
namespace aud {

using AudioTag = s3d::String;
using AudioDesc = app::AssetManager::AudioDesc;

class IAudioSource;

class AudioProxy {
public: // static_const/enum
    static AudioProxy Null;
public: // static
public: // public function
    bool hasTag(const AudioTag& tag) const {
        return std::find(m_tags.begin(), m_tags.end(), tag) != m_tags.end();
    }

    bool play(const s3d::Duration& duration = s3d::SecondsF(0.0)) const;
    void pause(const s3d::Duration& duration = s3d::SecondsF(0.0)) const;
    void stop(const s3d::Duration& duration = s3d::SecondsF(0.0)) const;
    void playOneShot(double volume = 1.0, double speed = 1.0) const;
    void stopAllShots() const;
    
    void setVolume(double volume) const;
    void applyMasterVolume(double master_volume) const;

public: // field
    const AudioType type;
    const s3d::String key;
    s3d::Array<AudioTag> m_tags;
private: // private function
    s3d::AudioAsset getReal() const { return s3d::AudioAsset(key); }
    bool isValid() const {
        return !key.empty() && s3d::AudioAsset::IsRegistered(key);
    }
public: // ctor/dtor
    AudioProxy(const AudioDesc& desc);
    AudioProxy(const AudioDesc& desc, const s3d::Array<AudioTag>& tags);
    AudioProxy(AudioType type, const s3d::String& short_key);
    AudioProxy(AudioType type, const s3d::String& short_key, const s3d::Array<AudioTag>& tags);
private:
    AudioProxy() : // 無効値用
    type(AudioType::BGM),
    key(U"") {}
};


}
}
