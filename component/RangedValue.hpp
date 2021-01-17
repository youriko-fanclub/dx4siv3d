#pragma once
#include <cassert>

namespace dx {
namespace cmp {

template<typename T, int MIN, int MAX>
struct RangedValue {
public:
    [[nodiscard]] operator T() const noexcept {
        return value;
    }
    RangedValue<T, MIN, MAX>& operator =(T another) {
        assert(inRange(another));
        value = another;
        return *this;
    }
    bool inRange(T value) const { return min <= value && value <= max; }
private:
    T value;
    const T min;
    const T max;
public:
    RangedValue(T value) :
    value(value),
    min(static_cast<T>(MIN)),
    max(static_cast<T>(MAX)) {
        *this = value;
    }
};

}
}
