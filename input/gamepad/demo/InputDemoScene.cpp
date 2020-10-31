#include "InputDemoScene.hpp"

using namespace s3d::Literals::FormatLiterals;

namespace dx {
namespace di {

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
        { GamePadId::_1P, GamePadDemo(GamePadId::_1P, Vec2(30, 20) * m_scale, m_scale,
            ColorF(0.86, 0.47, 0.35), // base
            ColorF(0.30, 0.30, 0.30), // button
            ColorF(0.96, 0.82, 0.57), // pressed
            ColorF(1.00, 0.30, 0.30)) }, // arrow
        { GamePadId::_2P, GamePadDemo(GamePadId::_2P, Vec2(60, 20) * m_scale, m_scale,
            ColorF(0.35, 0.47, 0.86), // base
            ColorF(0.30, 0.30, 0.30), // button
            ColorF(0.96, 0.82, 0.57), // pressed
            ColorF(1.00, 0.30, 0.30)) }, // arrow
        { GamePadId::_3P, GamePadDemo(GamePadId::_3P, Vec2(30, 40) * m_scale, m_scale,
            ColorF(0.96, 0.77, 0.35), // base
            ColorF(0.30, 0.30, 0.30), // button
            ColorF(0.96, 0.92, 0.67), // pressed
            ColorF(1.00, 0.30, 0.30)) }, // arrow
        { GamePadId::_4P, GamePadDemo(GamePadId::_4P, Vec2(60, 40) * m_scale, m_scale,
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
