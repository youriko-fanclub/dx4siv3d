#include "PhysicalCategoryManager.hpp"

namespace dx {
namespace phys {

using bitflag = PhysicalCategoryManager::bitflag;

/* ---------- PhysicalCategoryManager ---------- */

// static ----------------------------------------
void PhysicalCategoryManager::initialize(const s3d::Array<bitflag>& categories, const s3d::HashTable<bitflag, bool>& collision_map) {
    m_categories = categories;
    m_collision_map = collision_map;
    for (const auto category_a : m_categories) {
        auto mask = category_a;
        for (const auto category_b : m_categories) {
            if (const auto mask_value = category_a | category_b;
                m_collision_map.contains(mask_value) && m_collision_map.at(mask_value)) {
                mask |= category_b;
            }
        }
        m_masks[category_a] = mask;
    }
}

bitflag PhysicalCategoryManager::mask(const bitflag category) {
    return m_masks.at(category);
}

s3d::P2Filter PhysicalCategoryManager::filter(bitflag category) {
    return s3d::P2Filter(category, m_masks.at(category));
}

s3d::HashTable<bitflag, bool> PhysicalCategoryManager::m_collision_map;
s3d::HashTable<bitflag, bitflag> PhysicalCategoryManager::m_masks;
s3d::Array<bitflag> PhysicalCategoryManager::m_categories;
// public function -------------------------------
// private function ------------------------------
// ctor/dtor -------------------------------------

}
}
