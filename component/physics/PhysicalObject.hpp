#pragma once
#include <memory>
#include <Siv3D/Physics2D.hpp>
#include "PhysicalCategory.hpp"


namespace dx {
namespace phys {

using Category = kanji::battle::PhysicalCategory::bitflag;
using ID = s3d::P2BodyID;

class IPhysicalObject {
public: // static_const/enum
public: // static
public: // public function
    virtual ID id() const = 0;
    virtual const s3d::String& tag() const = 0;
    virtual Category category() const = 0;
    virtual const std::shared_ptr<s3d::P2Body>& impl() = 0;
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
    virtual ID id() const override { return m_impl->id(); }
    const s3d::String& tag() const override { return m_tag; }
    Category category() const override { return m_category; }
    const std::shared_ptr<s3d::P2Body>& impl() override { return m_impl; }
private: // field
    s3d::String m_tag;
    Category m_category;
    std::shared_ptr<s3d::P2Body> m_impl;
private: // private function
public: // ctor/dtor
    PhysicalObject(const s3d::String& tag, Category category, const std::shared_ptr<s3d::P2Body>& impl);
};


}
}

