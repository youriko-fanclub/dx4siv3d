#pragma once
#include <Siv3D/HashTable.hpp>
#include <Siv3D/Duration.hpp>
#include "AssetManager.hpp"
#include "AudioVolume.hpp"

namespace dx {
namespace aud {

class AudioProxy;

using AudioTag = s3d::String;

class IAudioSource {
public:
    using Key = s3d::String;
public:
    virtual bool addClip(AudioType type, const Key& key, bool with_play = false) = 0;
    virtual bool addClip(AudioType type, const Key& key, const s3d::Array<AudioTag>& tags, bool with_play = false) = 0;
    virtual bool play(const Key& key, const s3d::Duration& duration = s3d::SecondsF(0.0)) = 0;
    virtual void playOneShot(const Key& key) = 0;
    
    virtual void stopAll(const s3d::Duration& duration = s3d::SecondsF(0.0)) = 0;
    virtual void stopAllJustBelow(const s3d::Duration& duration = s3d::SecondsF(0.0)) = 0;
    virtual void stopTag(const AudioTag& tag, const s3d::Duration& duration = s3d::SecondsF(0.0)) = 0;
    virtual AudioVolume* volume() = 0;

    virtual IAudioSource* addSource(const Key& key, double relative = 1.0, bool is_mute = false) = 0;
    virtual void removeSource(const Key& key) = 0;
    virtual IAudioSource* source(const Key& key) = 0;
    
    virtual void finalize() = 0;
    
protected:
    IAudioSource() = default;
public:
    virtual ~IAudioSource() = default;
};


class IAudioSourceAsVolumeChangedObserver {
public:
    virtual void onVolumeChanged() = 0;
protected:
    IAudioSourceAsVolumeChangedObserver() = default;
public:
    virtual ~IAudioSourceAsVolumeChangedObserver() = default;
};


class AudioSource final : public IAudioSource, public IAudioSourceAsVolumeChangedObserver {
public: // static_const/enum
public: // static
public: // public function
    bool addClip(AudioType type, const Key& key, bool with_play = false) override;
    bool addClip(AudioType type, const Key& key, const s3d::Array<AudioTag>& tags, bool with_play = false) override;
    bool play(const Key& key, const s3d::Duration& duration = s3d::SecondsF(0.0)) override;
    void playOneShot(const Key& key) override;
    
    void stopAll(const s3d::Duration& duration = s3d::SecondsF(0.0)) override;
    void stopAllJustBelow(const s3d::Duration& duration = s3d::SecondsF(0.0)) override;
    void stopTag(const AudioTag& tag, const s3d::Duration& duration = s3d::SecondsF(0.0)) override;
    virtual AudioVolume* volume() override { return &m_volume; }

    IAudioSource* addSource(const Key& key, double relative = 1.0, bool is_mute = false) override;
    void removeSource(const Key& key) override;
    IAudioSource* source(const Key& key) override;
    
    void finalize() override;
    
    void onVolumeChanged() override;
    
private: // field
    bool m_has_finalized = false;
    s3d::HashTable<s3d::String, std::shared_ptr<AudioProxy>> m_clips;
    s3d::HashTable<s3d::String, std::shared_ptr<AudioSource>> m_sources;
    AudioVolume m_volume;
private: // private function
public: // ctor/dtor
    AudioSource(const AudioVolume* const parent_volume, double relative = 1.0, bool is_mute = false);
    ~AudioSource() override = default;
};


}
}
