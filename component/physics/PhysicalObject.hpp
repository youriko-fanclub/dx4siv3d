#pragma once
#include <memory>
#include <Siv3D/Physics2D.hpp>
#include "PhysicalCategory.hpp"


namespace dx {
namespace phys {

class ICollisionObserver;

using Category = dx::phys::PhysicalCategoryManager::bitflag;
using ID = s3d::P2BodyID;

class IPhysicalObject {
public: // static_const/enum
public: // static
public: // public function
    virtual ID id() const = 0;
    virtual const s3d::String& name() const = 0;
    virtual Category category() const = 0;
    virtual const std::shared_ptr<s3d::P2Body>& body() = 0;
    virtual const std::shared_ptr<ICollisionObserver>& collisionObserver() = 0;
private: // field
private: // private function
protected: // ctor/dtor
    IPhysicalObject() = default;
public: // ctor/dtor
    virtual ~IPhysicalObject() = default;
};

class PhysicalObject : public IPhysicalObject {
public: // static_const/enum
public: // static
public: // public function
    ID id() const override { return m_body->id(); }
    const s3d::String& name() const override { return m_name; }
    Category category() const override { return m_category; }
    const std::shared_ptr<s3d::P2Body>& body() override { return m_body; }
    const std::shared_ptr<ICollisionObserver>& collisionObserver() override {
        return nullptr;
    }
private: // field
    s3d::String m_name;
    Category m_category;
    std::shared_ptr<s3d::P2Body> m_body;
private: // private function
public: // ctor/dtor
    PhysicalObject(const s3d::String& name, Category category, const std::shared_ptr<s3d::P2Body>& impl);
};


}
}

