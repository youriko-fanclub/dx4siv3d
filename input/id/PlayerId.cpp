#include "PlayerId.hpp"

namespace dx {
namespace di {

/* ---------- Id ---------- */

// static ----------------------------------------
s3d::HashTable<PlayerId, GamePadId> Id::s_p2gp = {
    { PlayerId::_1P, GamePadId::_1P },
    { PlayerId::_2P, GamePadId::_2P },
    { PlayerId::_3P, GamePadId::_3P },
    { PlayerId::_4P, GamePadId::_4P },
};
/// <summary> GamePadIdIDとGamePadRawIdIDの対応表 </summary>
s3d::HashTable<GamePadId, GamePadRawId> Id::s_gp2raw = {
    { GamePadId::_1P, GamePadRawId::_1P },
    { GamePadId::_2P, GamePadRawId::_2P },
    { GamePadId::_3P, GamePadRawId::_3P },
    { GamePadId::_4P, GamePadRawId::_4P },
};
s3d::HashTable<PlayerId, s3d::ColorF> Id::s_p2color = {
    { PlayerId::_1P, s3d::ColorF(1.0, 0.3, 0.3) },
    { PlayerId::_2P, s3d::ColorF(0.3, 0.3, 1.0) },
    { PlayerId::_3P, s3d::ColorF(1.0, 0.9, 0.3) },
    { PlayerId::_4P, s3d::ColorF(0.3, 1.0, 0.3) },
};
s3d::HashTable<PlayerId, s3d::ColorF> Id::s_p2color_light = {
    { PlayerId::_1P, s3d::ColorF(s3d::Color(255, 133, 133)) },
    { PlayerId::_2P, s3d::ColorF(s3d::Color(140, 140, 204)) },
    { PlayerId::_3P, s3d::ColorF(s3d::Color(255, 235,  70)) },
    { PlayerId::_4P, s3d::ColorF(s3d::Color(130, 201, 130)) },
};
s3d::HashTable<PlayerId, s3d::ColorF> Id::s_p2color_dark = {
    { PlayerId::_1P, s3d::ColorF(s3d::Color(204,  33,  33)) },
    { PlayerId::_2P, s3d::ColorF(s3d::Color( 50,  50, 144)) },
    { PlayerId::_3P, s3d::ColorF(s3d::Color(230, 185,  10)) },
    { PlayerId::_4P, s3d::ColorF(s3d::Color( 70, 141,  70)) },
};

// public function -------------------------------
// private function ------------------------------
// ctor/dtor -------------------------------------


}

namespace denum {

template <>
s3d::Array<di::PlayerId> elems() {
    return s3d::Array<di::PlayerId>({
        di::PlayerId::_1P, di::PlayerId::_2P, di::PlayerId::_3P, di::PlayerId::_4P,
    });
}
template <>
s3d::String toString(di::PlayerId value) {
    switch (value) {
    case di::PlayerId::_1P: return U"1P";
    case di::PlayerId::_2P: return U"2P";
    case di::PlayerId::_3P: return U"3P";
    case di::PlayerId::_4P: return U"4P";
    }
}

template <>
s3d::Array<di::GamePadId> elems() {
    return s3d::Array<di::GamePadId>({
        di::GamePadId::_1P, di::GamePadId::_2P, di::GamePadId::_3P, di::GamePadId::_4P,
    });
}
template <>
s3d::String toString(di::GamePadId value) {
    switch (value) {
    case di::GamePadId::_1P: return U"1P";
    case di::GamePadId::_2P: return U"2P";
    case di::GamePadId::_3P: return U"3P";
    case di::GamePadId::_4P: return U"4P";
    }
}

template <>
s3d::Array<di::GamePadRawId> elems() {
    return s3d::Array<di::GamePadRawId>({
        di::GamePadRawId::_1P, di::GamePadRawId::_2P, di::GamePadRawId::_3P, di::GamePadRawId::_4P,
    });
}
template <>
s3d::String toString(di::GamePadRawId value) {
    switch (value) {
    case di::GamePadRawId::_1P: return U"1P";
    case di::GamePadRawId::_2P: return U"2P";
    case di::GamePadRawId::_3P: return U"3P";
    case di::GamePadRawId::_4P: return U"4P";
    }
}

}

}
