#include "DPad.hpp"
#include "KeyMapping.hpp"

namespace dx {
namespace di {

bool DPadFromKeyboard::key(GPDPad button) const {
    return isState(keyFromCode(KeyMapping::get(m_gpId, button)), m_state);
}

}
}
