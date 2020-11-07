#include "LogDestination.hpp"

namespace dx {
namespace dbg {

/* ---------- LogDestinationText ---------- */

// static ----------------------------------------
// public function -------------------------------
void LogDestinationText::setCategoryIsActive(const Category& category, bool is_active) {
    m_is_active[category] = is_active;
}

void LogDestinationText::addCategoryIcon(const Category& category, const s3d::String& icon) {
    m_category_icon[category] = icon;
}

// private function ------------------------------
// ctor/dtor -------------------------------------
LogDestinationText::LogDestinationText() :
m_level_icon({
    { Level::Error, U"🛑" },
    { Level::Info, U"🔶" },
    { Level::Debug, U"🔵" },
}) {}

}
}

