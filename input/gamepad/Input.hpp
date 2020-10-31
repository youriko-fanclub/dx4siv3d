#pragma once
#include "Singleton.hpp"
#include "PlayerId.hpp"
#include "PlayerInput.hpp"

namespace dx {
namespace di {

enum class InputSource : int {
    Keyboard, JoyConFrontally, JoyConHorizontally
};

class Input final : public cmp::Singleton<Input> {
public: // static_const/enum
    static const PlayerInput& get(GamePadId gpid) { return instance()->getImpl(gpid); }
public: // static
public: // public function
    void initialize();
    const PlayerInput& getImpl(GamePadId gpid) const { return m_inputs.at(gpid); }
    InputSource source(GamePadId gpid) const { return m_sources.at(gpid); }
private: // field
private: // private function
    std::unordered_map<GamePadId, PlayerInput> m_inputs;
    std::unordered_map<GamePadId, InputSource> m_sources;
public: // ctor/dtor
    Input();
};

}
}