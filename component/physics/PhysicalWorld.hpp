#pragma once
#include <Siv3D/HashTable.hpp>
#include "PhysicalObject.hpp"
#include "PhysicalCategoryManager.hpp"
#include "Timer.hpp"

namespace dx {
namespace phys {

class PhysicalWorld {
public: // static_const/enum
public: // static
public: // public function
    void update(Time dt = s3d::Scene::DeltaTime(), s3d::int32 velocity_iterations = 6, s3d::int32 position_iterations = 2);

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
    s3d::P2World m_impl;
    s3d::HashTable<s3d::P2BodyID, std::weak_ptr<IPhysicalObject>> m_objects;
    PhysicalCategoryManager m_category_mgr;
private: // private function
public: // ctor/dtor
    PhysicalWorld(
        const PhysicalCategoryManager::Categories& categories,
        const PhysicalCategoryManager::CollisionMap& collision_map,
        double gravity = 9.8) :
    m_impl(gravity),
    m_category_mgr(categories, collision_map) {}
};



}
}
