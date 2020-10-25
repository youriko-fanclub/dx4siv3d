#include "InputManager.hpp"

namespace dx {
namespace di {

/* ---------- InputManager ---------- */

// static ----------------------------------------
// public function -------------------------------
void initialize();
// private function ------------------------------
// ctor/dtor -------------------------------------
InputManager::InputManager() {
    for (auto id : elems<GamePadId>()) {
        m_inputs.insert(std::make_pair(id, PlayerInput(id)));
    }
    // TOdO:
    m_sources.insert(std::make_pair(GamePadId::_1P, InputSource::JoyConHorizontally));
    m_sources.insert(std::make_pair(GamePadId::_2P, InputSource::JoyConHorizontally));
    m_sources.insert(std::make_pair(GamePadId::_3P, InputSource::JoyConHorizontally));
    m_sources.insert(std::make_pair(GamePadId::_4P, InputSource::JoyConHorizontally));
}


}
}
