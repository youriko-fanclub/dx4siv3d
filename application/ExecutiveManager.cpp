#include "ExecutiveManager.hpp"

#include "MainExecutiveManager.hpp"

namespace dx {
namespace app {

void ExecutiveManager::initialize() {
  const auto& desc = kanji::app::createExecutiveDesc();
  ApplicationManager::instance()->initialize(desc.application);
  AssetManager::instance()->initialize();
}


}
}
