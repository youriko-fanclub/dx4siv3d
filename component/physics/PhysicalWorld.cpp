#include "PhysicalWorld.hpp"
#include "CollisionObserver.hpp"

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
    auto contacts = m_contacts;
    m_contacts.clear();
    for (const auto& collision : m_impl.getCollisions()) {
        const s3d::P2ContactPair& contact(collision.first);
        auto it = std::find(contacts.begin(), contacts.end(), contact);
        const bool is_enter = it == contacts.end(); // 直前frameに同じobj同士の衝突が無い
        
        auto obj_a = m_objects.at(contact.a).lock();
        auto obj_b = m_objects.at(contact.b).lock();
        if (obj_a->collisionObserver()) {
            if (is_enter) { obj_a->collisionObserver()->onCollisionEnter(obj_b); }
            else          { obj_a->collisionObserver()->onCollisionStay (obj_b); }
        }
        if (obj_b->collisionObserver()) {
            if (is_enter) { obj_b->collisionObserver()->onCollisionEnter(obj_a); }
            else          { obj_b->collisionObserver()->onCollisionStay (obj_a); }
        }
        
        if (it != contacts.end()) {
            contacts.erase(it);
        }
        m_contacts.push_back(contact);
    }
    // 衝突終了のお知らせ
    for (const auto& contact : contacts) {
        auto obj_a = m_objects.contains(contact.a)
            ? m_objects.at(contact.a).lock()
            : nullptr;
        auto obj_b = m_objects.contains(contact.b)
            ? m_objects.at(contact.b).lock()
            : nullptr;
        if (obj_a && obj_a->collisionObserver()) {
            obj_a->collisionObserver()->onCollisionExit(obj_b);
        }
        if (obj_b && obj_b->collisionObserver()) {
            obj_b->collisionObserver()->onCollisionExit(obj_a);
        }
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
    auto body = std::make_shared<s3d::P2Body>(m_impl.createRect(center, size, material, m_category_mgr.filter(category), body_type));
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
    auto body = std::make_shared<s3d::P2Body>(m_impl.createStaticLine(center, line, material, m_category_mgr.filter(category)));
    auto obj = std::make_shared<PhysicalObject>(name, category, body);
    m_objects.emplace(body->id(), obj);
    return obj;
}

// private function ------------------------------
// ctor/dtor -------------------------------------


}
}
