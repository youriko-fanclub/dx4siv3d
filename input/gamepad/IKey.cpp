#include "IKey.hpp"

namespace dx {
namespace di {

/* ---------- KeyFromMultiKeys ---------- */

// static ----------------------------------------
IKey IKey::key(const s3d::Key& key) {
    return KeyFromSingleKey(key);
}
IKey IKey::key(const std::initializer_list<s3d::Key>& keys) {
    return KeyFromMultiKeys(keys);
}
// public function -------------------------------
bool KeyFromMultiKeys::down() const {
    return std::any_of(m_keys.begin(), m_keys.end(),
        [](const s3d::Key& key){ return key.down(); });
}

bool KeyFromMultiKeys::pressed() const {
    return std::any_of(m_keys.begin(), m_keys.end(),
        [](const s3d::Key& key){ return key.pressed(); });
}

bool KeyFromMultiKeys::up() const {
    return std::any_of(m_keys.begin(), m_keys.end(),
        [](const s3d::Key& key){ return key.up(); });
}

s3d::Duration KeyFromMultiKeys::pressedDuration() const {
    s3d::Duration d(0);
    for (const auto& key : m_keys) {
        if (d < key.pressedDuration()) {
            d = key.pressedDuration();
        }
    }
    return d;
}

// private function ------------------------------
// ctor/dtor -------------------------------------


}
}
