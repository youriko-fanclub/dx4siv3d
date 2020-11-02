#pragma once
#include <Siv3D/Vector2D.hpp>

namespace s3d {
class Key;
}

namespace dx {
namespace misc {

s3d::Vec2 boolToVec2(bool xPositive, bool xNegative, bool yPositive, bool yNegative);
s3d::Vec2 keyPressedToVec2(
    const s3d::Key& xPositive, const s3d::Key& xNegative,
    const s3d::Key& yPositive, const s3d::Key& yNegative);
    
bool approximately(float a, float b);
bool approximately(double a, double b);
bool approximately(const s3d::Vec2& a, const s3d::Vec2& b);
bool approximatelyZero(float value);
bool approximatelyZero(double value);
bool approximatelyZero(const s3d::Vec2& value);

}
}
