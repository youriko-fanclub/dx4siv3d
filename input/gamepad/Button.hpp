#pragma once

namespace du {
namespace di {

enum class GPButton : int {
    A, B, X, Y,
    L1, R1, L2, R2,
    Start, Select,
};

class IButtons {
public:
    virtual const Key& key(GPButton button) const = 0;
    virtual const Key& keyA() const = 0;
    virtual const Key& keyB() const = 0;
    virtual const Key& keyX() const = 0;
    virtual const Key& keyY() const = 0;
protected:
    IButtons() = default;
    virtual ~IButtons() = default;
};

class AbsButtons : public IButtons {
public:
    // virtual const IKey& key(GPButton button) const = 0;
    const Key& keyA() const override { return key(GPButton::A); }
    const Key& keyB() const override { return key(GPButton::B); }
    const Key& keyX() const override { return key(GPButton::X); }
    const Key& keyY() const override { return key(GPButton::Y); }
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

