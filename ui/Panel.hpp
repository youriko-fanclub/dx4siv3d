#pragma once

#include <Siv3D/String.hpp>
#include <Siv3D/Vector2D.hpp>

namespace dx {
namespace ui {

struct Panel
{
public:
    s3d::String m_label;
    s3d::Vec2 m_pos;
    s3d::Size m_size;
    
public:
    Panel(const s3d::String& label, const s3d::Vec2& pos, const s3d::Size& size);
    ~Panel() = default;
    
    void update();
    void draw() const;
};

}
}
