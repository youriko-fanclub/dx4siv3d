#pragma once
#include "SceneStates.hpp"
#include "PlayerInput.hpp"

namespace dx {
namespace di {

class SampleGamePadDemo {
public: // static_const/enum
public: // static
public: // public function
    void setCenter(float x, float y) { m_center.set(x, y);}
    void setCenter(const Vec2& center) { m_center = center;}
    void update();
    void draw() const;
private: // field
    GamePadId m_gpid;
    Vec2 m_center;
    double m_scale;
    
    const ColorF m_base_color;
    const ColorF m_button_color;
    const ColorF m_button_pressed_color;
    const ColorF m_arrow_color;

private: // private function
    void drawABXY() const;
    void drawLR() const;
    void drawStartSelect() const;
    void drawDPad() const;
    void drawAxis() const;
    void drawId() const;
    const ColorF& buttonColor(bool is_pressed) const;
    ColorF buttonColor(s3d::Duration duration) const;
public: // ctor/dtor
    SampleGamePadDemo(GamePadId id, const Vec2& center, double scale, const ColorF& base, const ColorF& button, const ColorF& pressed, const ColorF& arrow);
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
    std::unordered_map<GamePadId, SampleGamePadDemo> m_gamepad_demos;
    JoyConDemo m_joyConDemo;
private: // private function
public: // ctor/dtor
    InputDemoScene(const InitData& init);
    
};

}
}
