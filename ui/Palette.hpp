#pragma once
#include <unordered_map>
#include <Siv3D/String.hpp>
#include <Siv3D/Color.hpp>
#include <Siv3D/Font.hpp>

namespace dx {
namespace ui {

template<typename Type>
Type defaultValue() { return Type(); }
template<>
s3d::ColorF defaultValue<s3d::ColorF>();
template<>
s3d::Font defaultValue<s3d::Font>();

template<typename Key, typename Value>
class Palette {
public: // static_const/enum
public: // static
public: // public function
    bool contains(const Key& key) const {
        return m_impl.contains(key);
    }
    const Value& at(const Key& key) const {
        if (m_impl.contains(key)) {
            return m_impl.at(key);
        }
        else {
            return m_default;
        }
    }
    void insert(const Key& key, const Value& color) {
        m_impl.insert_or_assign(key, color);
    }
private: // field
    const Value m_default;
    std::unordered_map<Key, Value> m_impl;
private: // private function
public: // ctor/dtor
    Palette() :
    m_default(defaultValue<Value>()) {}
    Palette(const Value& defaultValue) :
    m_default(defaultValue) {}
};


using ColorPalette = Palette<s3d::String, s3d::ColorF>;
using FontPalette = Palette<s3d::String, s3d::Font>;


}
}

