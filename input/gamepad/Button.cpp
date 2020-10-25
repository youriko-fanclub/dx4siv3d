#include "Button.hpp"
#include "KeyMapping.hpp"

namespace dx {
namespace di {

bool ButtonsFromKeyboard::key(GPButton button) const {
    if (KeyCode code = KeyMapping::get(m_gpId, button); code != KeyCode::None) {
        return isState(keyFromCode(code), m_state);
    }
    else {
        return false;
    }
}

}
}
