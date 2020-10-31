#include "InputDemoScene.hpp"
#include <Siv3D/FontAsset.hpp>
#include <Siv3D/FormatLiteral.hpp>
#include "Input.hpp"

using namespace s3d::Literals::FormatLiterals;

namespace dx {
namespace di {

/* ---------- SampleGamePadDemo ---------- */

// static ----------------------------------------
// public function -------------------------------
void SampleGamePadDemo::update() {}
void SampleGamePadDemo::draw() const {
    RoundRect(Arg::center(m_center), Size(25, 15) * m_scale, m_scale).draw(m_base_color);
    drawId();
    drawABXY();
    drawLR();
    drawStartSelect();
    drawDPad();
    drawAxis();
}

// private function ------------------------------
void SampleGamePadDemo::drawId() const {
    const auto& pid = toString(Id::ToPlayerId(m_gpid));
    const auto& gpid = toString(m_gpid);
    const auto& rawid = toString(Id::ToRawID(m_gpid));
    s3d::FontAsset(U"System")(U"{}->{}->{}"_fmt(pid, gpid, rawid))
        .drawAt(m_center + Vec2(0, -12) * m_scale);
}

void SampleGamePadDemo::drawABXY() const {
    const auto& input = Input::get(m_gpid);
    const bool a = input.buttons().get(GPButton::A).pressed(),
               b = input.button(GPButton::B).pressed(),
               x = input.buttons().x().pressed(),
               y = input.buttons().get(GPButton::Y).pressed();
    Circle circle(m_center + Vec2(8, 0) * m_scale, m_scale);
    circle.movedBy(Vec2( 2,  0) * m_scale).draw(buttonColor(a));
    circle.movedBy(Vec2( 0,  2) * m_scale).draw(buttonColor(b));
    circle.movedBy(Vec2( 0, -2) * m_scale).draw(buttonColor(x));
    circle.movedBy(Vec2(-2,  0) * m_scale).draw(buttonColor(y));
    Circle circleIn(circle.scaled(0.5));
    if (a) { circleIn.movedBy(Vec2( 2,  0) * m_scale).draw(buttonColor(input.buttons().get(GPButton::A).pressedDuration())); }
    if (b) { circleIn.movedBy(Vec2( 0,  2) * m_scale).draw(buttonColor(input.buttons().get(GPButton::B).pressedDuration())); }
    if (x) { circleIn.movedBy(Vec2( 0, -2) * m_scale).draw(buttonColor(input.buttons().get(GPButton::X).pressedDuration())); }
    if (y) { circleIn.movedBy(Vec2(-2,  0) * m_scale).draw(buttonColor(input.buttons().get(GPButton::Y).pressedDuration())); }
}

void SampleGamePadDemo::drawLR() const {
    const auto& input = Input::get(m_gpid);
    const bool l1 = input.buttons().l1().pressed(),
               r1 = input.buttons().r1().pressed(),
               l2 = input.buttons().l2().pressed(),
               r2 = input.buttons().r2().pressed();
    RoundRect shoulder(Arg::center(m_center), SizeF(4, 1) * m_scale, 0.2 * m_scale);
    shoulder.movedBy(Vec2(-8, -4.5) * m_scale).draw(buttonColor(l1));
    shoulder.movedBy(Vec2( 8, -4.5) * m_scale).draw(buttonColor(r1));
    shoulder.movedBy(Vec2(-8, -6  ) * m_scale).draw(buttonColor(l2));
    shoulder.movedBy(Vec2( 8, -6  ) * m_scale).draw(buttonColor(r2));
    RoundRect shoulderIn(Arg::center(m_center), SizeF(3, 0.5) * m_scale, 0.2 * m_scale);
    if (l1) { shoulderIn.movedBy(Vec2(-8, -4.5) * m_scale).draw(buttonColor(input.buttons().get(GPButton::L1).pressedDuration())); }
    if (r1) { shoulderIn.movedBy(Vec2( 8, -4.5) * m_scale).draw(buttonColor(input.buttons().get(GPButton::R1).pressedDuration())); }
    if (l2) { shoulderIn.movedBy(Vec2(-8, -6  ) * m_scale).draw(buttonColor(input.buttons().get(GPButton::L2).pressedDuration())); }
    if (r2) { shoulderIn.movedBy(Vec2( 8, -6  ) * m_scale).draw(buttonColor(input.buttons().get(GPButton::R2).pressedDuration())); }
}

void SampleGamePadDemo::drawStartSelect() const {
    const auto& input = Input::get(m_gpid);
    const bool start  = input.buttons().start ().pressed(),
               select = input.buttons().select().pressed();
    RoundRect small(Arg::center(m_center), SizeF(2, 0.8) * m_scale, 0.2 * m_scale);
    small.movedBy(Vec2( 1.7, 1.5) * m_scale).draw(buttonColor(start ));
    small.movedBy(Vec2(-1.7, 1.5) * m_scale).draw(buttonColor(select));
    RoundRect smallIn(Arg::center(m_center), SizeF(1.5, 0.4) * m_scale, 0.2 * m_scale);
    if (start ) { smallIn.movedBy(Vec2( 1.7, 1.5) * m_scale).draw(buttonColor(input.buttons().get(GPButton::Start ).pressedDuration())); }
    if (select) { smallIn.movedBy(Vec2(-1.7, 1.5) * m_scale).draw(buttonColor(input.buttons().get(GPButton::Select).pressedDuration())); }
}

void SampleGamePadDemo::drawDPad() const {
    const auto& input = Input::get(m_gpid);
    const bool l = input.dpad().get(GPDPad::Left).pressed(),
               r = input.dpad(GPDPad::Right).pressed(),
               u = input.dpad().up().pressed(),
               d = input.dpad().down().pressed();
    RectF rect(Arg::center(m_center + Vec2(-8, 0) * m_scale), 1.8 * m_scale);
    rect.movedBy(Vec2(-2,  0) * m_scale).draw(buttonColor(l));
    rect.movedBy(Vec2( 2,  0) * m_scale).draw(buttonColor(r));
    rect.movedBy(Vec2( 0, -2) * m_scale).draw(buttonColor(u));
    rect.movedBy(Vec2( 0,  2) * m_scale).draw(buttonColor(d));
    RectF rectIn(rect.scaled(0.5));
    if (l) { rectIn.movedBy(Vec2(-2,  0) * m_scale).draw(buttonColor(input.dpad(GPDPad::Left ).pressedDuration())); }
    if (r) { rectIn.movedBy(Vec2( 2,  0) * m_scale).draw(buttonColor(input.dpad(GPDPad::Right).pressedDuration())); }
    if (u) { rectIn.movedBy(Vec2( 0, -2) * m_scale).draw(buttonColor(input.dpad(GPDPad::Up   ).pressedDuration())); }
    if (d) { rectIn.movedBy(Vec2( 0,  2) * m_scale).draw(buttonColor(input.dpad(GPDPad::Down ).pressedDuration())); }
}

void SampleGamePadDemo::drawAxis() const {
    const auto& input = Input::get(m_gpid);
    Circle(m_center + Vec2(-4, 4.5) * m_scale, 2 * m_scale).draw(m_button_color);
    Circle(m_center + Vec2( 4, 4.5) * m_scale, 2 * m_scale).draw(m_button_color);
    Circle axis(m_center, 0.5 * m_scale);
    axis.movedBy((input.axis().l() + Vec2(-4, 4.5)) * m_scale).draw(m_button_pressed_color);
    axis.movedBy((input.axis().r() + Vec2( 4, 4.5)) * m_scale).draw(m_button_pressed_color);
    Circle arrow(m_center, 0.25 * m_scale);
    arrow.movedBy((input.arrowL() + Vec2(-4, 4.5)) * m_scale).draw(m_arrow_color);
    arrow.movedBy((input.arrowR() + Vec2( 4, 4.5)) * m_scale).draw(m_arrow_color);
}

const ColorF& SampleGamePadDemo::buttonColor(bool is_pressed) const {
    return is_pressed ? m_button_pressed_color : m_button_color;
}

ColorF SampleGamePadDemo::buttonColor(s3d::Duration duration) const {
    constexpr s3d::Duration max(3);
    const float factor = (1.f - duration / max);
    return ColorF(
        m_button_pressed_color.r,
        m_button_pressed_color.g * factor,
        m_button_pressed_color.b * factor);
}

// ctor/dtor -------------------------------------
SampleGamePadDemo::SampleGamePadDemo(GamePadId gpid, const Vec2& center, double scale, const ColorF& base, const ColorF& button, const ColorF& pressed, const ColorF& arrow) :
    m_gpid(gpid),
    m_center(center),
    m_scale(scale),
    m_base_color(base),
    m_button_color(button),
    m_button_pressed_color(pressed),
    m_arrow_color(arrow) {}


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
}

void InputDemoScene::draw() const {
    for (const auto gpid : elems<GamePadId>()) {
        m_gamepad_demos.at(gpid).draw();
    }
}

// private function ------------------------------
// ctor/dtor -------------------------------------
InputDemoScene::InputDemoScene(const InitData& init) :
    IScene(init),
    m_scale(8),
    m_layout(Layout::Horizontal),
    m_gamepad_demos({
        { GamePadId::_1P, SampleGamePadDemo(GamePadId::_1P, Vec2(30, 20) * m_scale, m_scale,
            ColorF(0.86, 0.47, 0.35), // base
            ColorF(0.30, 0.30, 0.30), // button
            ColorF(0.96, 0.82, 0.57), // pressed
            ColorF(1.00, 0.30, 0.30)) }, // arrow
        { GamePadId::_2P, SampleGamePadDemo(GamePadId::_2P, Vec2(60, 20) * m_scale, m_scale,
            ColorF(0.35, 0.47, 0.86), // base
            ColorF(0.30, 0.30, 0.30), // button
            ColorF(0.96, 0.82, 0.57), // pressed
            ColorF(1.00, 0.30, 0.30)) }, // arrow
        { GamePadId::_3P, SampleGamePadDemo(GamePadId::_3P, Vec2(30, 40) * m_scale, m_scale,
            ColorF(0.96, 0.77, 0.35), // base
            ColorF(0.30, 0.30, 0.30), // button
            ColorF(0.96, 0.92, 0.67), // pressed
            ColorF(1.00, 0.30, 0.30)) }, // arrow
        { GamePadId::_4P, SampleGamePadDemo(GamePadId::_4P, Vec2(60, 40) * m_scale, m_scale,
            ColorF(0.35, 0.86, 0.47), // base
            ColorF(0.30, 0.30, 0.30), // button
            ColorF(0.96, 0.82, 0.57), // pressed
            ColorF(1.00, 0.30, 0.30)) }, // arrow
    }),
    m_joyConDemo()
{
    switch (m_layout) {
    case Layout::Square: {
    
    } break;
    case Layout::Horizontal: {
        m_gamepad_demos.at(GamePadId::_1P).setCenter(Vec2( 20, 40) * m_scale);
        m_gamepad_demos.at(GamePadId::_2P).setCenter(Vec2( 50, 40) * m_scale);
        m_gamepad_demos.at(GamePadId::_3P).setCenter(Vec2( 80, 40) * m_scale);
        m_gamepad_demos.at(GamePadId::_4P).setCenter(Vec2(110, 40) * m_scale);
    } break;
    case Layout::Vertical: {
    } break;
    }
}


}
}
