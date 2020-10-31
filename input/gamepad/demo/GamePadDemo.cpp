#include "GamePadDemo.hpp"
#include <Siv3D.hpp>
#include "Input.hpp"

namespace dx {
namespace di {

/* ---------- GamePadDemo ---------- */

// static ----------------------------------------
// public function -------------------------------
void GamePadDemo::update() {}
void GamePadDemo::draw() const {
    RoundRect(Arg::center(m_center), Size(25, 15) * m_scale, m_scale).draw(m_base_color);
    drawId();
    drawABXY();
    drawLR();
    drawStartSelect();
    drawDPad();
    drawAxis();
}

// private function ------------------------------
void GamePadDemo::drawId() const {
    const auto& pid = toString(Id::ToPlayerId(m_gpid));
    const auto& gpid = toString(m_gpid);
    const auto& rawid = toString(Id::ToRawID(m_gpid));
    s3d::FontAsset(U"System")(U"{}->{}->{}"_fmt(pid, gpid, rawid))
        .drawAt(m_center + Vec2(0, -12) * m_scale);
}

void GamePadDemo::drawABXY() const {
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

void GamePadDemo::drawLR() const {
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

void GamePadDemo::drawStartSelect() const {
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

void GamePadDemo::drawDPad() const {
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

void GamePadDemo::drawAxis() const {
    const auto& input = Input::get(m_gpid);
    const bool l3 = input.buttons().l3().pressed(),
               r3 = input.buttons().r3().pressed();
    Circle(m_center + Vec2(-4, 4.5) * m_scale, 2 * m_scale).draw(buttonColor(l3));
    Circle(m_center + Vec2( 4, 4.5) * m_scale, 2 * m_scale).draw(buttonColor(r3));
    Circle axis(m_center, 0.75 * m_scale);
    axis.movedBy((input.axis().l() + Vec2(-4, 4.5)) * m_scale).draw(l3 ? buttonColor(input.buttons().l3().pressedDuration()) : m_button_pressed_color);
    axis.movedBy((input.axis().r() + Vec2( 4, 4.5)) * m_scale).draw(r3 ? buttonColor(input.buttons().r3().pressedDuration()) : m_button_pressed_color);
    Circle arrow(m_center, 0.25 * m_scale);
    arrow.movedBy((input.arrowL() + Vec2(-4, 4.5)) * m_scale).draw(m_arrow_color);
    arrow.movedBy((input.arrowR() + Vec2( 4, 4.5)) * m_scale).draw(m_arrow_color);
}

const ColorF& GamePadDemo::buttonColor(bool is_pressed) const {
    return is_pressed ? m_button_pressed_color : m_button_color;
}

ColorF GamePadDemo::buttonColor(s3d::Duration duration) const {
    constexpr s3d::Duration max(3);
    const float factor = (1.f - duration / max);
    return ColorF(
        m_button_pressed_color.r,
        m_button_pressed_color.g * factor,
        m_button_pressed_color.b * factor);
}

// ctor/dtor -------------------------------------
GamePadDemo::GamePadDemo(GamePadId gpid, const Vec2& center, double scale, const ColorF& base, const ColorF& button, const ColorF& pressed, const ColorF& arrow) :
    m_gpid(gpid),
    m_center(center),
    m_scale(scale),
    m_base_color(base),
    m_button_color(button),
    m_button_pressed_color(pressed),
    m_arrow_color(arrow) {}


}
}
