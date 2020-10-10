#pragma once

#include "Singleton.hpp"
// #include "./sequenceManager.h"
// #include "../_main/CommonData.h"

namespace dx {
namespace app {


class ExecutiveManager final : public cmp::Singleton<ExecutiveManager> {
private:
  // CommonData m_common_data;
  // Scene::Manager m_scene_manager;
  
public:
  void initialize();
public:
  // bool update();
  
  // void draw() const { m_scene_manager.draw(); }
  // void transScene(){ m_scene_manager.transitionScene(); }
};


}
}
