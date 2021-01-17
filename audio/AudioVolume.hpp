#pragma once
#include "RangedValue.hpp"

namespace dx {
namespace aud {

class IAudioSourceAsVolumeChangedObserver;

class AudioVolume {
public: // static_const/enum
    using Value = double;
    using Ratio = cmp::RangedValue<double, 0, 1>;
public: // static
public: // public function
    Value absolute() const;
    const Ratio& relative() const { return m_relative; }
    bool isMute() const { return m_is_mute; }

    void setRelative(Value relative);
    void setMute(bool is_mute) { m_is_mute = is_mute; }
private: // field
    const AudioVolume* const m_master;
    Ratio m_relative; // [0, 1]
    bool m_is_mute;
    
    IAudioSourceAsVolumeChangedObserver* m_observer;
private: // private function
public: // ctor/dtor
    AudioVolume(IAudioSourceAsVolumeChangedObserver* observer, const AudioVolume* const parent_volume, double relative, bool is_mute);
};


}
}
