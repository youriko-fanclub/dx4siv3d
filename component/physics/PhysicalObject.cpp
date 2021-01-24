#include "PhysicalObject.hpp"

namespace dx {
namespace phys {

/* ---------- PhysicalObject ---------- */

// static ----------------------------------------
// public function -------------------------------
// private function ------------------------------
// ctor/dtor -------------------------------------
PhysicalObject::PhysicalObject(const s3d::String& name, Category category, const std::shared_ptr<s3d::P2Body>& body) :
m_name(name),
m_category(category),
m_body(body) {}


}
}

