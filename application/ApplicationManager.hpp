#pragma once

#include <Siv3D/String.hpp>
#include <Siv3D/Point.hpp>
#include "Singleton.hpp"

namespace dx {
namespace app {

class ApplicationManager final : public cmp::Singleton<ApplicationManager> {
public: // static_const/enum
  struct Desc {
    bool isCloseByEscapeKey;
    s3d::String windowTitle;
    s3d::Size windowSize;
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
