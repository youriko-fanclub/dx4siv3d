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
}


}
}
