#pragma once

#include <vector>

#include "PlayerCursor.hpp"

namespace dx {
namespace ui {

class PlayerCursorManager
{
public:
    PlayerCursorManager();
    ~PlayerCursorManager() = default;
    
public:
    void update();
    void draw() const;
    
public:
    std::vector<PlayerCursor> m_cursors;
};

}
}
