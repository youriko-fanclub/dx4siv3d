#include "KeyMapping.hpp"
#include <Siv3D/JoyCon.hpp>
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

KeyCodeOfJoyCon KeyMapping::getJoyCon(const GamePadId& gpid, const GPButton& gp_button) {
    switch (gpid) {
    case GamePadId::_1P: {
        switch (gp_button) {
        case GPButton::A: return KeyCodeOfJoyCon::A;
        case GPButton::B: return KeyCodeOfJoyCon::B;
        case GPButton::X: return KeyCodeOfJoyCon::X;
        case GPButton::Y: return KeyCodeOfJoyCon::Y;
        case GPButton::L1: return KeyCodeOfJoyCon::SL;
        case GPButton::R1: return KeyCodeOfJoyCon::SR;
        case GPButton::Start: return KeyCodeOfJoyCon::Minus;
        default         : return KeyCodeOfJoyCon::None;
        }
    } break;
    default: return KeyCodeOfJoyCon::None;
    }
}

KeyCodeOfJoyCon KeyMapping::getJoyCon(const GamePadId& gpid, const GPDPad& gp_dpad_button) {
    switch (gpid) {
    case GamePadId::_1P: {
        switch (gp_dpad_button) {
        case GPDPad::Left : return KeyCodeOfJoyCon::Left ;
        case GPDPad::Right: return KeyCodeOfJoyCon::Right;
        case GPDPad::Up   : return KeyCodeOfJoyCon::Up   ;
        case GPDPad::Down : return KeyCodeOfJoyCon::Down ;
        default           : return KeyCodeOfJoyCon::None;
        }
    } break;
    default: return KeyCodeOfJoyCon::None;
    }
}

}
}
