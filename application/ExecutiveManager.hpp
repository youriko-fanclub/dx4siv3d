#pragma once

#include "Singleton.hpp"
#include "ApplicationManager.hpp"
#include "AssetManager.hpp"

namespace dx {
namespace app {


class ExecutiveManager final : public cmp::Singleton<ExecutiveManager> {
public: // static_const/enum
  class Desc {
  public:
    ApplicationManager::Desc application;
  };
public: // static
public: // public function
  void initialize();
  // bool update();
  // void draw() const { m_scene_manager.draw(); }
  // void transScene(){ m_scene_manager.transitionScene(); }
private: // field
private: // private function
public: // ctor/dtor
};


}
}
