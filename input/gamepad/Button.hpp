#pragma once

namespace dx {
namespace di {

enum class GPButton : int {
    A, B, X, Y,
    L1, R1, L2, R2,
    Start, Select,
};

class IButtons {
public:
    virtual const Key& key(GPButton button) const = 0;
    virtual const Key& a() const = 0;
    virtual const Key& b() const = 0;
    virtual const Key& x() const = 0;
    virtual const Key& y() const = 0;
protected:
    IButtons() = default;
    virtual ~IButtons() = default;
};

class AbsButtons : public IButtons {
public:
    // virtual const IKey& key(GPButton button) const = 0;
    const Key& a() const override { return key(GPButton::A); }
    const Key& b() const override { return key(GPButton::B); }
    const Key& x() const override { return key(GPButton::X); }
    const Key& y() const override { return key(GPButton::Y); }
protected:
    AbsButtons() = default;
    virtual ~AbsButtons() = default;
};

class ButtonsFromKeyboard final : public AbsButtons {
public: // static_const/enum
public: // static
public: // public function
    const Key& key(GPButton button) const override {
        return m_keyMap.at(button)();
    }
private: // field
    const std::unordered_map<GPButton, std::function<const Key&()>> m_keyMap {
        { GPButton::A, [](){ return KeyL; } },
        { GPButton::B, [](){ return KeyK; } },
        { GPButton::X, [](){ return KeyI; } },
        { GPButton::Y, [](){ return KeyJ; } },
    };
private: // private function
public: // ctor/dtor
};


}
}

