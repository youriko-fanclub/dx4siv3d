#pragma once
#include <Siv3D/Vector2D.hpp>

namespace s3d {
class Key;
}

namespace dx {
namespace misc {

s3d::Vec2 boolToVec2(bool x_positive, bool x_negative, bool y_positive, bool y_negative);
s3d::Vec2 keyPressedToVec2(
    const s3d::Key& x_positive, const s3d::Key& x_negative,
    const s3d::Key& y_positive, const s3d::Key& y_negative);
    
bool approximately(float a, float b);
bool approximately(double a, double b);
bool approximately(const s3d::Vec2& a, const s3d::Vec2& b);
bool approximatelyZero(float value);
bool approximatelyZero(double value);
bool approximatelyZero(const s3d::Vec2& value);

}
}
