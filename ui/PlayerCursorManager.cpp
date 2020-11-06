#include "PlayerCursorManager.hpp"

namespace dx {
namespace ui {

PlayerCursorManager::PlayerCursorManager()
{
    constexpr size_t NumPlayer = 4;
    
    const int step = s3d::Window::ClientWidth() / (NumPlayer + 1);
    const auto& elems = dx::denum::elems<di::PlayerId>();
    
    for (size_t i = 0; i < NumPlayer; ++i) {
        m_cursors.emplace_back(elems[i], s3d::Vec2{ step * (i + 1), s3d::Window::ClientHeight() / 2 });
    }
}

void PlayerCursorManager::update()
{
    for (auto&& c : m_cursors) {
        c.update();
    }
}

void PlayerCursorManager::draw() const
{
    for (const auto& c : m_cursors) {
        c.draw();
    }
}

}
}
