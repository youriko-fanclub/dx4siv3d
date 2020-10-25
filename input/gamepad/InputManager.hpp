#pragma once
#include "Singleton.hpp"
#include "PlayerId.hpp"
#include "PlayerInput.hpp"

namespace dx {
namespace di {

class InputManager final : public cmp::Singleton<InputManager> {
public: // static_const/enum
public: // static
public: // public function
    void initialize();
    const PlayerInput& get(GamePadId gpid) const { return m_inputs.at(gpid); }
private: // field
private: // private function
    std::unordered_map<GamePadId, PlayerInput> m_inputs;
public: // ctor/dtor
    InputManager();
};

inline const PlayerInput& in(GamePadId gpid) {
    return InputManager::instance()->get(gpid);
}

}
}
