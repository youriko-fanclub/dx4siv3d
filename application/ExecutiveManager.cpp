#include "ExecutiveManager.hpp"

#include "MainExecutiveManager.hpp"
#include "SequenceManager.hpp"
#include "HotReloadManager.hpp"
#include "TomlAssetRepository.hpp"
#include "Audio.hpp"
#include "Log.hpp"

namespace dx {
namespace app {

void ExecutiveManager::initialize() {
    const auto& desc = kanji::app::createExecutiveDesc();
    ApplicationManager::instance()->initialize(desc.application);
    AssetManager::instance()->initialize(desc.font, desc.texture, desc.audio);
    m_sequencer = kanji::seq::SequenceManager::instance().get();
    m_sequencer->initialize();
    
    dbg::Log::instance()->setCategoryIsActive(U"Error", true);
    dbg::Log::instance()->setCategoryIsActive(U"Info", true);
    dbg::Log::instance()->setCategoryIsActive(U"Debug", true);
    // dbg::Log::instance()->setCategoryIcon(U"dx"      , U"");
    // dbg::Log::instance()->setCategoryIcon(U"dx.SOUND", U"");
    // dbg::Log::instance()->setCategoryIcon(U"main"    , U"");
}

bool ExecutiveManager::update() {
    cmp::HotReloadManager::instance()->update();
    cmp::TomlAssetRepository::instance()->update();
    return m_sequencer->update();
}

void ExecutiveManager::draw() const {
    m_sequencer->draw();
}

void ExecutiveManager::finalize() {
    aud::Audio::masterSource()->finalize();
}

}
}
