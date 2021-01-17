#include "PhysicalWorld.hpp"

namespace dx {
namespace phys {

/* ---------- PhysicalWorld ---------- */

// static ----------------------------------------
// public function -------------------------------
void PhysicalWorld::update(Time dt, s3d::int32 velocity_iterations, s3d::int32 position_iterations) {
    m_impl.update(dt, velocity_iterations, position_iterations);
    // 実体の消えたオブジェクトはテーブルから削除
    for (auto&& it = m_objects.begin(); it != m_objects.end();) {
        if (it->second.expired()) {
            it = m_objects.erase(it);
        }
        else {
            ++it;
        }
    }
    // 衝突コールバック呼び出し
    for (const auto& collision : m_impl.getCollisions()) {
        auto obj_a = m_objects.at(collision.first.a);
        auto obj_b = m_objects.at(collision.first.b);
        // TOdO:
        // obj_a->onCollision(obj_b);
        // obj_b->onCollision(obj_a);
    }
}

std::shared_ptr<IPhysicalObject> PhysicalWorld::createRect(
    const Category category,
    const s3d::Vec2& center,
    const s3d::SizeF& size,
    const s3d::P2Material& material,
    const s3d::P2BodyType body_type) {
    return createRect(U"Anonymous", category, center, size, material, body_type);
}

std::shared_ptr<IPhysicalObject> PhysicalWorld::createRect(
    const s3d::String& name,
    const Category category,
    const s3d::Vec2& center,
    const s3d::SizeF& size,
    const s3d::P2Material& material,
    const s3d::P2BodyType body_type) {
    auto body = std::make_shared<s3d::P2Body>(m_impl.createRect(center, size, material, CategoryMgr::filter(category), body_type));
    auto obj = std::make_shared<PhysicalObject>(name, category, body);
    m_objects.emplace(body->id(), obj);
    return obj;
}

std::shared_ptr<IPhysicalObject> PhysicalWorld::createStaticLine(
    const Category category,
    const s3d::Vec2& center,
    const s3d::Line& line,
    const s3d::P2Material& material) {
    return createStaticLine(U"Anonymous", category, center, line, material);
}

std::shared_ptr<IPhysicalObject> PhysicalWorld::createStaticLine(
    const s3d::String& name,
    const Category category,
    const s3d::Vec2& center,
    const s3d::Line& line,
    const s3d::P2Material& material) {
    auto body = std::make_shared<s3d::P2Body>(m_impl.createStaticLine(center, line, material, CategoryMgr::filter(category)));
    auto obj = std::make_shared<PhysicalObject>(name, category, body);
    m_objects.emplace(body->id(), obj);
    return obj;
}
// private function ------------------------------
// ctor/dtor -------------------------------------


}
}
