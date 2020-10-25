#pragma once
#include <algorithm>
#include "Button.hpp"
#include "DPad.hpp"
#include "Axis.hpp"
#include "Arrow.hpp"

using PlayerID = int;//du.di.Id.Player;

namespace dx {
namespace di {


/// <summary> プレイヤー入力 </summary>
class IPlayerInput {
public: // getter
    virtual const Buttons& buttons() const = 0;
    virtual const IArrows& arrow  () const = 0;
    virtual const DPad   & dpad   () const = 0;
    virtual const IAxis  & axis   () const = 0;
};

/// <summary> プレイヤー入力 </summary>
class PlayerInput : public IPlayerInput {
public: // getter
    const Buttons& buttons() const override { return m_buttons; }
    const IArrows& arrow  () const override { return *m_arrow ; }
    const DPad   & dpad   () const override { return m_dpad   ; }
    const IAxis  & axis   () const override { return m_axis   ; }
    s3d::Vec2 arrowL() const { return (m_dpad.vec() + m_axis.l()).clampLength(1.f); }
    s3d::Vec2 arrowR() const { return m_axis.r(); }
private: // field
    const Buttons m_buttons;
    // const ButtonsFromJoyCon m_buttons;
    // const DPadFromKeyboard m_dpad;
    const DPad m_dpad;
    const AxisFromMultiSource m_axis;
    std::shared_ptr<ArrowFromKeyboard> m_arrow = nullptr;
public: // ctor/dtor
    PlayerInput() :
        m_buttons(),
        m_dpad(),
        m_axis({ std::make_shared<AxisFromKeyboard>(GamePadId::_1P),
                 std::make_shared<AxisFromJoyCon  >(GamePadId::_1P), }) {
        m_arrow = std::make_shared<ArrowFromKeyboard>(&m_buttons, &m_dpad, &m_axis);
    } // TOdO:
};

}
}

