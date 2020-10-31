#include "Misc.hpp"
#include <Siv3D/Key.hpp>

namespace dx {
namespace misc {

s3d::Vec2 boolToVec2(bool xPositive, bool xNegative, bool yPositive, bool yNegative) {
    if (xPositive || xNegative || yPositive || yNegative) {
        return s3d::Vec2(
            static_cast<int>(xPositive) - static_cast<int>(xNegative),
            static_cast<int>(yPositive) - static_cast<int>(yNegative));
    }
    return s3d::Vec2::Zero();
}

s3d::Vec2 keyPressedToVec2(
    const s3d::Key& xPositive, const s3d::Key& xNegative,
    const s3d::Key& yPositive, const s3d::Key& yNegative) {
    return boolToVec2(
        xPositive.pressed(), xNegative.pressed(),
        yPositive.pressed(), yNegative.pressed());
}

}
}
