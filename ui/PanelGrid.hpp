#pragma once

#include <vector>
#include "Panel.hpp"

namespace dx {
namespace ui {

class PanelGrid
{
public:
    PanelGrid(const s3d::Vec2& pos, const s3d::Size& panel_size, int32_t num_cols, double margin = 0.0);
    ~PanelGrid() = default;
    
    void update();
    void draw() const;
    
    void Add(const s3d::String& label);
    // void Delete();
    
private:
    s3d::Vec2 m_pos;
    s3d::Size m_panel_size;
    int32_t m_num_cols;
    double m_margin;
    
    std::vector<Panel> m_panels;
};

}
}
