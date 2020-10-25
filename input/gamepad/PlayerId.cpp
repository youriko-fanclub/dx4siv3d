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

// public function -------------------------------
// private function ------------------------------
// ctor/dtor -------------------------------------


}
}
