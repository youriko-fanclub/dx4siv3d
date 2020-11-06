#pragma once
#include <Siv3D/String.hpp>
#include "Singleton.hpp"


namespace dx {
namespace dbg {

class LayeredLogManager : public cmp::Singleton<LayeredLogManager> {
public: // static_const/enum
    enum class Level {
        Info, Assert, Error
    }
    std::vector<s3d::String> logLayer = {
        U"AppBoot",
        U"MainBoot",
        U"dx",
        U"Debug",
        U"Audio",
        U"Audio.SE",
        U"Audio.BGM",
        U"Misc",
    };

public: // static
public: // public function
    void initialize() {
        LayeredLog.Initialize(m_isLogEnable);
        LayeredLog.SetActive("LLOG" , m_llog );

        LayeredLog.SetActive("BOOT" , m_boot );
        LayeredLog.SetActive("dUTIL", m_dutil);
        LayeredLog.SetActive("DEBUG", m_debug);
        LayeredLog.SetActive("AUDIO", m_audio);
        LayeredLog.SetActive("MISC" , m_misc );

        LayeredLog.SetActive("IA:BOOT", m_iaBoot);
        LayeredLog.SetActive("IA:IACT", m_iAct);
        LayeredLog.SetActive("EXPLOG", m_expLog);
        LayeredLog.SetActive("MAIN:BOOT", m_mainBoot);
        LayeredLog.SetActive("MAIN:MEM", m_mainMem);
        LayeredLog.SetActive("EXPM", m_expLog);
    }

private: // field
private: // private function
public: // ctor/dtor
};

}
}

