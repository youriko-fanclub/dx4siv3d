#include "Button.hpp"
#include "KeyMapping.hpp"

namespace dx {
namespace di {

bool ButtonsFromKeyboard::key(GPButton button) const {
    if (KeyCode code = KeyMapping::get(m_gpId, button); code != KeyCode::None) {
        return isState(keyFromCode(code), m_state);
    }
    return false;
}

bool ButtonsFromJoyCon::key(GPButton button) const {
    if (KeyCodeOfJoyCon code = KeyMapping::getJoyCon(m_gpId, button); code != KeyCodeOfJoyCon::None) {
        if (const auto joy = s3d::JoyConL(0)) { // TOdO:
            return isState(keyFromCodeAtHorizontally(joy, code), m_state);
        }
    }
    return false;
}

bool ButtonsFromMultiDevice::key(GPButton button) const {
    return std::any_of(m_buttons_list.begin(), m_buttons_list.end(),
        [button](const auto& buttons){ return buttons->key(button); });
}

}
}
