#pragma once
#include <Siv3D/HashTable.hpp>
#include <Siv3D/Color.hpp>
#include "Enum.hpp"


/// <summary> 複数プレイヤーによる入力を管理するIDを管理 </summary>
namespace dx {
namespace di {

/// <summary> プレイヤー </summary>
enum class PlayerId {
    _1P, _2P, _3P, _4P// , Any
};

/// <summary> コントローラー </summary>
enum class GamePadId {
    _1P, _2P, _3P, _4P// , Any
};

/// <summary> コントローラー自動割り振り </summary>
enum class GamePadRawId {
    _1P, _2P, _3P, _4P// , Any, Max
};

// e.g. スマブラ
// - Player     : キャラが左から何枠目か
// - GamePad    : コントローラが挿さってるのが左から何枠目か
// - GamePadRaw : そのコントローラに対してマシンが振ったIndex

class Id {
private:
    /// <summary> PlayerIdとGamePadIdの対応表 </summary>
    static s3d::HashTable<PlayerId, GamePadId> s_p2gp;
    /// <summary> GamePadIdとGamePadRawIdの対応表 </summary>
    static s3d::HashTable<GamePadId, GamePadRawId> s_gp2raw;
    
    static s3d::HashTable<PlayerId, s3d::ColorF> s_p2color;
    static s3d::HashTable<PlayerId, s3d::ColorF> s_p2color_light;
    static s3d::HashTable<PlayerId, s3d::ColorF> s_p2color_dark;
public:
    /// <summary> PlayerIdをGamePadIdに変換 </summary>
    static GamePadId ToGamePadId(PlayerId pid) { return s_p2gp.at(pid); }
    static PlayerId ToPlayerId(GamePadId gpid) {
        for (const auto& p2gp : s_p2gp) {
            if (p2gp.second == gpid) {
                return p2gp.first;
            }
        }
        return PlayerId::_1P;
    }
    /// <summary> GamePadIdをGamePadRawIdに変換 </summary>
    static GamePadRawId ToRawID(GamePadId gpid) { return s_gp2raw.at(gpid); }
    /// <summary> PlayerIdをColorに変換 </summary>
    static s3d::ColorF ToColor(PlayerId pid) { return s_p2color.at(pid); }
    /// <summary> PlayerIdをColorに変換 </summary>
    static s3d::ColorF ToColorLight(PlayerId pid) { return s_p2color_light.at(pid); }
    /// <summary> PlayerIdをColorに変換 </summary>
    static s3d::ColorF ToColorDark(PlayerId pid) { return s_p2color_dark.at(pid); }
};

#if false

/// <summary> 三種のIDの対応表 </summary>
class IdConverter {
    /// <summary> PlayerIDとGamePadIDの対応表 </summary>
    static IDictionary<Player, GamePad> player2gamepad = new Dictionary<Player, GamePad>();
    /// <summary> GamePadIDとGamePadRawIDの対応表 </summary>
    static IDictionary<GamePad, GamePadRaw> gamepad2raw = new Dictionary<GamePad, GamePadRaw>();
    
    /// <summary> PlayerIDをGamePadIDに変換 </summary>
    public static GamePad ToGamePadID(Player playerID) => player2gamepad[playerID];
    /// <summary> GamePadIDをGamePadRawIDに変換 </summary>
    public static GamePadRaw ToRawID(GamePad gpID) {
        try {
            return gamepad2raw[gpID];
        }
        catch (System.Exception e) {
            Debug.LogError(e);
            return GamePadRaw.Any;
        }
    }
    
    /// <summary> PlayerIDに対応するGamePadIDを設定 </summary>
    public static void SetPlayer2GamePad(Player playerID, GamePad gpID) {
        if (player2gamepad.ContainsKey(playerID)) {
            player2gamepad[playerID] = gpID;
        }
        else {
            player2gamepad.Add(playerID, gpID);
        }
    }
    
    /// <summary> PlayerIDとGamePadIDの対応をnP-nPに初期化 </summary>
    public static void ResetPlayer2GamePad() {
        player2gamepad.Clear();
        player2gamepad.Add(Player._1P, GamePad._1P);
        player2gamepad.Add(Player._2P, GamePad._2P);
        player2gamepad.Add(Player._3P, GamePad._3P);
        player2gamepad.Add(Player._4P, GamePad._4P);
        player2gamepad.Add(Player.Any, GamePad.Any);
    }
    
    /// <summary> PlayerIDとGamePadIDの対応を一括設定 </summary>
    public static void SetPlayer2GamePad(GamePad _1p, GamePad _2p, GamePad _3p, GamePad _4p) {
        player2gamepad.Clear();
        player2gamepad.Add(Player._1P, _1p);
        player2gamepad.Add(Player._2P, _2p);
        player2gamepad.Add(Player._3P, _3p);
        player2gamepad.Add(Player._4P, _4p);
        player2gamepad.Add(Player.Any, GamePad.Any);
    }
    
    
    /// <summary> CSV形式からGamePadIDとGamePadRawIDの対応関係を読み出す </summary>
    private class GPIDConvertDesc {
        
