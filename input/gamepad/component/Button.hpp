#pragma once
#include <Siv3D/JoyCon.hpp>
#include "KeyCode.hpp"
#include "PlayerId.hpp"

namespace dx {
namespace di {

enum class GamePadButton : int {
    A, B, X, Y,
    L1, R1, L2, R2, L3, R3,
    Start, Select,
};
using GPButton = GamePadButton;

class AbsButtons {
public:
    virtual bool get(GPButton button) const = 0;
    virtual s3d::Duration pressedDuration(GPButton button) const = 0;
protected:
    AbsButtons() = default;
    virtual ~AbsButtons() = default;
};

class ButtonsBase : public AbsButtons {
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
    bool get(GPButton button) const override;
    s3d::Duration pressedDuration(GPButton button) const override;
public: // ctor/dtor
    ButtonsFromKeyboard(GamePadId gpid, KeyState state) :
        ButtonsBase(gpid, state) {}
};

class ButtonsFromJoyCon final : public ButtonsBase {
public: // public function
    bool get(GPButton button) const override;
    s3d::Duration pressedDuration(GPButton button) const override;
public: // ctor/dtor
    ButtonsFromJoyCon(GamePadId gpid, KeyState state) :
        ButtonsBase(gpid, state) {}
};

class ButtonsFromMultiSource final : public AbsButtons {
public: // public function
    bool get(GPButton button) const override;
    s3d::Duration pressedDuration(GPButton button) const override;
private: // field
    const s3d::Array<std::shared_ptr<AbsButtons>> m_buttons_list;
public: // ctor/dtor
    ButtonsFromMultiSource(const std::initializer_list<std::shared_ptr<AbsButtons>>& buttons_list) :
    m_buttons_list(buttons_list) {}
};

class Buttons;

class IButton {
public:
    bool down   () const;
    bool pressed() const;
    bool up     () const;
    s3d::Duration pressedDuration() const;
private: // field
    const Buttons* const m_parent;
    const GPButton m_button;
public: // ctor/dtor
    IButton(const Buttons* parent, GPButton button) :
        m_parent(parent),
        m_button(button) {}
};

class IButtons {
public:
    virtual IButton get(GPButton button) const = 0;
    IButton a() const { return get(GPButton::A ); }
    IButton b() const { return get(GPButton::B ); }
    IButton x() const { return get(GPButton::X ); }
    IButton y() const { return get(GPButton::Y ); }
    IButton l1() const { return get(GPButton::L1); }
    IButton r1() const { return get(GPButton::R1); }
    IButton l2() const { return get(GPButton::L2); }
    IButton r2() const { return get(GPButton::R2); }
    IButton l3() const { return get(GPButton::L3); }
    IButton r3() const { return get(GPButton::R3); }
    IButton start () const { return get(GPButton::Start ); }
    IButton select() const { return get(GPButton::Select); }
private: // field
public: // ctor/dtor
    IButtons() = default;
};

class Buttons final : public IButtons {
public:
    IButton get(GPButton button) const override { return IButton(this, button); }
    
    bool down   (GPButton button) const { return m_down   .get(button); }
    bool pressed(GPButton button) const { return m_pressed.get(button); }
    bool up     (GPButton button) const { return m_up     .get(button); }
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

