#include "Button.hpp"
#include "KeyMapping.hpp"

namespace dx {
namespace di {

bool ButtonsFromKeyboard::key(GPButton button) const {
    return isState(keyFromCode(KeyMapping::get(m_gpId, button)), m_state);
}

}
}
