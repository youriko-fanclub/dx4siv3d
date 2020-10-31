#pragma once
#include <Siv3D/Effect.hpp>
#include <Siv3D/Vector2D.hpp>

namespace dx {
namespace di {

class JoyConDemo {
public: // static_const/enum
public: // static
public: // public function
    void update();
    void draw() const;
private: // field
    s3d::Effect m_effect;
    s3d::Vec2 m_left, m_right;
    double m_angle;
    double m_scale;
    bool m_covered;
private: // private function
public: // ctor/dtor
    JoyConDemo();
};

}
}
