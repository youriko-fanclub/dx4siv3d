#pragma once
#include "PlayerId.hpp"
#include "KeyCode.hpp"
#include "Button.hpp"

namespace dx {
namespace di {

class KeyMapping {
public: // static_const/enum
public: // static
    KeyCode get(GamePadId gpId, GPButton gpButton) {
        switch (gpId) {
        case GamePadId::_1P: {
            switch (gpButton) {
            case GPButton::A: return KeyCode::L;
            case GPButton::B: return KeyCode::K;
            case GPButton::X: return KeyCode::I;
            case GPButton::Y: return KeyCode::J;
            default:          return KeyCode::None;
            }
        } break;
        default: return KeyCode::None;
        }
    }
private:
public: // public function
private: // field
private: // private function
public: // ctor/dtor
};


}
}
