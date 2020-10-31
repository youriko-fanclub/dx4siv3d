#pragma once
#include "SceneStates.hpp"
#include "PlayerInput.hpp"
#include "GamePadDemo.hpp"
#include "JoyConDemo.hpp"

namespace dx {
namespace di {

// di デモ用
class InputDemoScene : public kanji::seq::KanjiScene {
public: // static_const/enum
    enum class Layout : int {
        Square, Horizontal, Vertical
    };
public: // static
public: // public function
    void update() override;
    void draw() const override;
private: // field
    float m_scale;
    Layout m_layout;
    std::unordered_map<GamePadId, GamePadDemo> m_gamepad_demos;
    JoyConDemo m_joyConDemo;
private: // private function
public: // ctor/dtor
    InputDemoScene(const InitData& init);
    
};

}
}
