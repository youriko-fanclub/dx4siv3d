#include "KeyMapping.hpp"
#include "PlayerId.hpp"
#include "Button.hpp"
#include "DPad.hpp"

namespace dx {
namespace di {

KeyCode KeyMapping::get(const GamePadId& gpid, const GPButton& gp_button) {
    switch (gpid) {
    case GamePadId::_1P: {
        switch (gp_button) {
        case GPButton::A: return KeyCode::L;
        case GPButton::B: return KeyCode::K;
        case GPButton::X: return KeyCode::I;
        case GPButton::Y: return KeyCode::J;
        default         : return KeyCode::None;
        }
    } break;
    default: return KeyCode::None;
    }
}

KeyCode KeyMapping::get(const GamePadId& gpid, const GPDPad& gp_dpad_button) {
    switch (gpid) {
    case GamePadId::_1P: {
        switch (gp_dpad_button) {
        case GPDPad::Left : return KeyCode::S;
        case GPDPad::Right: return KeyCode::F;
        case GPDPad::Up   : return KeyCode::E;
        case GPDPad::Down : return KeyCode::D;
        default           : return KeyCode::None;
        }
    } break;
    default: return KeyCode::None;
    }
}

}
}
