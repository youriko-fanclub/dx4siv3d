#pragma once

#include <string>
#include "Singleton.hpp"

namespace dx {
namespace app {

class ApplicationManager final : public cmp::Singleton<ApplicationManager> {
public: // static_const/enum
  struct Desc {
    bool isCloseByEscapeKey;
    std::string windowTitle;
  };
  
public: // static
public: // public function
  void initialize(const Desc& desc);

private: // field
private: // private function
public: // ctor/dtor
};

}
}
