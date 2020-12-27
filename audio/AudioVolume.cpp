#include "AudioVolume.hpp"
#include <cassert>
#include "AudioSource.hpp"

namespace dx {
namespace aud {

/* ---------- AudioVolume ---------- */

// static ----------------------------------------
// public function -------------------------------
AudioVolume::Value AudioVolume::absolute() const {
    if (m_is_mute) {
        return 0.0;
    }
    else if (m_master){
        return m_master->absolute() * m_relative;
    }
    else {
        return m_relative;
    }
}

void AudioVolume::setRelative(Value relative) {
    if (m_relative != relative) {
        m_relative = relative;
        if (m_observer) {
            m_observer->onVolumeChanged();
        }
    }
}

// private function ------------------------------
// ctor/dtor -------------------------------------
AudioVolume::AudioVolume(IAudioSourceAsVolumeChangedObserver* observer, const AudioVolume* const parent_volume, double relative, bool is_mute) :
m_master(parent_volume),
m_relative(relative),
m_is_mute(is_mute),
m_observer(observer) {}


}
}
