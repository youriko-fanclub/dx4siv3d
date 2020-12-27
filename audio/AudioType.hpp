#pragma once
#include "Enum.hpp"

namespace dx {
namespace aud {

enum class AudioType : int {
    BGM, SE, VOICE
};

}

namespace denum {

template <>
s3d::String toString(aud::AudioType value);
template <>
s3d::String toLower(aud::AudioType value);

}
}
