#pragma once
#include "Misc.hpp"

namespace dx {
namespace di {

enum class GPDPad : int {
    Left, Right, Up, Down,
};

class IDPad {
public:
    virtual const Key& key(GPDPad button) const = 0;
    virtual const Key& left () const = 0;
    virtual const Key& right() const = 0;
    virtual const Key& up   () const = 0;
    virtual const Key& down () const = 0;
    virtual Vec2 vec() const = 0;
protected:
    IDPad() = default;
    virtual ~IDPad() = default;
};

class AbsDPad : public IDPad {
public:
    // virtual const IKey& key(GPButton button) const = 0;
    const Key& left () const override { return key(GPDPad::Left ); }
    const Key& right() const override { return key(GPDPad::Right); }
    const Key& up   () const override { return key(GPDPad::Up   ); }
    const Key& down () const override { return key(GPDPad::Down ); }
    Vec2 vec() const override {
        // return dx::misc::keyPressedToVec2(keyRight(), keyLeft(), keyDown(), keyUp());
        return dx::misc::boolToVec2(
            right().pressed(), left().pressed(),
            down ().pressed(), up  ().pressed());
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
