#pragma once
#include "Button.hpp"
#include "DPad.hpp"
#include "Axis.hpp"

namespace dx {
namespace di {


/// <summary> プレイヤー入力 </summary>
class IPlayerInput {
public: // getter
    virtual const Buttons& buttons() const = 0;
    virtual const DPad   & dpad   () const = 0;
    virtual const IAxis  & axis   () const = 0;
    virtual s3d::Vec2 arrowL() const = 0;
    virtual s3d::Vec2 arrowR() const = 0;
};

/// <summary> プレイヤー入力 </summary>
class PlayerInput : public IPlayerInput {
public: // getter
    const Buttons& buttons() const override { return m_buttons; }
    const DPad   & dpad   () const override { return m_dpad   ; }
    const IAxis  & axis   () const override { return m_axis   ; }
    s3d::Vec2 arrowL() const override { return (m_dpad.vec() + m_axis.l()).clampLength(1.f); }
    s3d::Vec2 arrowR() const override { return m_axis.r(); }
private: // field
    const Buttons m_buttons;
    const DPad m_dpad;
    const AxisFromMultiSource m_axis;
public: // ctor/dtor
    PlayerInput() :
        m_buttons(),
        m_dpad(),
        m_axis({ std::make_shared<AxisFromKeyboard>(GamePadId::_1P),
                 std::make_shared<AxisFromJoyCon  >(GamePadId::_1P), }) {} // TOdO:
};

}
}

