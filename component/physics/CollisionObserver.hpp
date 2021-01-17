#pragma once
#include <memory>
#include "PhysicalWorld.hpp"


namespace dx {
namespace phys {

class ICollisionObserver {
public: // static_const/enum
public: // static
public: // public function
    virtual void onConllisionEnter(std::weak_ptr<IPhysicalObject> that);
    virtual void onConllisionStay(std::weak_ptr<IPhysicalObject> that);
    virtual void onConllisionExit(std::weak_ptr<IPhysicalObject> that);
private: // field
private: // private function
protected: // ctor/dtor
    ICollisionObserver() = default;
public: // ctor/dtor
    virtual ~ICollisionObserver() = default;
};

}
}

