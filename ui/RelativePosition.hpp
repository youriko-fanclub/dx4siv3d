#pragma once
#include <Siv3D/Vector2D.hpp>

namespace dx {
namespace ui {

class RelativePosition {
public: // static_const/enum
public: // static
public: // public function
    s3d::Vec2 offset(float x, float y) const {
        return m_center + s3d::Vec2(x, y) * m_scale;
    }
    s3d::Vec2 offset(const s3d::Vec2 vec) const {
        return m_center + vec * m_scale;
    }
    s3d::Size size(float w, float h) const {
        return s3d::Size(
            static_cast<int>(w * m_scale),
            static_cast<int>(h * m_scale));
    }
    s3d::Size size(const s3d::Size size) const {
        return s3d::Size(
            static_cast<int>(size.x * m_scale),
            static_cast<int>(size.y * m_scale));
    }
    float size(float x) const {
        return x * m_scale;
    }
    
    const s3d::Vec2& center() const { return m_center; }
    float scale() const { return m_scale; }
    
    void setCenter(const s3d::Vec2& center) { m_center = center; }
    void setScale(float scale) { m_scale = scale; }
    void set(const s3d::Vec2& center, float scale) {
        m_center = center;
        m_scale = scale;
    }
private: // field
    s3d::Vec2 m_center;
    float m_scale;
private: // private function
public: // ctor/dtor
};

}
}
