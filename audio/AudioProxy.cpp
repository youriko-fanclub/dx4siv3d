#include "AudioProxy.hpp"

namespace {

const s3d::String generateKey(dx::aud::AudioType type, const s3d::String& short_key) {
    return dx::denum::toString(type) + U"::" + short_key;
}

}

namespace dx {
namespace aud {


/* ---------- AudioProxy ---------- */

// static ----------------------------------------
// public function -------------------------------
bool AudioProxy::play(const s3d::Duration& duration) const {
    if (isValid()) {
        return getReal().play(duration);
    }
    else {
        return false;
    }
}
void AudioProxy::pause(const s3d::Duration& duration) const {
    if (isValid()) {
        getReal().pause(duration);
    }
}
void AudioProxy::stop(const s3d::Duration& duration) const {
    if (isValid()) {
        getReal().stop(duration);
    }
}
void AudioProxy::playOneShot(double volume, double speed) const {
    if (isValid()) {
        getReal().playOneShot(volume, speed);
    }
}
void AudioProxy::stopAllShots() const {
    if (isValid()) {
        getReal().stopAllShots();
    }
}

void AudioProxy::setVolume(double volume) const {
    if (isValid()) {
        getReal().setVolume(volume);
    }
}

void AudioProxy::applyMasterVolume(double master_volume) const {
    if (isValid()) {
        setVolume(master_volume);
    }
}

// private function ------------------------------
// ctor/dtor -------------------------------------
AudioProxy::AudioProxy(const AudioDesc& desc) :
type(desc.type),
key(generateKey(desc.type, desc.key)),
m_tags() {}

AudioProxy::AudioProxy(const AudioDesc& desc, const s3d::Array<AudioTag>& tags) :
type(desc.type),
key(generateKey(desc.type, desc.key)),
m_tags(tags) {}

AudioProxy::AudioProxy(AudioType type, const s3d::String& key) :
type(type),
key(key),
m_tags() {}

AudioProxy::AudioProxy(AudioType type, const s3d::String& key, const s3d::Array<AudioTag>& tags) :
type(type),
key(key),
m_tags(tags) {}


}
}
