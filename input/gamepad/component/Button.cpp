#include "Button.hpp"
#include "KeyMapping.hpp"

namespace dx {
namespace di {

bool ButtonsFromKeyboard::get(GPButton button) const {
    if (KeyCode code = KeyMapping::get(m_gpid, button); code != KeyCode::None) {
        return isState(keyFromCode(code), m_state);
    }
    return false;
}

s3d::Duration ButtonsFromKeyboard::pressedDuration(GPButton button) const {
    if (KeyCode code = KeyMapping::get(m_gpid, button); code != KeyCode::None) {
        return keyFromCode(code).pressedDuration();
    }
    return s3d::Duration(0);
}


bool ButtonsFromJoyCon::get(GPButton button) const {
    if (KeyCodeOfJoyCon code = KeyMapping::getJoyCon(m_gpid, button); code != KeyCodeOfJoyCon::None) {
        if (const auto joy = KeyMapping::getJoyCon(m_gpid)) {
            return isState(keyFromCodeAtHorizontally(joy, code), m_state);
        }
    }
    return false;
}

s3d::Duration ButtonsFromJoyCon::pressedDuration(GPButton button) const {
    if (KeyCodeOfJoyCon code = KeyMapping::getJoyCon(m_gpid, button); code != KeyCodeOfJoyCon::None) {
        if (const auto joy = KeyMapping::getJoyCon(m_gpid)) {
            return keyFromCodeAtHorizontally(joy, code).pressedDuration();
        }
    }
    return s3d::Duration(0);
}


bool ButtonsFromMultiSource::get(GPButton button) const {
    return std::any_of(m_buttons_list.begin(), m_buttons_list.end(),
        [button](const auto& buttons){ return buttons->get(button); });
}

s3d::Duration ButtonsFromMultiSource::pressedDuration(GPButton button) const {
    s3d::Duration duration(0);
    for (const auto& buttons : m_buttons_list) {
        const auto& d = buttons->pressedDuration(button);
        if (duration < d) {
            duration = d;
        }
    }
    return duration;
}


bool IButton::down   () const { return m_parent->down   (m_button); }
bool IButton::pressed() const { return m_parent->pressed(m_button); }
bool IButton::up     () const { return m_parent->up     (m_button); }
s3d::Duration IButton::pressedDuration() const {
    return m_parent->pressedDuration(m_button);
}


Buttons::Buttons(GamePadId gpid) :
    m_down   ({ std::make_shared<ButtonsFromKeyboard>(gpid, KeyState::Down   ),
                std::make_shared<ButtonsFromJoyCon  >(gpid, KeyState::Down   ) }),
    m_pressed({ std::make_shared<ButtonsFromKeyboard>(gpid, KeyState::Pressed),
                std::make_shared<ButtonsFromJoyCon  >(gpid, KeyState::Pressed) }),
    m_up     ({ std::make_shared<ButtonsFromKeyboard>(gpid, KeyState::Up     ),
                std::make_shared<ButtonsFromJoyCon  >(gpid, KeyState::Up     ) }) {}

}
}
