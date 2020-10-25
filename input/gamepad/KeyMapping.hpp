#pragma once
#include "KeyCode.hpp"

namespace dx {
namespace di {

enum class GamePadId;
enum class GPButton;
enum class GPDPad;

class KeyMapping {
public: // static_const/enum
public: // static
    static KeyCode get(const GamePadId& gpId, const GPButton& gp_button);
    static KeyCode get(const GamePadId& gpId, const GPDPad& gp_dpad_button);
private:
public: // public function
private: // field
private: // private function
public: // ctor/dtor
};


}
}
