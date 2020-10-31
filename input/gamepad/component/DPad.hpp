#pragma once
#include <Siv3D/JoyCon.hpp>
#include "KeyCode.hpp"
#include "PlayerId.hpp"

namespace dx {
namespace di {

enum class GPDPad : int {
    Left, Right, Up, Down,
};

class AbsDPad {
public:
    virtual bool get(GPDPad DPad) const = 0;
    bool left () const { return get(GPDPad::Left ); }
    bool right() const { return get(GPDPad::Right); }
    bool up   () const { return get(GPDPad::Up   ); }
    bool down () const { return get(GPDPad::Down ); }
    s3d::Vec2 vec() const;
    virtual s3d::Duration pressedDuration(GPDPad DPad) const = 0;
protected:
    AbsDPad() = default;
    virtual ~AbsDPad() = default;
};

class DPadBase : public AbsDPad {
protected:
    const GamePadId m_gpid;
    const KeyState m_state;
protected:
    DPadBase(GamePadId gpid, KeyState state) :
        m_gpid(gpid), m_state(state) {}
    virtual ~DPadBase() = default;
};

class DPadFromKeyboard final : public DPadBase {
public: // public function
    bool get(GPDPad DPad) const override;
    s3d::Duration pressedDuration(GPDPad DPad) const override;
public: // ctor/dtor
    DPadFromKeyboard(GamePadId gpid, KeyState state) :
        DPadBase(gpid, state) {}
};

class DPadFromJoyCon final : public DPadBase {
public: // public function
    bool get(GPDPad DPad) const override;
    s3d::Duration pressedDuration(GPDPad DPad) const override;
public: // ctor/dtor
    DPadFromJoyCon(GamePadId gpid, KeyState state) :
        DPadBase(gpid, state) {}
};

class DPadFromMultiSource final : public AbsDPad {
public: // public function
    bool get(GPDPad DPad) const override;
    s3d::Duration pressedDuration(GPDPad DPad) const override;
private: // field
    const std::vector<std::shared_ptr<AbsDPad>> m_dpad_list;
public: // ctor/dtor
    DPadFromMultiSource(const std::initializer_list<std::shared_ptr<AbsDPad>>& dpad_list) :
    m_dpad_list(dpad_list) {}
};


class DPad;

class IDPadButton {
public:
    bool down   () const;
    bool pressed() const;
    bool up     () const;
    s3d::Duration pressedDuration() const;
private: // field
    const DPad* const m_parent;
    const GPDPad m_button;
public: // ctor/dtor
    IDPadButton(const DPad* parent, GPDPad button) :
        m_parent(parent),
        m_button(button) {}
};

class IDPad {
public:
    virtual IDPadButton get(GPDPad button) const = 0;
    IDPadButton left () const { return get(GPDPad::Left ); }
    IDPadButton right() const { return get(GPDPad::Right); }
    IDPadButton up   () const { return get(GPDPad::Up   ); }
    IDPadButton down () const { return get(GPDPad::Down ); }
    virtual s3d::Vec2 vec() const = 0;
private: // field
public: // ctor/dtor
    IDPad() = default;
};


class DPad : public IDPad {
public:
    IDPadButton get(GPDPad button) const override { return IDPadButton(this, button); }
    
    bool down   (GPDPad button) const { return m_down   .get(button); }
    bool pressed(GPDPad button) const { return m_pressed.get(button); }
    bool up     (GPDPad button) const { return m_up     .get(button); }
    s3d::Duration pressedDuration(GPDPad button) const;
    virtual s3d::Vec2 vec() const;
private: // field
    DPadFromMultiSource m_down;
    DPadFromMultiSource m_pressed;
    DPadFromMultiSource m_up;
public: // ctor/dtor
    DPad(GamePadId gpid);
};

}
}
