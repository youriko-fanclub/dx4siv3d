#pragma once
#include <Siv3D/JoyCon.hpp>
#include "KeyCode.hpp"
#include "PlayerId.hpp"

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
    virtual bool a() const { return key(GPButton::A); }
    virtual bool b() const { return key(GPButton::B); }
    virtual bool x() const { return key(GPButton::X); }
    virtual bool y() const { return key(GPButton::Y); }
protected:
    IButtons() = default;
    virtual ~IButtons() = default;
};

class AbsButtons : public IButtons {
protected:
    const GamePadId m_gpId;
    const KeyState m_state;
protected:
    AbsButtons(GamePadId _gpId, KeyState _state) :
        m_gpId(_gpId), m_state(_state) {}
    virtual ~AbsButtons() = default;
};

inline bool isState(const s3d::Key& key, KeyState state) {
    switch (state) {
    case KeyState::Down   : return key.down();
    case KeyState::Pressed: return key.pressed();
    case KeyState::Up     : return key.up();
    }
}

class ButtonsFromKeyboard final : public AbsButtons {
public: // static_const/enum
public: // static
public: // public function
    bool key(GPButton button) const override;
private: // field
private: // private function
public: // ctor/dtor
    ButtonsFromKeyboard(GamePadId gpId, KeyState state) :
        AbsButtons(gpId, state) {}
};

class ButtonsFromJoyCon final : public AbsButtons {
public: // static_const/enum
public: // static
public: // public function
    bool key(GPButton button) const override {
        return m_keyMap.at(button)();
    }
private: // field
    const std::unordered_map<GPButton, std::function<bool()>> m_keyMap {
        { GPButton::A, [this](){ if (const auto joy = s3d::JoyConL(0)) { return isState(joy.button1, m_state); } else { return false; } } },
        { GPButton::B, [this](){ if (const auto joy = s3d::JoyConL(0)) { return isState(joy.button0, m_state); } else { return false; } } },
        { GPButton::X, [this](){ if (const auto joy = s3d::JoyConL(0)) { return isState(joy.button3, m_state); } else { return false; } } },
        { GPButton::Y, [this](){ if (const auto joy = s3d::JoyConL(0)) { return isState(joy.button2, m_state); } else { return false; } } },
    };
private: // private function
public: // ctor/dtor
    ButtonsFromJoyCon(GamePadId gpId, KeyState state) :
        AbsButtons(gpId, state) {}
};

class ButtonsFromMultiDevice final : public IButtons {
public: // static_const/enum
public: // static
public: // public function
    bool key(GPButton button) const override {
        return std::any_of(m_buttons_list.begin(), m_buttons_list.end(),
            [button](const auto& buttons){ return buttons->key(button); });
    }
private: // field
    const std::vector<std::shared_ptr<IButtons>> m_buttons_list;
private: // private function
public: // ctor/dtor
    ButtonsFromMultiDevice(const std::initializer_list<std::shared_ptr<IButtons>>& buttons_list) :
    m_buttons_list(buttons_list) {}
};

class Buttons {
public:
    const IButtons& down   () const { return m_down; }
    const IButtons& pressed() const { return m_pressed; }
    const IButtons& up     () const { return m_up; }
    s3d::Duration pressedDuration() const { return s3d::Duration(0); } // TOdO:
private: // field
    ButtonsFromMultiDevice m_down;
    ButtonsFromMultiDevice m_pressed;
    ButtonsFromMultiDevice m_up;
public: // ctor/dtor
    Buttons() :
        m_down   ({ std::make_shared<ButtonsFromKeyboard>(GamePadId::_1P, KeyState::Down   ),
                    std::make_shared<ButtonsFromJoyCon  >(GamePadId::_1P, KeyState::Down   ) }),
        m_pressed({ std::make_shared<ButtonsFromKeyboard>(GamePadId::_1P, KeyState::Pressed),
                    std::make_shared<ButtonsFromJoyCon  >(GamePadId::_1P, KeyState::Pressed) }),
        m_up     ({ std::make_shared<ButtonsFromKeyboard>(GamePadId::_1P, KeyState::Up     ),
                    std::make_shared<ButtonsFromJoyCon  >(GamePadId::_1P, KeyState::Up     ) }) {}
};


}
}

