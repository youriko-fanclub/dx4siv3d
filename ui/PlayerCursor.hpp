#pragma once

#include "UIComponent.hpp"
#include "PlayerId.hpp"

namespace dx {
namespace ui {

class PlayerCursor : public UIComponent
{
public:
    PlayerCursor(di::PlayerId id, const s3d::Vec2& pos = { 0, 0 });
    ~PlayerCursor() = default;
    
public:
    void update();
    void drawImpl() const override;
    
public:
    di::PlayerId getPlayerId() const { return m_pid; }
    s3d::Vec2 getPos() const { return m_pos; }
    
private:
    di::PlayerId m_pid;
    s3d::Vec2 m_pos;
};

}
}
