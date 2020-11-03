#pragma once

namespace dx {
namespace denum {

template <typename EnumType>
inline std::vector<EnumType> elems() { return std::vector<EnumType>(); }
template <typename EnumType>
inline s3d::String toString(EnumType value) { return U""; }

}
}
