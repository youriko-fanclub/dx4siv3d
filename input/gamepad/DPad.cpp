#include "DPad.hpp"
#include "KeyMapping.hpp"
#include "Misc.hpp"

namespace dx {
namespace di {

s3d::Vec2 IDPad::vec() const {
    return dx::misc::boolToVec2(right(), left(), down(), up());
}

bool DPadFromKeyboard::key(GPDPad button) const {
    if (KeyCode code = KeyMapping::get(m_gpId, button); code != KeyCode::None) {
        return isState(keyFromCode(code), m_state);
    }
    return false;
}

bool DPadFromJoyCon::key(GPDPad button) const {
#ifdef UNDER_CONSTRUCTION // TOdO: 横持ちなら常にfalse
    if (KeyCodeOfJoyCon code = KeyMapping::getJoyCon(m_gpId, button); code != KeyCodeOfJoyCon::None) {
        const auto joy_l = s3d::JoyConL(0);
        const auto joy_r = s3d::JoyConR(0);
        if (joy_l && joy_r) { // TOdO:
            return isState(keyFromCodeAtFrontally(joy_l, joy_r, code), m_state);
        }
    }
#endif
    return false;
}

bool DPadFromMultiSource::key(GPDPad button) const {
    return std::any_of(m_dpad_list.begin(), m_dpad_list.end(),
        [button](const auto& dpad){ return dpad->key(button); });
}


s3d::Duration DPad::pressedDuration() const { return s3d::Duration(0); } // TOdO:
s3d::Vec2 DPad::vec() const { return m_pressed.vec(); }

DPad::DPad() :
    m_down   ({ std::make_shared<DPadFromKeyboard>(GamePadId::_1P, KeyState::Down   ),
                std::make_shared<DPadFromJoyCon  >(GamePadId::_1P, KeyState::Down   ) }),
    m_pressed({ std::make_shared<DPadFromKeyboard>(GamePadId::_1P, KeyState::Pressed),
                std::make_shared<DPadFromJoyCon  >(GamePadId::_1P, KeyState::Pressed) }),
    m_up     ({ std::make_shared<DPadFromKeyboard>(GamePadId::_1P, KeyState::Up     ),
                std::make_shared<DPadFromJoyCon  >(GamePadId::_1P, KeyState::Up     ) }) {}

}
}
