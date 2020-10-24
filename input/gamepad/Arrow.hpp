#pragma once
#include "Axis.hpp"

namespace dx {
namespace di {

using GPArrow = GPAxis;

class IArrow {
public:
    virtual Vec2 key(GPArrow arrow) const = 0;
    virtual Vec2 keyL() const = 0;
    virtual Vec2 keyR() const = 0;
protected:
    IArrow() = default;
    virtual ~IArrow() = default;
};

class AbsArrow : public IArrow {
public:
    // virtual const IKey& key(GPButton button) const = 0;
    Vec2 keyL() const override { return key(GPArrow::L); }
    Vec2 keyR() const override { return key(GPArrow::R); }
protected:
    AbsArrow() = default;
    virtual ~AbsArrow() = default;
};

class ArrowFromKeyboard final : public AbsArrow {
public: // static_const/enum
public: // static
public: // public function
    Vec2 key(GPArrow arrow) const override {
        switch (arrow) {
        case GPArrow::L: {
            return (m_axis.keyL() + m_dpad.vec()).clamped(RectF(Arg::center(0, 0), 2));
        }
        case GPArrow::R: {
            return (m_axis.keyR() + dx::misc::boolToVec2(
                m_buttons.a().pressed(), m_buttons.y().pressed(),
                m_buttons.b().pressed(), m_buttons.x().pressed()))
                .clamped(RectF(Arg::center(0, 0), 2));
        }
        }
    }
private: // field
private: // private function
    const IButtons& m_buttons;
    const IDPad& m_dpad;
    const IAxis& m_axis;
public: // ctor/dtor
    ArrowFromKeyboard(const IButtons& buttons, const IDPad& dpad, const IAxis& axis) :
        m_axis(axis),
        m_dpad(dpad),
        m_buttons(buttons) {}
};

}
}
