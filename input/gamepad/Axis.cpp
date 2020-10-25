#include "Axis.hpp"
#include <Siv3D/MathConstants.hpp>
#include <Siv3D/Circular.hpp>
#include "KeyMapping.hpp"
// #include "Misc.hpp"

using s3d::operator""_deg;

namespace dx {
namespace di {

s3d::Vec2 AxisFromKeyboard::vec(GPAxis axis) const {
    // TOdO: 一旦キーボードをスティックには割り当てない
    return s3d::Vec2::Zero();
    // return m_keyMap.at(axis)();
}

s3d::Vec2 AxisFromJoyCon::vec(GPAxis axis) const {
    if (axis == GPAxis::R) { return s3d::Vec2::Zero(); } // TOdO: 横持ちでない場合は右スティックがある
    if (const auto joy = s3d::JoyConL(0)) { // TOdO:
        if (auto d = joy.povD8()) {
            return s3d::Circular(1, *d * 45_deg).toVec2();
        }
    }
    return s3d::Vec2::Zero();
}

s3d::Vec2 AxisFromMultiSource::vec(GPAxis axis) const {
    s3d::Vec2 vec(0, 0);
    for (const auto& axes : m_axes_list) {
        vec += axes->vec(axis);
    }
    return vec.normalize();
}


}
}
