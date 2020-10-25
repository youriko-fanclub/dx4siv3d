#pragma once
#include <Siv3D/JoyCon.hpp>
#include "KeyCode.hpp"
#include "PlayerId.hpp"

namespace dx {
namespace di {

enum class GPButton : int {
    A, B, X, Y,
    L1, R1, L2, R2,
    Start, Select,
};

class IButtons {
public:
    virtual bool key(GPButton button) const = 0;
    bool a() const { return key(GPButton::A ); }
    bool b() const { return key(GPButton::B ); }
    bool x() const { return key(GPButton::X ); }
    bool y() const { return key(GPButton::Y ); }
    bool l() const { return key(GPButton::L1); }
    bool r() const { return key(GPButton::R1); }
    bool start() const { return key(GPButton::Start); }
    virtual s3d::Duration pressedDuration(GPButton button) const = 0;
protected:
    IButtons() = default;
    virtual ~IButtons() = default;
};

class ButtonsBase : public IButtons {
protected:
    const GamePadId m_gpid;
    const KeyState m_state;
protected:
    ButtonsBase(GamePadId gpid, KeyState state) :
        m_gpid(gpid), m_state(state) {}
    virtual ~ButtonsBase() = default;
};

class ButtonsFromKeyboard final : public ButtonsBase {
public: // public function
    bool key(GPButton button) const override;
    s3d::Duration pressedDuration(GPButton button) const override;
public: // ctor/dtor
    ButtonsFromKeyboard(GamePadId gpid, KeyState state) :
        ButtonsBase(gpid, state) {}
};

class ButtonsFromJoyCon final : public ButtonsBase {
public: // public function
    bool key(GPButton button) const override;
    s3d::Duration pressedDuration(GPButton button) const override;
public: // ctor/dtor
    ButtonsFromJoyCon(GamePadId gpid, KeyState state) :
        ButtonsBase(gpid, state) {}
};

class ButtonsFromMultiSource final : public IButtons {
public: // public function
    bool key(GPButton button) const override;
    s3d::Duration pressedDuration(GPButton button) const override;
private: // field
    const std::vector<std::shared_ptr<IButtons>> m_buttons_list;
public: // ctor/dtor
    ButtonsFromMultiSource(const std::initializer_list<std::shared_ptr<IButtons>>& buttons_list) :
    m_buttons_list(buttons_list) {}
};

class Buttons {
public:
    const IButtons& down   () const { return m_down; }
    const IButtons& pressed() const { return m_pressed; }
    const IButtons& up     () const { return m_up; }
    s3d::Duration pressedDuration(GPButton button) const { return m_pressed.pressedDuration(button); }
private: // field
    ButtonsFromMultiSource m_down;
    ButtonsFromMultiSource m_pressed;
    ButtonsFromMultiSource m_up;
public: // ctor/dtor
    Buttons(GamePadId gpid);
};


}
}

