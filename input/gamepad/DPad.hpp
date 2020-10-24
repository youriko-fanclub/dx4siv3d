#pragma once
#include "Misc.hpp"

namespace du {
namespace di {

enum class GPDPad : int {
    Left, Right, Up, Down,
};

class IDPad {
public:
    virtual const Key& key(GPDPad button) const = 0;
    virtual const Key& keyLeft () const = 0;
    virtual const Key& keyRight() const = 0;
    virtual const Key& keyUp   () const = 0;
    virtual const Key& keyDown () const = 0;
    virtual Vec2 vec() const = 0;
protected:
    IDPad() = default;
    virtual ~IDPad() = default;
};

class AbsDPad : public IDPad {
public:
    // virtual const IKey& key(GPButton button) const = 0;
    const Key& keyLeft () const override { return key(GPDPad::Left ); }
    const Key& keyRight() const override { return key(GPDPad::Right); }
    const Key& keyUp   () const override { return key(GPDPad::Up   ); }
    const Key& keyDown () const override { return key(GPDPad::Down ); }
    Vec2 vec() const override {
        return dx::misc::boolToVec2(
            keyRight().pressed(), keyLeft().pressed(),
            keyDown ().pressed(), keyUp  ().pressed());
    }
protected:
    AbsDPad() = default;
    virtual ~AbsDPad() = default;
};

class DPadFromKeyboard final : public AbsDPad {
public: // static_const/enum
public: // static
public: // public function
    const Key& key(GPDPad button) const override {
        return m_keyMap.at(button)();
    }
private: // field
    const std::unordered_map<GPDPad, std::function<const Key&()>> m_keyMap {
        { GPDPad::Left , [](){ return KeyS; } },
        { GPDPad::Right, [](){ return KeyF; } },
        { GPDPad::Up   , [](){ return KeyE; } },
        { GPDPad::Down , [](){ return KeyD; } },
    };
private: // private function
public: // ctor/dtor
};

}
}
