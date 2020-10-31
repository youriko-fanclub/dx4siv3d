#pragma once
#include <Siv3D/Vector2D.hpp>
#include <Siv3D/Color.hpp>
#include <Siv3D/Duration.hpp>
#include "PlayerId.hpp"

namespace dx {
namespace di {

class GamePadDemo {
public: // static_const/enum
public: // static
public: // public function
    void setCenter(float x, float y) { m_center.set(x, y);}
    void setCenter(const s3d::Vec2& center) { m_center = center;}
    void update();
    void draw() const;
private: // field
    GamePadId m_gpid;
    s3d::Vec2 m_center;
    double m_scale;
    
    const s3d::ColorF m_base_color;
    const s3d::ColorF m_button_color;
    const s3d::ColorF m_button_pressed_color;
    const s3d::ColorF m_arrow_color;

private: // private function
    void drawABXY() const;
    void drawLR() const;
    void drawStartSelect() const;
    void drawDPad() const;
    void drawAxis() const;
    void drawId() const;
    const s3d::ColorF& buttonColor(bool is_pressed) const;
    s3d::ColorF buttonColor(s3d::Duration duration) const;
public: // ctor/dtor
    GamePadDemo(GamePadId id, const s3d::Vec2& center, double scale, const s3d::ColorF& base, const s3d::ColorF& button, const s3d::ColorF& pressed, const s3d::ColorF& arrow);
};

}
}

