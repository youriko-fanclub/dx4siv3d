#include "InputDemoScene.hpp"

namespace dx {
namespace di {

/* ---------- SampleGamePadDemo ---------- */

// static ----------------------------------------
// public function -------------------------------
void SampleGamePadDemo::update() {}
void SampleGamePadDemo::draw() const {
    // Circle(m_center, m_scale / 2).drawFrame(m_scale * 0.1);
    const ColorF base_color(0.86, 0.47, 0.35);
    const ColorF button_color(0.3, 0.3, 0.3);
    const ColorF button_pressed_color(0.96, 0.82, 0.57);
    // ベース
    RoundRect(Arg::center(m_center), Size(25, 15) * m_scale, m_scale).draw(base_color);
    // ABXY
    Circle(m_center + Vec2(8 + 2, 0    ) * m_scale, 1 * m_scale).draw(button_color);
    Circle(m_center + Vec2(8    , 0 - 2) * m_scale, 1 * m_scale).draw(button_color);
    Circle(m_center + Vec2(8    , 0 + 2) * m_scale, 1 * m_scale).draw(button_color);
    Circle(m_center + Vec2(8 - 2, 0    ) * m_scale, 1 * m_scale).draw(button_color);
    // 十字ボタン
    RectF(Arg::center(m_center + Vec2(-8 - 2, 0    ) * m_scale), 1.8 * m_scale).draw(button_color);
    RectF(Arg::center(m_center + Vec2(-8 + 2, 0    ) * m_scale), 1.8 * m_scale).draw(button_color);
    RectF(Arg::center(m_center + Vec2(-8    , 0 - 2) * m_scale), 1.8 * m_scale).draw(button_color);
    RectF(Arg::center(m_center + Vec2(-8    , 0 + 2) * m_scale), 1.8 * m_scale).draw(button_color);
    // スティック
    Circle(m_center + Vec2(-4, 4.5) * m_scale, 2 * m_scale).draw(button_color);
    Circle(m_center + Vec2( 4, 4.5) * m_scale, 2 * m_scale).draw(button_color);
    Circle(m_center + Vec2(-4, 4.5) * m_scale, 0.5 * m_scale).draw(button_pressed_color);
    Circle(m_center + Vec2( 4, 4.5) * m_scale, 0.5 * m_scale).draw(button_pressed_color);
    // L/R
    RoundRect(Arg::center(m_center + Vec2(-8, -4.5) * m_scale), SizeF(4, 1) * m_scale, 0.2 * m_scale).draw(button_color);
    RoundRect(Arg::center(m_center + Vec2( 8, -4.5) * m_scale), SizeF(4, 1) * m_scale, 0.2 * m_scale).draw(button_color);
    RoundRect(Arg::center(m_center + Vec2(-8, -6) * m_scale), SizeF(4, 1) * m_scale, 0.2 * m_scale).draw(button_color);
    RoundRect(Arg::center(m_center + Vec2( 8, -6) * m_scale), SizeF(4, 1) * m_scale, 0.2 * m_scale).draw(button_color);
    // Start/Select
    RoundRect(Arg::center(m_center + Vec2(-1.7, 1.5) * m_scale), SizeF(2, 0.8) * m_scale, 0.2 * m_scale).draw(button_color);
    RoundRect(Arg::center(m_center + Vec2( 1.7, 1.5) * m_scale), SizeF(2, 0.8) * m_scale, 0.2 * m_scale).draw(button_color);

}

// private function ------------------------------
// ctor/dtor -------------------------------------
SampleGamePadDemo::SampleGamePadDemo(const Vec2& center, double scale) :
    m_center(center),
    m_scale(scale) {}


/* ---------- JoyConDemo ---------- */

// static ----------------------------------------
// public function -------------------------------
void JoyConDemo::update() {
    for (const auto& joy : { JoyConL(0), JoyConR(0) }) {
        if (!joy) { continue; }
        if (auto d = joy.povD8()) {
            m_left += Circular(4, *d * 45_deg);
        }
    }

    SimpleGUI::Slider(U"Rotation: ", m_angle, -180_deg, 180_deg, Vec2(20, 20), 120, 200);
    SimpleGUI::Slider(U"Scale: ", m_scale, 100.0, 600.0, Vec2(20, 60), 120, 200);
    SimpleGUI::CheckBox(m_covered, U"Covered", Vec2(20, 100));
}

void JoyConDemo::draw() const {
    const Vec2 centerL(640 - 300, 450);
    const Vec2 centerR(640 + 300, 450);
    Circle(centerL, m_scale / 2).drawFrame(m_scale * 0.1);
    Circle(centerR, m_scale / 2).drawFrame(m_scale * 0.1);
    
    if (const auto joy = JoyConL(0)) {
        joy.drawAt(centerL, m_scale, -90_deg - m_angle, m_covered);
        if (joy.button2.down()) {
            m_effect.add([center = m_left](double t) {
                Circle(center, 20 + t * 200).drawFrame(10, 0, AlphaF(1.0 - t));
                return t < 1.0;
            });
        }
    }
    
    if (const auto joy = JoyConR(0)) {
        joy.drawAt(centerR, m_scale, 90_deg + m_angle, m_covered);
        if (joy.button2.down()) {
            m_effect.add([center = m_right](double t) {
                Circle(center, 20 + t * 200).drawFrame(10, 0, AlphaF(1.0 - t));
                return t < 1.0;
            });
        }
    }
    
    Circle(m_left, 30).draw(ColorF(0.0, 0.75, 0.9));
    Circle(m_right, 30).draw(ColorF(1.0, 0.4, 0.3));
    m_effect.update();
}

// private function ------------------------------

// ctor/dtor -------------------------------------
JoyConDemo::JoyConDemo() :
    m_left(640 - 100, 100),
    m_right(640 + 100, 100),
    m_angle(0_deg),
    m_scale(400.0),
    m_covered(true) {}


/* ---------- InputDemoScene ---------- */

// static ----------------------------------------
// public function -------------------------------
void InputDemoScene::update() {
    m_gamepad_demo.update();
    // m_joyConDemo.update();
}

void InputDemoScene::draw() const {
    m_gamepad_demo.draw();
    m_gamepad_demo_s.draw();
    // m_joyConDemo.draw();
}

// private function ------------------------------
// ctor/dtor -------------------------------------
InputDemoScene::InputDemoScene(const InitData& init) :
    IScene(init),
    m_gamepad_demo(Vec2(400, 300), 20.0),
    m_gamepad_demo_s(Vec2(500, 600), 8.0),
    m_joyConDemo() {}


}
}
