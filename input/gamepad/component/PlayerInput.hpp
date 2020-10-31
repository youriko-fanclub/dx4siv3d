#pragma once
#include "Button.hpp"
#include "DPad.hpp"
#include "Axis.hpp"

namespace dx {
namespace di {


/// <summary> プレイヤー入力 </summary>
class IPlayerInput {
public: // getter
    virtual const IButtons& buttons() const = 0;
    virtual const IDPad   & dpad   () const = 0;
    virtual const IAxis   & axis   () const = 0;
    virtual s3d::Vec2 arrowL() const = 0;
    virtual s3d::Vec2 arrowR() const = 0;
    
    virtual IButton button(GPButton button) const = 0;
    virtual IDPadButton dpad(GPDPad button) const = 0;
    virtual s3d::Vec2 axis(GPAxis axis) const = 0;
};

/// <summary> プレイヤー入力 </summary>
class PlayerInput : public IPlayerInput {
public: // getter
    const IButtons& buttons() const override { return m_buttons; }
    const IDPad   & dpad   () const override { return m_dpad   ; }
    const IAxis   & axis   () const override { return m_axis   ; }
    s3d::Vec2 arrowL() const override { return (m_dpad.vec() + m_axis.l()).clampLength(1.f); }
    s3d::Vec2 arrowR() const override { return m_axis.r(); }
    
    IButton button(GPButton button) const override { return m_buttons.get(button); }
    IDPadButton dpad(GPDPad button) const override { return m_dpad.get(button); }
    s3d::Vec2 axis(GPAxis axis) const override { return m_axis.vec(axis); }
private: // field
    const Buttons m_buttons;
    const DPad m_dpad;
    const AxisFromMultiSource m_axis;
public: // ctor/dtor
    PlayerInput(GamePadId gpid) :
        m_buttons(gpid),
        m_dpad(gpid),
        m_axis({ std::make_shared<AxisFromKeyboard>(gpid),
                 std::make_shared<AxisFromJoyCon  >(gpid), }) {}
};

}
}

