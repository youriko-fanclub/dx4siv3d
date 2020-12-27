#pragma once
#include "Enum.hpp"

namespace dx {
namespace dbg {

using Category = s3d::String;

enum class Level : int {
    Error, Info, Debug
};

}
namespace denum {

template <>
s3d::String toString(dbg::Level value);

}
}
