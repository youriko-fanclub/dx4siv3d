#pragma once
#include <optional>

namespace dx {
namespace denum {

template <typename EnumType>
std::vector<EnumType> elems() { return std::vector<EnumType>(); }
template <typename EnumType>
s3d::String toString(EnumType value) { return U""; }
template <typename EnumType>
std::optional<EnumType> fromString(const s3d::String& str) { return std::optional<EnumType>(); }
template <typename EnumType>
s3d::String toLower(EnumType value) { return U""; }

}
}
