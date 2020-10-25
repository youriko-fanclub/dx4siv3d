#pragma once
#include "KeyCode.hpp"

namespace dx {
namespace di {

enum class GamePadId;
enum class GPButton;

class KeyMapping {
public: // static_const/enum
public: // static
    static KeyCode get(const GamePadId& gpId, const GPButton& gpButton);
private:
public: // public function
private: // field
private: // private function
public: // ctor/dtor
};


}
}
