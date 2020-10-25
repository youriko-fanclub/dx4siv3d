#pragma once
#include <Siv3D/Key.hpp>
#include <Siv3D/JoyCon.hpp>
#include "KeyCode.hpp"

namespace dx {
namespace di {

enum class GamePadId;
enum class GPButton;
enum class GPDPad;
enum class JoyConLR {
    None, L, R
};

class KeyMapping {
public: // static_const/enum
public: // static
    static KeyCode get(const GamePadId& gpid, const GPButton& gp_button);
    static KeyCode get(const GamePadId& gpid, const GPDPad& gp_dpad_button);
    
    static KeyCodeOfJoyCon getJoyCon(const GamePadId& gpid, const GPButton& gp_button);
    static KeyCodeOfJoyCon getJoyCon(const GamePadId& gpid, const GPDPad& gp_dpad_button);
    
    static s3d::JoyCon getJoyCon(const GamePadId& gpid);
    static JoyConLR getJoyConLR(const GamePadId& gpid);
private:
public: // public function
private: // field
private: // private function
public: // ctor/dtor
};


}
}
