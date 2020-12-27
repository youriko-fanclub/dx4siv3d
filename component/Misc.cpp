#include "Misc.hpp"
#include <Siv3D/Key.hpp>
#include <cfloat>

namespace dx {
namespace misc {

s3d::Vec2 boolToVec2(bool x_positive, bool x_negative, bool y_positive, bool y_negative) {
    if (x_positive || x_negative || y_positive || y_negative) {
        return s3d::Vec2(
            static_cast<int>(x_positive) - static_cast<int>(x_negative),
            static_cast<int>(y_positive) - static_cast<int>(y_negative));
    }
    return s3d::Vec2::Zero();
}

s3d::Vec2 keyPressedToVec2(
    const s3d::Key& x_positive, const s3d::Key& x_negative,
    const s3d::Key& y_positive, const s3d::Key& y_negative) {
    return boolToVec2(
        x_positive.pressed(), x_negative.pressed(),
        y_positive.pressed(), y_negative.pressed());
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

bool approximatelyZero(float value) {
    return fabs(value) <= FLT_EPSILON;
}
bool approximatelyZero(double value) {
    return abs(value) <= DBL_EPSILON;
}
bool approximatelyZero(const s3d::Vec2& value) {
    return approximatelyZero(value.x) && approximatelyZero(value.y);
}

}
}
