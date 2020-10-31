#include "PlayerId.hpp"

namespace dx {
namespace di {

/* ---------- Id ---------- */

// static ----------------------------------------
std::unordered_map<PlayerId, GamePadId> Id::s_p2gp = {
    { PlayerId::_1P, GamePadId::_1P },
    { PlayerId::_2P, GamePadId::_2P },
    { PlayerId::_3P, GamePadId::_3P },
    { PlayerId::_4P, GamePadId::_4P },
};
/// <summary> GamePadIdIDとGamePadRawIdIDの対応表 </summary>
std::unordered_map<GamePadId, GamePadRawId> Id::s_gp2raw = {
    { GamePadId::_1P, GamePadRawId::_1P },
    { GamePadId::_2P, GamePadRawId::_2P },
    { GamePadId::_3P, GamePadRawId::_3P },
    { GamePadId::_4P, GamePadRawId::_4P },
};
std::unordered_map<PlayerId, s3d::ColorF> Id::s_p2color = {
    { PlayerId::_1P, s3d::ColorF(1.0, 0.3, 0.3) },
    { PlayerId::_2P, s3d::ColorF(0.3, 0.3, 1.0) },
    { PlayerId::_3P, s3d::ColorF(1.0, 0.9, 0.3) },
    { PlayerId::_4P, s3d::ColorF(0.3, 1.0, 0.3) },
};

// public function -------------------------------
// private function ------------------------------
// ctor/dtor -------------------------------------


}
}
