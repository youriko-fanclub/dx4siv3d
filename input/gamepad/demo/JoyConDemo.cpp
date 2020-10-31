#include "JoyConDemo.hpp"
#include <Siv3D.hpp>

namespace dx {
namespace di {

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
    
}
}
