#pragma once

#include <Siv3D/String.hpp>
#include <Siv3D/Point.hpp>
#include "Singleton.hpp"

namespace dx {
namespace app {

class ApplicationManager final : public cmp::Singleton<ApplicationManager> {
public: // static_const/enum
    struct Desc {
        bool is_close_by_escape_key;
        s3d::String window_title;
        s3d::Size window_size;
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
