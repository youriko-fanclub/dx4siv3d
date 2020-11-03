#pragma once
#include "HotReloadableParameters.hpp"

namespace dx {
namespace app {

class SystemParams final : public dx::cmp::HotReloadableParameters {
public: // protected function
    void loadImpl(const s3d::TOMLReader& toml) override;
public: // field
    s3d::String initial_scene;
private: // private function
public: // ctor/dtor
    SystemParams();
};

}
}
