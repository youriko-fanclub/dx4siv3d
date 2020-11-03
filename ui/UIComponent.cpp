#include "UIComponent.hpp"

namespace dx {
namespace ui {


void Button::setCallback(const std::function<void()>& callback) {
    m_pressedCallback = callback;
}
bool Button::update() {
    m_transition.update(m_rect.mouseOver());
    if (rect().mouseOver()) {
        s3d::Cursor::RequestStyle(s3d::CursorStyle::Hand);
    }
    if (rect().leftClicked()) {
        m_pressedCallback();
    }
    return true;
}
void Button::drawImpl() const {
    m_rect.draw(s3d::ColorF(1.0, m_transition.value())).drawFrame(2);
    m_label.drawAt(m_rect.center(), s3d::ColorF(0.25));
}


}
}
