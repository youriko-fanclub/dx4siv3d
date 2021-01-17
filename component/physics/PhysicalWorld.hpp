#pragma once
#include <Siv3D/HashTable.hpp>
#include "PhysicalObject.hpp"
#include "Timer.hpp"


namespace dx {
namespace phys {

using CategoryMgr = kanji::battle::PhysicalCategory;

class PhysicalWorld {
public: // static_const/enum
public: // static
public: // public function
    const std::weak_ptr<IPhysicalObject>& object(s3d::P2BodyID id) {
        return m_objects.at(id);
    }
    void update(Time dt = s3d::Scene::DeltaTime(), s3d::int32 velocity_iterations = 6, s3d::int32 position_iterations = 2);
    s3d::P2World& impl() { return m_impl; }
    
    // create
    std::shared_ptr<IPhysicalObject> createRect(
        Category category,
        const s3d::Vec2& center,
        const s3d::SizeF& size,
        const s3d::P2Material& material,
        s3d::P2BodyType body_type = s3d::P2BodyType::Dynamic);
    std::shared_ptr<IPhysicalObject> createRect(
        const s3d::String& name,
        Category category,
        const s3d::Vec2& center,
        const s3d::SizeF& size,
        const s3d::P2Material& material,
        s3d::P2BodyType body_type = s3d::P2BodyType::Dynamic);
    std::shared_ptr<IPhysicalObject> createStaticLine(
        Category category,
        const s3d::Vec2& center,
        const s3d::Line& line,
        const s3d::P2Material& material);
    std::shared_ptr<IPhysicalObject> createStaticLine(
        const s3d::String& name,
        Category category,
        const s3d::Vec2& center,
        const s3d::Line& line,
        const s3d::P2Material& material);
private: // field
    s3d::Array<s3d::P2Body> m_bodies;
    s3d::P2World m_impl;
    s3d::HashTable<s3d::P2BodyID, std::weak_ptr<IPhysicalObject>> m_objects;
private: // private function
public: // ctor/dtor
    PhysicalWorld(double gravity = 9.8) :
    m_impl(gravity) {}
};



}
}
