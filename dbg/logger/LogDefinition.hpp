#pragma once
#include <Siv3D/String.hpp>
#include "Enum.hpp"

namespace dx {
namespace dbg {

enum class Level : int {
    Error, Info, Debug
};

}
namespace denum {

template <>
s3d::String toString(dbg::Level value);

}
}
