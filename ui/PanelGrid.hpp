#pragma once

#include <vector>
#include "Panel.hpp"

namespace dx {
namespace ui {

class PanelGrid
{
public:
    PanelGrid();
    ~PanelGrid() = default;
    
    void update();
    void draw() const;
    
private:
    std::vector<Panel> m_panels;
};

}
}
