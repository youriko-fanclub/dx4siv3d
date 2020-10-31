#include "DPad.hpp"
#include "KeyMapping.hpp"
#include "Misc.hpp"
#include "Input.hpp"

namespace dx {
namespace di {

s3d::Vec2 AbsDPad::vec() const {
    return dx::misc::boolToVec2(right(), left(), down(), up());
}

bool DPadFromKeyboard::get(GPDPad button) const {
    if (KeyCode code = KeyMapping::get(m_gpid, button); code != KeyCode::None) {
        return isState(keyFromCode(code), m_state);
    }
    return false;
}

s3d::Duration DPadFromKeyboard::pressedDuration(GPDPad button) const {
    if (KeyCode code = KeyMapping::get(m_gpid, button); code != KeyCode::None) {
        return keyFromCode(code).pressedDuration();
    }
    return s3d::Duration(0);
}

bool DPadFromJoyCon::get(GPDPad button) const {
    if (Input::instance()->source(m_gpid) == InputSource::JoyConHorizontally) {
        return false;
    }
#ifdef UNDER_CONSTRUCTION // TOdO: 横持ちなら常にfalse
    if (KeyCodeOfJoyCon code = KeyMapping::getJoyCon(m_gpid, button); code != KeyCodeOfJoyCon::None) {
        const auto joy_l = s3d::JoyConL(0);
        const auto joy_r = s3d::JoyConR(0);
        if (joy_l && joy_r) { // TOdO:
            return isState(keyFromCodeAtFrontally(joy_l, joy_r, code), m_state);
        }
    }
#endif
    return false;
}

s3d::Duration DPadFromJoyCon::pressedDuration(GPDPad button) const {
    if (Input::instance()->source(m_gpid) == InputSource::JoyConHorizontally) {
        return s3d::Duration(0);
    }
    return s3d::Duration(0); // TOdO:
}


bool DPadFromMultiSource::get(GPDPad button) const {
    return std::any_of(m_dpad_list.begin(), m_dpad_list.end(),
        [button](const auto& dpad){ return dpad->get(button); });
}

s3d::Duration DPadFromMultiSource::pressedDuration(GPDPad button) const {
    s3d::Duration duration(0);
    for (const auto& dpad : m_dpad_list) {
        const auto& d = dpad->pressedDuration(button);
        if (duration < d) {
            duration = d;
        }
    }
    return duration;
}


bool IDPadButton::down   () const { return m_parent->down   (m_button); }
bool IDPadButton::pressed() const { return m_parent->pressed(m_button); }
bool IDPadButton::up     () const { return m_parent->up     (m_button); }
s3d::Duration IDPadButton::pressedDuration() const {
    return m_parent->pressedDuration(m_button);
}

s3d::Duration DPad::pressedDuration(GPDPad button) const {
    return m_pressed.pressedDuration(button);
}

s3d::Vec2 DPad::vec() const { return m_pressed.vec(); }

DPad::DPad(GamePadId gpid) :
    m_down   ({ std::make_shared<DPadFromKeyboard>(gpid, KeyState::Down   ),
                std::make_shared<DPadFromJoyCon  >(gpid, KeyState::Down   ) }),
    m_pressed({ std::make_shared<DPadFromKeyboard>(gpid, KeyState::Pressed),
                std::make_shared<DPadFromJoyCon  >(gpid, KeyState::Pressed) }),
    m_up     ({ std::make_shared<DPadFromKeyboard>(gpid, KeyState::Up     ),
                std::make_shared<DPadFromJoyCon  >(gpid, KeyState::Up     ) }) {}

}
}
