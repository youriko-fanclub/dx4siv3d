#include "PanelGrid.hpp"

namespace dx {
namespace ui {

PanelGrid::PanelGrid() :
    m_panels()
{
    m_panels.emplace_back(s3d::String(U"王"), s3d::Vec2{ 100, 100 }, s3d::Size{ 100, 100 });
}

void PanelGrid::update()
{
    for (auto&& p : m_panels) {
        p.update();
    }
}

void PanelGrid::draw() const
{
    for (const auto& p : m_panels) {
        p.draw();
    }
}

}
}
