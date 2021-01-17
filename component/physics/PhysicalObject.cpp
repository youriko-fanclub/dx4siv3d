#include "PhysicalObject.hpp"

namespace dx {
namespace phys {

/* ---------- PhysicalObject ---------- */

// static ----------------------------------------
// public function -------------------------------
// private function ------------------------------
// ctor/dtor -------------------------------------
PhysicalObject::PhysicalObject(const s3d::String& tag, Category category, const std::shared_ptr<s3d::P2Body>& impl) :
m_tag(tag),
m_category(category),
m_impl(impl) {}


}
}

