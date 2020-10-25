#pragma once
#include <Siv3D/JoyCon.hpp>
#include "KeyCode.hpp"

namespace dx {
namespace di {

enum class KeyState : int {
    Down, Pressed, Up
};

enum class GPButton : int {
    A, B, X, Y,
    L1, R1, L2, R2,
    Start, Select,
};

class IButtons {
public:
    virtual bool key(GPButton button) const = 0;
    virtual bool a() const = 0;
    virtual bool b() const = 0;
    virtual bool x() const = 0;
    virtual bool y() const = 0;
protected:
    IButtons() = default;
    virtual ~IButtons() = default;
};

class AbsButtons : public IButtons {
public:
    // virtual const IKey& key(GPButton button) const = 0;
    bool a() const override { return key(GPButton::A); }
    bool b() const override { return key(GPButton::B); }
    bool x() const override { return key(GPButton::X); }
    bool y() const override { return key(GPButton::Y); }
protected:
    AbsButtons() = default;
    virtual ~AbsButtons() = default;
};

inline bool isState(const Key& key, KeyState state) {
    switch (state) {
    case KeyState::Down   : return KeyL.down();
    case KeyState::Pressed: return KeyL.pressed();
    case KeyState::Up     : return KeyL.up();
    }
}

class ButtonsFromKeyboard final : public AbsButtons {
public: // static_const/enum
public: // static
public: // public function
    bool key(GPButton button) const override {
        return m_keyMap.at(button)();
    }
private: // field
    const KeyState m_state;
    const std::unordered_map<GPButton, std::function<bool()>> m_keyMap {
        { GPButton::A, [this](){ return isState(KeyL, m_state); } },
        { GPButton::B, [this](){ return isState(KeyK, m_state); } },
        { GPButton::X, [this](){ return isState(KeyI, m_state); } },
        { GPButton::Y, [this](){ return isState(KeyJ, m_state); } },
    };
private: // private function
public: // ctor/dtor
    ButtonsFromKeyboard(KeyState state) : m_state(state) {}
};

class ButtonsFromJoyCon final : public AbsButtons {
public: // static_const/enum
public: // static
public: // public function
    bool key(GPButton button) const override {
        return m_keyMap.at(button)();
    }
private: // field
    const KeyState m_state;
    JoyCon m_joycon;
    const std::unordered_map<GPButton, std::function<bool()>> m_keyMap {
        { GPButton::A, [this](){ if (const auto joy = JoyConL(0)) { return isState(joy.button1, m_state); } else { return false; } } },
        { GPButton::B, [this](){ if (const auto joy = JoyConL(0)) { return isState(joy.button0, m_state); } else { return false; } } },
        { GPButton::X, [this](){ if (const auto joy = JoyConL(0)) { return isState(joy.button3, m_state); } else { return false; } } },
        { GPButton::Y, [this](){ if (const auto joy = JoyConL(0)) { return isState(joy.button2, m_state); } else { return false; } } },
    };
private: // private function
public: // ctor/dtor
    ButtonsFromJoyCon(KeyState state) : m_state(state), m_joycon(JoyConL(0)) {}
};


class Buttons {
public:
    const IButtons& down   () const { return m_down; }
    const IButtons& pressed() const { return m_pressed; }
    const IButtons& up     () const { return m_up; }
    s3d::Duration pressedDuration() const { return s3d::Duration(0); } // TOdO:
private: // field
    ButtonsFromKeyboard m_down;
    ButtonsFromKeyboard m_pressed;
    ButtonsFromKeyboard m_up;
public: // ctor/dtor
    Buttons() :
        m_down(KeyState::Down),
        m_pressed(KeyState::Pressed),
        m_up(KeyState::Up) {}
};


}
}

