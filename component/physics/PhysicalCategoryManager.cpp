#include "PhysicalCategoryManager.hpp"

namespace dx {
namespace phys {

using bitflag = PhysicalCategoryManager::bitflag;

/* ---------- PhysicalCategoryManager ---------- */

// static ----------------------------------------
void PhysicalCategoryManager::initialize(const std::vector<bitflag>& categories, const std::unordered_map<bitflag, bool>& collision_map) {
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

std::unordered_map<bitflag, bool> PhysicalCategoryManager::m_collision_map;
std::unordered_map<bitflag, bitflag> PhysicalCategoryManager::m_masks;
std::vector<bitflag> PhysicalCategoryManager::m_categories;
// public function -------------------------------
// private function ------------------------------
// ctor/dtor -------------------------------------

}
}
