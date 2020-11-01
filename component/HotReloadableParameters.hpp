#pragma once
#include <vector>
#include <Siv3D/DirectoryWatcher.hpp>
#include "Enum.hpp"

namespace dx {
namespace cmp {

class Param {
public: // static_const/enum
public: // static
public: // public function
    void update();
    void load();
public: // field
    double force_horizontal;
    double force_jump;
    double chara_friction;
    double air_resistance;
    double floor_friction;
    double wall_friction;
private:
    const s3d::String file = U"Physics";
    s3d::FilePath m_path;
    s3d::DirectoryWatcher m_watcher;
private: // private function
public: // ctor/dtor
    Param();
};

}

namespace denum {

template <>
std::vector<s3d::FileAction> elems();
template <>
s3d::String toString(s3d::FileAction value);

}
}
