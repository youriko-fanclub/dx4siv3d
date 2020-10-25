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

class AbsDPad : public IDPad {
protected:
    const GamePadId m_gpId;
    const KeyState m_state;
protected:
    AbsDPad(GamePadId _gpId, KeyState _state) :
        m_gpId(_gpId), m_state(_state) {}
    virtual ~AbsDPad() = default;
};

class DPadFromKeyboard final : public AbsDPad {
public: // public function
    bool key(GPDPad button) const override;
public: // ctor/dtor
    DPadFromKeyboard(GamePadId _gpId, KeyState _state) :
        AbsDPad(_gpId, _state) {}
};

class DPadFromJoyCon final : public AbsDPad {
public: // public function
    bool key(GPDPad button) const override;
public: // ctor/dtor
    DPadFromJoyCon(GamePadId _gpId, KeyState _state) :
        AbsDPad(_gpId, _state) {}
};

class DPadFromMultiDevice final : public IDPad {
public: // public function
    bool key(GPDPad button) const override {
        return std::any_of(m_dpad_list.begin(), m_dpad_list.end(),
            [button](const auto& dpad){ return dpad->key(button); });
    }
private: // field
    const std::vector<std::shared_ptr<IDPad>> m_dpad_list;
public: // ctor/dtor
    DPadFromMultiDevice(const std::initializer_list<std::shared_ptr<IDPad>>& dpad_list) :
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
    DPadFromMultiDevice m_down;
    DPadFromMultiDevice m_pressed;
    DPadFromMultiDevice m_up;
public: // ctor/dtor
    DPad() :
        m_down   ({ std::make_shared<DPadFromKeyboard>(GamePadId::_1P, KeyState::Down   ),
                    std::make_shared<DPadFromJoyCon  >(GamePadId::_1P, KeyState::Down   ) }),
        m_pressed({ std::make_shared<DPadFromKeyboard>(GamePadId::_1P, KeyState::Pressed),
                    std::make_shared<DPadFromJoyCon  >(GamePadId::_1P, KeyState::Pressed) }),
        m_up     ({ std::make_shared<DPadFromKeyboard>(GamePadId::_1P, KeyState::Up     ),
                    std::make_shared<DPadFromJoyCon  >(GamePadId::_1P, KeyState::Up     ) }) {}
};

}
}