        [File.CSVColAttr(0)] GamePadRaw raw1P;
        [File.CSVColAttr(1)] GamePadRaw raw2P;
        [File.CSVColAttr(2)] GamePadRaw raw3P;
        [File.CSVColAttr(3)] GamePadRaw raw4P;
        
        /// <summary> GamePadIDとGamePadRawIDの対応関係を一括設定 </summary>
        public void Register(IDictionary<GamePad, GamePadRaw> gp2raw) {
            Debug.Log(ToString());
            gp2raw.Clear();
            gp2raw.Add(GamePad._1P, raw1P);
            gp2raw.Add(GamePad._2P, raw2P);
            gp2raw.Add(GamePad._3P, raw3P);
            gp2raw.Add(GamePad._4P, raw4P);
            gp2raw.Add(GamePad.Any, GamePadRaw.Any);
        }
        
        public override string ToString() => $"1P:{raw1P}, 2P:{raw2P}, 3P:{raw3P}, 4P:{raw4P}";
        
    }
    
    /// <summary> PlayerIDとGamePadIDの対応を一括読み込み </summary>
    public static void Initialize() {
        ResetPlayer2GamePad();
        using (var reader = File.CSVReader<GPIDConvertDesc>.FromMyData("dUtil/Input/RawGamePadWrapper", true))
        {
            foreach (var desc in reader) { desc.Register(gamepad2raw); }
        }
        
    }
    
    /// <summary> 対応関係を書き出し </summary>
    public static void Dump() {
        string rtn = "";
        for (Player i = Player._1P; i <= Player.Any; ++i) {
            rtn += $"Player : {i} : {i.ToGPID()} : {i.ToRawID()} : RawGP\n";
        }
        Debug.Log(rtn);
    }
}


/// <summary> ID関連の拡張メソッド群 </summary>
public static class ExId {
    
    /// <summary> _1P -> 1 </summary>
    public static int ToInt(this Player player) => player.ToInt0Origin() + 1;
    /// <summary> _1P -> 0 </summary>
    public static int ToInt0Origin(this Player player) => (int)player;
    /// <summary> 1 -> _1P </summary>
    public static Player ToPlayerID(this int id) {
        switch (id) {
            case 1 : return Player._1P;
            case 2 : return Player._2P;
            case 3 : return Player._3P;
            case 4 : return Player._4P;
            default: return Player.Any;
        }
    }
    /// <summary> 0 -> _1P </summary>
    public static Player ToPlayerID0Origin(this int id0Origin) => (id0Origin + 1).ToPlayerID();
    
    /// <summary> 1P:Red, 2P:Blue, 3P:Yellow, 4P:Green  </summary>
    public static Color ToColor(this Player player) {
        switch (player) {
            case Player._1P: return Color.red;
            case Player._2P: return Color.blue;
            case Player._3P: return Color.yellow;
            case Player._4P: return Color.green;
            default        : return Color.black;
        }
    }
    /// <summary> 1P:Red, 2P:Blue, 3P:Yellow, 4P:Green  </summary>
    public static string ToColorString(this Player player) {
        switch (player) {
            case Player._1P: return "Red";
            case Player._2P: return "Blue";
            case Player._3P: return "Yellow";
            case Player._4P: return "Green";
            default        : return "Null";
        }
    }
    
    // public static bool In(this Player own, params Player[] others) {
    //     return others.Contains(own);
    // }
    
    /// <summary> PlayerIDをGamePadIDに変換 </summary>
    public static GamePad ToGPID(this Player playerID) => IdConverter.ToGamePadID(playerID);
    /// <summary> GamePadIDをGamePadRawIDに変換 </summary>
    public static GamePadRaw ToRawID(this Player playerID) => IdConverter.ToRawID(IdConverter.ToGamePadID(playerID));
    /// <summary> PlayerIDをGamePadRawIDに変換 </summary>
    public static GamePadRaw ToRawID(this GamePad gpID) => IdConverter.ToRawID(gpID);
    
    public static IList<Player> ValidPlayers() => new Player[4] { Player._1P, Player._2P, Player._3P, Player._4P };
    public static IList<GamePad> ValidGamePads() => new GamePad[4] { GamePad._1P, GamePad._2P, GamePad._3P, GamePad._4P };
}


#if false
public static class Util {
    public static class PlayerID {
        public static IList<Player> GetValids() {
            return new Player[4] { Player._1P, Player._2P, Player._3P, Player._4P };
        }
    }
    public static class GamePadID {
        public static IList<GamePad> GetValids() {
            return new GamePad[4] { GamePad._1P, GamePad._2P, GamePad._3P, GamePad._4P };
        }
    }
}
#endif
#endif

}

namespace denum {

template <>
s3d::Array<di::PlayerId> elems();
template <>
s3d::String toString(di::PlayerId value);

template <>
s3d::Array<di::GamePadId> elems();
template <>
s3d::String toString(di::GamePadId value);

template <>
s3d::Array<di::GamePadRawId> elems();
template <>
s3d::String toString(di::GamePadRawId value);


}

}

