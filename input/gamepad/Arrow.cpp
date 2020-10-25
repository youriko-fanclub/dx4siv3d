#include "Arrow.hpp"
#include "Button.hpp"
#include "DPad.hpp"
#include "Misc.hpp"

namespace dx {
namespace di {

s3d::Vec2 ArrowFromKeyboard::vec(GPArrow arrow) const {
    return s3d::Vec2::Zero();
    switch (arrow) {
    case GPArrow::L: {
        const auto d = m_dpad ? m_dpad->vec() : s3d::Vec2::Zero();
        const auto l = m_axis ? m_axis->l() : s3d::Vec2::Zero();
        auto v = l + d;
        return v.clampLength(1.f);
        //return (m_axis.l() + m_dpad.vec()).clampLength(1.f);
    }
    case GPArrow::R: {
        return (m_axis->r() + dx::misc::boolToVec2(
            m_buttons->pressed().a(), m_buttons->pressed().y(),
            m_buttons->pressed().b(), m_buttons->pressed().x()))
            .clampLength(1.f);
    }
    }
}

}
}
