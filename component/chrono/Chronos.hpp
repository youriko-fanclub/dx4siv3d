#pragma once
#include <Siv3D/Array.hpp>
#include <Siv3D/CustomStopwatch.hpp>

namespace dx {
namespace chrono {

class Chrono : public s3d::CustomStopwatch {
public: // static_const/enum
public: // static
public: // public function
    void pause() {
        s3d::CustomStopwatch::pause();
    
    }
private: // field
    s3d::Array<Chrono*> m_children;
private: // private function
public: // ctor/dtor
};


}
}

