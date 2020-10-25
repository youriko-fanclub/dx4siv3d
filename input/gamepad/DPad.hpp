#pragma once
#include <Siv3D/JoyCon.hpp>
#include "KeyCode.hpp"
#include "PlayerId.hpp"

namespace dx {
namespace di {

enum class GPDPad : int {
    Left, Right, Up, Down,
};

class IDPad {
public:
    virtual bool key(GPDPad button) const = 0;
    bool left () const { return key(GPDPad::Left ); }
    bool right() const { return key(GPDPad::Right); }
    bool up   () const { return key(GPDPad::Up   ); }
    bool down () const { return key(GPDPad::Down ); }
    s3d::Vec2 vec() const;
protected:
    IDPad() = default;
    virtual ~IDPad() = default;
};

class DPadBase : public IDPad {
protected:
    const GamePadId m_gpId;
    const KeyState m_state;
protected:
    DPadBase(GamePadId _gpId, KeyState _state) :
        m_gpId(_gpId), m_state(_state) {}
    virtual ~DPadBase() = default;
};

class DPadFromKeyboard final : public DPadBase {
public: // public function
    bool key(GPDPad button) const override;
public: // ctor/dtor
    DPadFromKeyboard(GamePadId _gpId, KeyState _state) :
        DPadBase(_gpId, _state) {}
};

class DPadFromJoyCon final : public DPadBase {
public: // public function
    bool key(GPDPad button) const override;
public: // ctor/dtor
    DPadFromJoyCon(GamePadId _gpId, KeyState _state) :
        DPadBase(_gpId, _state) {}
};

class DPadFromMultiSource final : public IDPad {
public: // public function
    bool key(GPDPad button) const override;
private: // field
    const std::vector<std::shared_ptr<IDPad>> m_dpad_list;
public: // ctor/dtor
    DPadFromMultiSource(const std::initializer_list<std::shared_ptr<IDPad>>& dpad_list) :
    m_dpad_list(dpad_list) {}
};

class DPad {
public:
    const IDPad& down   () const { return m_down; }
    const IDPad& pressed() const { return m_pressed; }
    const IDPad& up     () const { return m_up; }
    s3d::Duration pressedDuration() const;
    s3d::Vec2 vec() const;
private: // field
    DPadFromMultiSource m_down;
    DPadFromMultiSource m_pressed;
    DPadFromMultiSource m_up;
public: // ctor/dtor
    DPad();
};

}
}
