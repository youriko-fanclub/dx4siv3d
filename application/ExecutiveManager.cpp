#include "ExecutiveManager.hpp"

#include "MainExecutiveManager.hpp"
#include "SequenceManager.hpp"

namespace dx {
namespace app {

void ExecutiveManager::initialize() {
  const auto& desc = kanji::app::createExecutiveDesc();
  ApplicationManager::instance()->initialize(desc.application);
  AssetManager::instance()->initialize(desc.font);
  m_sequencer = kanji::seq::SequenceManager::instance().get();
  m_sequencer->initialize();
}

bool ExecutiveManager::update() {
  return m_sequencer->update();
}

void ExecutiveManager::draw() const {
  m_sequencer->draw();
}

}
}
