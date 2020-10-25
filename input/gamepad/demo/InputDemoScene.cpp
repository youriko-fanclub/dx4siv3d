#include "InputDemoScene.hpp"
#include "InputManager.hpp"

namespace {

const ColorF& buttonColor(bool is_pressed) {
    static constexpr ColorF button_color(0.3, 0.3, 0.3);
    static constexpr ColorF button_pressed_color(0.96, 0.82, 0.57);
    return is_pressed ? button_pressed_color : button_color;
}
ColorF buttonColor(s3d::Duration duration) {
    constexpr s3d::Duration max(3);
    const float factor = (1.f - duration / max);
    return ColorF(0.96, 0.82 * factor, 0.57 * factor);
}

}

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
    const ColorF arrow_color(1.0, 0.3, 0.3);
    const auto& input = in(m_gpid);
    // ベース
    RoundRect(Arg::center(m_center), Size(25, 15) * m_scale, m_scale).draw(base_color);
    // ABXY
    const auto& button = input.buttons().pressed();
    const bool a = button.a(), b = button.b(), x = button.x(), y = button.y();
    Circle circle(m_center + Vec2(8, 0) * m_scale, 1 * m_scale);
    circle.movedBy(Vec2( 2,  0) * m_scale).draw(buttonColor(a));
    circle.movedBy(Vec2( 0,  2) * m_scale).draw(buttonColor(b));
    circle.movedBy(Vec2( 0, -2) * m_scale).draw(buttonColor(x));
    circle.movedBy(Vec2(-2,  0) * m_scale).draw(buttonColor(y));
    Circle circleIn(circle.scaled(0.5));
    if (a) { circleIn.movedBy(Vec2( 2,  0) * m_scale).draw(buttonColor(input.buttons().pressedDuration(GPButton::A))); }
    if (b) { circleIn.movedBy(Vec2( 0,  2) * m_scale).draw(buttonColor(input.buttons().pressedDuration(GPButton::B))); }
    if (x) { circleIn.movedBy(Vec2( 0, -2) * m_scale).draw(buttonColor(input.buttons().pressedDuration(GPButton::X))); }
    if (y) { circleIn.movedBy(Vec2(-2,  0) * m_scale).draw(buttonColor(input.buttons().pressedDuration(GPButton::Y))); }
    // 十字ボタン
    const auto& dpad = input.dpad().pressed();
    const bool l = dpad.left(), r = dpad.right(), u = dpad.up(), d = dpad.down();
    RectF rect(Arg::center(m_center + Vec2(-8, 0) * m_scale), 1.8 * m_scale);
    rect.movedBy(Vec2(-2,  0) * m_scale).draw(buttonColor(l));
    rect.movedBy(Vec2( 2,  0) * m_scale).draw(buttonColor(r));
    rect.movedBy(Vec2( 0, -2) * m_scale).draw(buttonColor(u));
    rect.movedBy(Vec2( 0,  2) * m_scale).draw(buttonColor(d));
    RectF rectIn(rect.scaled(0.5));
    if (l) { rectIn.movedBy(Vec2(-2,  0) * m_scale).draw(buttonColor(input.dpad().pressedDuration(GPDPad::Left ))); }
    if (r) { rectIn.movedBy(Vec2( 2,  0) * m_scale).draw(buttonColor(input.dpad().pressedDuration(GPDPad::Right))); }
    if (u) { rectIn.movedBy(Vec2( 0, -2) * m_scale).draw(buttonColor(input.dpad().pressedDuration(GPDPad::Up   ))); }
    if (d) { rectIn.movedBy(Vec2( 0,  2) * m_scale).draw(buttonColor(input.dpad().pressedDuration(GPDPad::Down ))); }
    // スティック
    Circle(m_center + Vec2(-4, 4.5) * m_scale, 2 * m_scale).draw(button_color);
    Circle(m_center + Vec2( 4, 4.5) * m_scale, 2 * m_scale).draw(button_color);
    Circle axis(m_center, 0.5 * m_scale);
    axis.movedBy((input.axis().l() + Vec2(-4, 4.5)) * m_scale).draw(button_pressed_color);
    axis.movedBy((input.axis().r() + Vec2( 4, 4.5)) * m_scale).draw(button_pressed_color);
    Circle arrow(m_center, 0.25 * m_scale);
    arrow.movedBy((input.arrowL() + Vec2(-4, 4.5)) * m_scale).draw(arrow_color);
    arrow.movedBy((input.arrowR() + Vec2( 4, 4.5)) * m_scale).draw(arrow_color);
    // L/R Trigger
    RoundRect shoulder(Arg::center(m_center), SizeF(4, 1) * m_scale, 0.2 * m_scale);
    shoulder.movedBy(Vec2(-8, -4.5) * m_scale).draw(buttonColor(input.buttons().pressed().key(GPButton::L1)));
    shoulder.movedBy(Vec2( 8, -4.5) * m_scale).draw(buttonColor(input.buttons().pressed().key(GPButton::R1)));
    shoulder.movedBy(Vec2(-8, -6  ) * m_scale).draw(buttonColor(input.buttons().pressed().key(GPButton::L2)));
    shoulder.movedBy(Vec2( 8, -6  ) * m_scale).draw(buttonColor(input.buttons().pressed().key(GPButton::R2)));
    // Start/Select
    RoundRect small(Arg::center(m_center), SizeF(2, 0.8) * m_scale, 0.2 * m_scale);
    small.movedBy(Vec2( 1.7, 1.5) * m_scale).draw(buttonColor(input.buttons().pressed().key(GPButton::Start )));
    small.movedBy(Vec2(-1.7, 1.5) * m_scale).draw(buttonColor(input.buttons().pressed().key(GPButton::Select)));

}

// private function ------------------------------
// ctor/dtor -------------------------------------
SampleGamePadDemo::SampleGamePadDemo(GamePadId gpid, const Vec2& center, double scale) :
    m_gpid(gpid),
    m_center(center),
    m_scale(scale) {}


/* ---------- JoyConDemo ---------- */

// static ----------------------------------------
// public function -------------------------------
void JoyConDemo::update() {
    for (const auto& joy : { JoyConL(0), JoyConR(0) }) {
        if (!joy) { continue; }
        if (auto d = joy.povD8()) {
            // 角度しか取れない
            // 入力なし:無効値 / 入力あり:入力方向 (*d*45_deg)
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
    m_gamepad_demo(GamePadId::_2P, Vec2(400, 300), 20.0),
    m_gamepad_demo_s(GamePadId::_1P, Vec2(500, 600), 10.0),
    m_joyConDemo() {}


}
}
