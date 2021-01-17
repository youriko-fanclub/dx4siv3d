#include <Siv3D/Rectangle.hpp>
#include <Siv3D/FontAsset.hpp>
#include "Panel.hpp"

namespace dx {
namespace ui {

Panel::Panel(const s3d::String& label, const s3d::Vec2& pos, const s3d::Size& size) :
    m_label{ label },
    m_pos{ pos },
    m_size{ size }
{
}

void Panel::update()
{
}

void Panel::draw() const
{
    constexpr double thickness = 2.0;
    s3d::RectF(m_pos, m_size).drawFrame(thickness);
    
    s3d::FontAsset(U"Panel")(m_label).draw(s3d::Arg::center = (m_pos + m_size / 2));
}

}
}
