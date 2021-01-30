#pragma once
#include <optional>
#include <Siv3D/Array.hpp>
#include <Siv3D/String.hpp>

namespace dx {
namespace denum {

template <typename EnumType>
s3d::Array<EnumType> elems() { return s3d::Array<EnumType>(); }
template <typename EnumType>
s3d::String toString(EnumType value) { return U""; }
template <typename EnumType>
std::optional<EnumType> fromString(const s3d::String& str) { return std::optional<EnumType>(); }
template <typename EnumType>
s3d::String toLower(EnumType value) { return U""; }

}
}
