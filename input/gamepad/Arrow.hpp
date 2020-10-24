#pragma once
#include "Axis.hpp"

namespace du {
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
    static Vec2 clamped(const Vec2& vec) {
        return Vec2(
            std::clamp<float>(vec.x, -1, 1),
            std::clamp<float>(vec.y, -1, 1));
    }
public: // public function
    Vec2 key(GPArrow arrow) const override {
        switch (arrow) {
        case GPArrow::L: {
            return clamped(m_axis.keyL() + m_dpad.vec());
        }
        case GPArrow::R: {
            return clamped(m_axis.keyR() + dx::misc::boolToVec2(
                m_buttons.keyA().pressed(), m_buttons.keyY().pressed(),
                m_buttons.keyB().pressed(), m_buttons.keyX().pressed()));
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
