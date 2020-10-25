#pragma once
#include <Siv3D/Vector2D.hpp>
#include "Axis.hpp"

// TOdO:

namespace dx {
namespace di {

class Buttons;
class DPad;
class IAxis;
enum class GPAxis;

using GPArrow = GPAxis;

class IArrows {
public: // public function
    virtual s3d::Vec2 vec(GPArrow arrow) const = 0;
    s3d::Vec2 l() const { return vec(GPArrow::L); }
    s3d::Vec2 r() const { return vec(GPArrow::R); }
protected: // ctor/dtor
    IArrows() = default;
    virtual ~IArrows() = default;
};

#if false
class ArrowsBase : public IArrows {
protected: // field
    const GamePadId m_gpid;
protected: // ctor/dtor
    ArrowsBase(GamePadId gpid) : m_gpid(gpid) {}
    virtual ~ArrowsBase() = default;
};
#endif

class ArrowFromKeyboard final : public IArrows {
public: // public function
    s3d::Vec2 vec(GPArrow arrow) const override;
private: // field
    const Buttons* m_buttons;
    const DPad   * m_dpad;
    const IAxis  * m_axis;
public: // ctor/dtor
    ArrowFromKeyboard(const Buttons* buttons, const DPad* dpad, const IAxis* axis) :
        m_buttons(buttons),
        m_dpad(dpad),
        m_axis(axis) {}
};

}
}
