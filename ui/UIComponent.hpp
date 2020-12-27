#pragma once

#include <Siv3D/Cursor.hpp>
#include <Siv3D/Color.hpp>
#include <Siv3D/Font.hpp>
#include <Siv3D/Rectangle.hpp>
#include <Siv3D/Transition.hpp>

namespace dx {
namespace ui {


class UIComponent {
public:
    bool visible() const { return m_isVisible; }
    void setVisible(bool isVisible) { m_isVisible = isVisible; }
    
    void draw() const { if (m_isVisible) { drawImpl(); } }
protected:
    virtual void drawImpl() const = 0;
    
private: // field
    bool m_isVisible = true;
    
protected:
    UIComponent() = default;
    virtual ~UIComponent() = default;
};


class Button : public UIComponent {
public: // static_const/enum
public: // static
public: // public getter
    const s3d::Rect& rect() const { return m_rect; }
public: // public setter
    void setCallback(const std::function<void()>& callback);
    bool update();
    void drawImpl() const override;
private: // field
    s3d::Rect m_rect;
    s3d::DrawableText m_label;
    s3d::Transition m_transition;
    std::function<void()> m_pressed_callback = [](){};
private: // private function
public: // ctor/dtor
    Button(
        const s3d::Rect& rect,
        const s3d::DrawableText& label,
        const s3d::Transition& transition,
        const std::function<void()>& pressed_callback) :
    m_rect(rect), m_label(label), m_transition(transition), m_pressed_callback(pressed_callback) {}
    Button(const s3d::Rect& rect, const s3d::DrawableText& label, const s3d::Transition& transition) :
    m_rect(rect), m_label(label), m_transition(transition) {}
};


}
}

namespace dui = dx::ui;
