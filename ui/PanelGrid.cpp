#include "PanelGrid.hpp"

namespace dx {
namespace ui {

PanelGrid::PanelGrid(const s3d::Vec2& pos, const s3d::Size& panel_size, int32_t num_cols, double margin) :
    m_pos(pos),
    m_panel_size(panel_size),
    m_num_cols(num_cols),
    m_margin(margin),
    m_panels()
{
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

void PanelGrid::Add(const s3d::String& label)
{
    const size_t n = m_panels.size();
    const double x = m_pos.x + (m_panel_size.x + m_margin) * (n % m_num_cols);
    const double y = m_pos.y + (m_panel_size.y + m_margin) * (n / m_num_cols);
    
    m_panels.emplace_back(label, s3d::Vec2{ x, y }, m_panel_size);
}

}
}
