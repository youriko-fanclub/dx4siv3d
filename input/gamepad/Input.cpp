#include "Input.hpp"

namespace dx {
namespace di {

/* ---------- InputManager ---------- */

// static ----------------------------------------
// public function -------------------------------
void initialize();
// private function ------------------------------
// ctor/dtor -------------------------------------
Input::Input() {
    for (auto id : denum::elems<GamePadId>()) {
        m_inputs.emplace(id, PlayerInput(id));
    }
    // TOdO:
    m_sources.emplace(GamePadId::_1P, InputSource::JoyConFrontally);
    m_sources.emplace(GamePadId::_2P, InputSource::JoyConHorizontally);
    m_sources.emplace(GamePadId::_3P, InputSource::JoyConHorizontally);
    m_sources.emplace(GamePadId::_4P, InputSource::JoyConHorizontally);
}


}
}
