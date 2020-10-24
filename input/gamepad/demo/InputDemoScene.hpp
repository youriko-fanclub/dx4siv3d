#pragma once
#include "SceneStates.hpp"
#include "PlayerInput.hpp"

namespace dx {
namespace di {

class SampleGamePadDemo {
public: // static_const/enum
public: // static
public: // public function
    void update();
    void draw() const;
private: // field
    const PlayerInputFromKeyboard m_input;
    Vec2 m_center;
    double m_scale;
private: // private function
public: // ctor/dtor
    SampleGamePadDemo(const PlayerInputFromKeyboard input, const Vec2& center, double scale);
};

class JoyConDemo {
public: // static_const/enum
public: // static
public: // public function
    void update();
    void draw() const;
private: // field
    Effect m_effect;
    Vec2 m_left, m_right;
    double m_angle;
    double m_scale;
    bool m_covered;
private: // private function
public: // ctor/dtor
    JoyConDemo();
};

// di デモ用
class InputDemoScene : public kanji::seq::KanjiScene {
public: // static_const/enum
public: // static
public: // public function
    void update() override;
    void draw() const override;
private: // field
    SampleGamePadDemo m_gamepad_demo;
    SampleGamePadDemo m_gamepad_demo_s;
    JoyConDemo m_joyConDemo;
private: // private function
public: // ctor/dtor
    InputDemoScene(const InitData& init);
    
};

}
}
