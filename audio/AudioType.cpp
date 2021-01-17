#include "AudioType.hpp"

namespace dx {
namespace denum {

template <>
s3d::String toString(aud::AudioType value) {
    switch (value) {
    case aud::AudioType::BGM  : return U"BGM";
    case aud::AudioType::SE   : return U"SE";
    case aud::AudioType::VOICE: return U"VOICE";
    }
}
template <>
s3d::String toLower(aud::AudioType value) {
    switch (value) {
    case aud::AudioType::BGM  : return U"bgm";
    case aud::AudioType::SE   : return U"se";
    case aud::AudioType::VOICE: return U"voice";
    }
}

}
}
