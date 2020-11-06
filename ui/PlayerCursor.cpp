
#include <Siv3D/Circle.hpp>
#include <Siv3D/Color.hpp>

#include "PlayerCursor.hpp"
#include "Input.hpp"

namespace dx {
namespace ui {

PlayerCursor::PlayerCursor(di::PlayerId id, const s3d::Vec2& pos) :
    m_pid{ id },
    m_pos{ pos }
{
}

void PlayerCursor::update()
{
    constexpr int CursorSpeed = 4;
    const auto& input = di::Input::get(di::Id::ToGamePadId(m_pid));
    m_pos += CursorSpeed * input.arrowL();
}

void PlayerCursor::drawImpl() const
{
    constexpr double Radius = 10.0;
    s3d::Circle{m_pos, Radius}.draw(di::Id::ToColor(m_pid));
}

}
}
