#pragma once
#include "Misc.hpp"

namespace dx {
namespace di {

enum class GPAxis : int {
    L, R,
};

class IAxis {
public:
    virtual const Vec2& key(GPAxis axis) const = 0;
    virtual const Vec2& keyL() const = 0;
    virtual const Vec2& keyR() const = 0;
protected:
    IAxis() = default;
    virtual ~IAxis() = default;
};

class AbsAxis : public IAxis {
public:
    // virtual const IKey& key(GPButton button) const = 0;
    const Vec2& keyL() const override { return key(GPAxis::L); }
    const Vec2& keyR() const override { return key(GPAxis::R); }
protected:
    AbsAxis() = default;
    virtual ~AbsAxis() = default;
};

class AxisFromKeyboard final : public AbsAxis {
public: // static_const/enum
public: // static
public: // public function
    const Vec2& key(GPAxis axis) const override {
        return m_keyMap.at(axis)();
    }
private: // field
    const std::unordered_map<GPAxis, std::function<const Vec2&()>> m_keyMap {
        { GPAxis::L, [](){ return dx::misc::boolToVec2(
            KeyF.pressed(), KeyS.pressed(),
            KeyD.pressed(), KeyE.pressed()); }
        },
        { GPAxis::R, [](){ return dx::misc::boolToVec2(
            KeyL.pressed(), KeyJ.pressed(),
            KeyK.pressed(), KeyI.pressed()); }
        },
    };
private: // private function
public: // ctor/dtor
};

}
}
