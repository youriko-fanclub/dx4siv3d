#include "AudioSource.hpp"
#include "AudioVolume.hpp"
#include "AudioProxy.hpp"

namespace dx {
namespace aud {

/* ---------- AudioSource ---------- */

// static ----------------------------------------
// public function -------------------------------
bool AudioSource::addClip(AudioType type, const Key& key, bool with_play) {
    return addClip(type, key, {}, with_play);
}
bool AudioSource::addClip(AudioType type, const Key& key, const std::vector<AudioTag>& tags, bool with_play) {
    if (m_has_finalized) { return false; }
    if (!m_clips.contains(key)) {
        m_clips.emplace(key, std::make_shared<AudioProxy>(type, key, tags));
        if (with_play) { return play(key); }
        else { return true; }
    }
    return false;
}

bool AudioSource::play(const Key& key, const s3d::Duration& duration) {
    if (m_has_finalized) { return false; }
    if (m_clips.contains(key)) {
        return m_clips.at(key)->play(duration);
    }
    return false;
}

void AudioSource::playOneShot(const Key& key) {
    if (m_has_finalized) { return; }
    if (m_clips.contains(key)) {
        return m_clips.at(key)->playOneShot(m_volume.absolute());
    }
}

void AudioSource::stopAll(const s3d::Duration& duration) {
    if (m_has_finalized) { return; }
    stopAllJustBelow();
    for (auto& source : m_sources) {
        source.second->stopAll(duration);
    }
}
void AudioSource::stopAllJustBelow(const s3d::Duration& duration) {
    if (m_has_finalized) { return; }
    for (const auto& clip : m_clips) {
        clip.second->stop(duration);
    }
}

void AudioSource::stopTag(const AudioTag& tag, const s3d::Duration& duration) {
    if (m_has_finalized) { return; }
    for (const auto& clip : m_clips) {
        if (clip.second->hasTag(tag)) {
            clip.second->stop(duration);
        }
    }
    for (auto& source : m_sources) {
        source.second->stopTag(tag, duration);
    }
}

IAudioSource* AudioSource::addSource(const Key& key, double relative, bool is_mute) {
    m_sources.emplace(key, std::make_shared<AudioSource>(&m_volume, relative, is_mute));
    return m_sources.at(key).get();
}
void AudioSource::removeSource(const Key& key) {
    if (m_sources.contains(key)) {
        m_sources.at(key)->stopAll();
        m_sources.erase(key);
    }
}
IAudioSource* AudioSource::source(const Key& key) {
    if (m_sources.contains(key)) {
        return m_sources.at(key).get();
    }
    else {
        return nullptr;
    }
}

void AudioSource::finalize() {
    if (m_has_finalized) { return; }
    for (auto& source : m_sources) {
        source.second->finalize();
    }
    stopAllJustBelow();
    m_has_finalized = true;
}

void AudioSource::onVolumeChanged() {
    if (m_has_finalized) { return; }
    const double absolute_master_volume = m_volume.absolute();
    for (const auto& clip : m_clips) {
        clip.second->applyMasterVolume(absolute_master_volume);
    }
    for (auto& source : m_sources) {
        source.second->onVolumeChanged();
    }
}
// private function ------------------------------
// ctor/dtor -------------------------------------
AudioSource::AudioSource(const AudioVolume* const parent_volume, double relative, bool is_mute) :
m_volume(this, parent_volume, relative, is_mute) {}


}
}
