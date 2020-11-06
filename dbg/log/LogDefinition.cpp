#include "LogDefinition.hpp"

namespace dx {
namespace denum {

template <>
s3d::String toString(dbg::Level value) {
    switch (value) {
    case dbg::Level::Error: return U"Error";
    case dbg::Level::Info : return U"Info";
    case dbg::Level::Debug: return U"Debut";
    }
}

}
}
