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
    using Code = KeyCodeOfJoyCon;
    bool is_horizontally = true; // TOdO:
    switch (gp_button) {
    case GPButton::A: return Code::A;
    case GPButton::B: return Code::B;
    case GPButton::X: return Code::X;
    case GPButton::Y: return Code::Y;
    case GPButton::L1: return is_horizontally ? Code::SL : Code::L;
    case GPButton::R1: return is_horizontally ? Code::SR : Code::R;
    case GPButton::Start:
        switch (getJoyConLR(gpid)) {
        case JoyConLR::L: return Code::Minus;
        case JoyConLR::R: return Code::Plus;
        case JoyConLR::None: return Code::None;
        }
    default: return Code::None;
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

s3d::JoyCon KeyMapping::getJoyCon(const GamePadId& gpid) {
    switch (gpid) {
    case GamePadId::_1P: return s3d::JoyConL(0);
    case GamePadId::_2P: return s3d::JoyConR(0);
    case GamePadId::_3P: return s3d::JoyConL(1);
    case GamePadId::_4P: return s3d::JoyConR(1);
    }
}

JoyConLR KeyMapping::getJoyConLR(const GamePadId& gpid) {
    switch (gpid) {
    case GamePadId::_1P:
    case GamePadId::_3P: return JoyConLR::L;
    case GamePadId::_2P:
    case GamePadId::_4P: return JoyConLR::R;
    default            : return JoyConLR::None;
    }
}
}
}
