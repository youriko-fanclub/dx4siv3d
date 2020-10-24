#include "Misc.hpp"

namespace dx {
namespace misc {

s3d::Vec2 boolToVec2(bool xPositive, bool xNegative, bool yPositive, bool yNegative) {
    return s3d::Vec2(
        static_cast<int>(xPositive) - static_cast<int>(xNegative),
        static_cast<int>(yPositive) - static_cast<int>(yNegative));
}

}
}
