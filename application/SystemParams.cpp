#include "SystemParams.hpp"

namespace dx {
namespace app {

/* ---------- SystemParams ---------- */

// static ----------------------------------------
// public function -------------------------------
// protected function -------------------------------
void SystemParams::loadImpl(const s3d::TOMLReader& toml) {
    initial_scene = toml[U"system.scene.initial"].getString();
}
// private function ------------------------------
// ctor/dtor -------------------------------------
SystemParams::SystemParams() :
HotReloadableParameters(U"System") {
    load();
}


}
}
