#include "KeyMapping.hpp"
#include "PlayerId.hpp"
#include "Button.hpp"

namespace dx {
namespace di {

KeyCode KeyMapping::get(const GamePadId& gpId, const GPButton& gpButton) {
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

}
}
