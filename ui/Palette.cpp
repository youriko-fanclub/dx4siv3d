#include "Palette.hpp"

namespace dx {
namespace ui {

template<>
s3d::ColorF defaultValue<s3d::ColorF>() { return s3d::ColorF(0.f, 1.f, 0.f); }
template<>
s3d::Font defaultValue<s3d::Font>() { return s3d::Font(10); }

}
}

