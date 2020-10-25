#pragma once
#include <Siv3D/JoyCon.hpp>
#include <Siv3D/Vector2D.hpp>
#include "KeyCode.hpp"
#include "PlayerId.hpp"

namespace dx {
namespace di {

enum class GPAxis : int {
    L, R,
};

class IAxis {
public:
    virtual s3d::Vec2 vec(GPAxis axis) const = 0;
    virtual s3d::Vec2 l() const { return vec(GPAxis::L); }
    virtual s3d::Vec2 r() const { return vec(GPAxis::R); }
protected:
    IAxis() = default;
    virtual ~IAxis() = default;
};

class AxisBase : public IAxis {
protected:
    const GamePadId m_gpid;
protected:
    AxisBase(GamePadId gpid) : m_gpid(gpid) {}
    virtual ~AxisBase() = default;
};

class AxisFromKeyboard final : public AxisBase {
public: // public function
    s3d::Vec2 vec(GPAxis axis) const override;
public: // ctor/dtor
    AxisFromKeyboard(GamePadId gpid) : AxisBase(gpid) {}
};

class AxisFromJoyCon final : public AxisBase {
public: // public function
    s3d::Vec2 vec(GPAxis axis) const override;
public: // ctor/dtor
    AxisFromJoyCon(GamePadId gpid) : AxisBase(gpid) {}
};

class AxisFromMultiSource final : public IAxis {
public: // public function
    s3d::Vec2 vec(GPAxis axis) const override;
private: // field
    const std::vector<std::shared_ptr<IAxis>> m_axes_list;
public: // ctor/dtor
    AxisFromMultiSource(const std::initializer_list<std::shared_ptr<IAxis>>& axes_list) :
    m_axes_list(axes_list) {}
};

}
}
