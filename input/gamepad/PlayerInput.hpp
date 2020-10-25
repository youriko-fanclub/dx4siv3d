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
    const Buttons& buttons() const override { return m_buttons; }
    const IArrow & arrow  () const override { return m_arrow  ; }
    const IDPad  & dpad   () const override { return m_dpad   ; }
    const IAxis  & axis   () const override { return m_axis   ; }
private: // field
    const Buttons m_buttons;
    // const ButtonsFromJoyCon m_buttons;
    // const DPadFromKeyboard m_dpad;
    const DPadFromJoyCon m_dpad;
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

