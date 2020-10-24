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
    virtual const IButtons& buttons() const = 0;
    virtual const IArrow  & arrow  () const = 0;
    virtual const IDPad   & dpad   () const = 0;
    virtual const IAxis   & axis   () const = 0;
};

/// <summary> プレイヤー入力 </summary>
class PlayerInput : public IPlayerInput {
private:
    PlayerID m_playerId;
public:
    PlayerInput(PlayerID plID) : m_playerId(plID) {}
};

/// <summary> プレイヤー入力 </summary>
class PlayerInputFromKeyboard : public PlayerInput {
public: // getter
    const IButtons& buttons() const override { return m_buttons; }
    const IArrow  & arrow  () const override { return m_arrow  ; }
    const IDPad   & dpad   () const override { return m_dpad   ; }
    const IAxis   & axis   () const override { return m_axis   ; }
    // const IAxis& axisL() const override { return axis(GPAxis::L); }
    // const IAxis& axisR() const override { return axis(GPAxis::R); }
private: // field
    const ButtonsFromKeyboard m_buttons;
    const DPadFromKeyboard m_dpad;
    const AxisFromKeyboard m_axis;
    const ArrowFromKeyboard m_arrow;
public: // ctor/dtor
    PlayerInputFromKeyboard() :
        PlayerInput(0),
        m_buttons(),
        m_dpad(),
        m_axis(),
        m_arrow(m_buttons, m_dpad, m_axis)
         {} // TOdO:
};

}
}

