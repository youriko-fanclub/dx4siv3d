#include "ExecutiveManager.hpp"

#include "ApplicationManager.hpp"
#include "AssetManager.hpp"

namespace dx {
namespace app {


void ExecutiveManager::initialize() {
  const ApplicationManager::Desc appDesc = {
    .isCloseByEscapeKey = true,
    .windowTitle = "クレイジーサイコレズ"
  };
  ApplicationManager::instance()->initialize(appDesc);
  AssetManager::instance()->initialize();
}


}
}
