#pragma once
#include <Siv3D/Key.hpp>

namespace dx {
namespace di {

class IKey {
public: // static_const/enum
public: // static
    static IKey key(const s3d::Key& key);
    static IKey key(const std::initializer_list<s3d::Key>& keys);
public: // public function
    [[nodiscard]] virtual bool down() const { return false; }
    [[nodiscard]] virtual bool pressed() const { return false; }
    [[nodiscard]] virtual bool up() const { return false; }
    [[nodiscard]] virtual s3d::Duration pressedDuration() const { return s3d::Duration(0); }
private: // field
private: // private function
public: // ctor/dtor
    IKey() = default;
};

class KeyFromSingleKey : public IKey {
public: // static_const/enum
public: // static
public: // public function
    [[nodiscard]] bool down   () const override { return m_key.down(); }
    [[nodiscard]] bool pressed() const override { return m_key.pressed(); }
    [[nodiscard]] bool up     () const override { return m_key.up(); }
    [[nodiscard]] s3d::Duration pressedDuration() const override { return m_key.pressedDuration(); }
private: // field
private: // private function
    s3d::Key m_key;
public: // ctor/dtor
    KeyFromSingleKey(const s3d::Key& key) : m_key(key) {}
};

class KeyFromMultiKeys : public IKey {
public: // static_const/enum
public: // static
public: // public function
    [[nodiscard]] bool down   () const override;
    [[nodiscard]] bool pressed() const override;
    [[nodiscard]] bool up     () const override;
    [[nodiscard]] s3d::Duration pressedDuration() const override;
private: // field
private: // private function
    std::initializer_list<s3d::Key> m_keys;
public: // ctor/dtor
    KeyFromMultiKeys(const std::initializer_list<s3d::Key>& keys) : m_keys(keys) {}
};


}
}

