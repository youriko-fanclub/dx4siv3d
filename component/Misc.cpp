#include "Misc.hpp"
#include <Siv3D/Key.hpp>
#include <cfloat>

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


bool approximately(float a, float b) {
    return fabs(a - b) <= FLT_EPSILON;
}
bool approximately(double a, double b) {
    return abs(a - b) <= DBL_EPSILON;
}
bool approximately(const s3d::Vec2& a, const s3d::Vec2& b) {
    return approximately(a.x, b.x) && approximately(a.y, b.y);
}

bool approximately0(float value) {
    return fabs(value) <= FLT_EPSILON;
}
bool approximately0(double value) {
    return abs(value) <= DBL_EPSILON;
}
bool approximately0(const s3d::Vec2& value) {
    return approximately0(value.x) && approximately0(value.y);
}

}
}
