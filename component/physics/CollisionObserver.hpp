#pragma once
#include <memory>
#include "PhysicalWorld.hpp"


namespace dx {
namespace phys {

class ICollisionObserver {
public: // static_const/enum
    using Callback = std::function<void(std::shared_ptr<IPhysicalObject>)>;
public: // static
public: // public function
    virtual void onCollisionEnter(const std::shared_ptr<IPhysicalObject>& that) = 0;
    virtual void onCollisionStay(const std::shared_ptr<IPhysicalObject>& that) = 0;
    virtual void onCollisionExit(const std::shared_ptr<IPhysicalObject>& that) = 0;
private: // field
private: // private function
protected: // ctor/dtor
    ICollisionObserver() = default;
public: // ctor/dtor
    virtual ~ICollisionObserver() = default;
};


class CollisionObserver : public ICollisionObserver {
public: // static_const/enum
public: // static
public: // public function
    virtual void onCollisionEnter(const std::shared_ptr<IPhysicalObject>& that) {}
    virtual void onCollisionStay(const std::shared_ptr<IPhysicalObject>& that) {}
    virtual void onCollisionExit(const std::shared_ptr<IPhysicalObject>& that) {}
protected: // protected function
    const std::shared_ptr<dx::phys::IPhysicalObject>& obj() const { return m_obj; }
private: // field
    std::shared_ptr<dx::phys::IPhysicalObject> m_obj;
private: // private function
protected: // ctor/dtor
    CollisionObserver(const std::shared_ptr<dx::phys::IPhysicalObject>& physical_obj) :
    m_obj(physical_obj) {
        m_obj->setCollisionObserver(this);
    }
public: // ctor/dtor
    virtual ~CollisionObserver() = default;
};


#if false
class CollisionObserver : public ICollisionObserver {
public: // static_const/enum
public: // static
public: // public function
    void onCollisionEnter(const std::shared_ptr<IPhysicalObject>& that) override { m_callback_enter(that); }
    void onCollisionStay(const std::shared_ptr<IPhysicalObject>& that) override { m_callback_stay(that); }
    void onCollisionExit(const std::shared_ptr<IPhysicalObject>& that) override { m_callback_exit(that); }
private: // field
    Callback m_callback_enter;
    Callback m_callback_stay;
    Callback m_callback_exit;
private: // private function
public: // ctor/dtor
};
#endif


}
}

