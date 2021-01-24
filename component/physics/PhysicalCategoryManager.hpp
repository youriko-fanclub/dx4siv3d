#pragma once
#include <unordered_map>
#include <vector>
#include <Siv3D/Physics2D.hpp>

namespace dx {
namespace phys {

class PhysicalCategoryManager {
public:
    using bitflag = s3d::uint16;
    using Categories = std::vector<bitflag>;
    using CollisionMap = std::unordered_map<bitflag, bool>;
public:
    static void initialize(const std::vector<bitflag>& categories, const std::unordered_map<bitflag, bool>& collision_map);
    static bitflag mask(bitflag category);
    static s3d::P2Filter filter(bitflag category);
    static const std::vector<bitflag>& categories() { return m_categories; }

private:
    static std::unordered_map<bitflag, bool> m_collision_map;
    static std::unordered_map<bitflag, bitflag> m_masks;
    static std::vector<bitflag> m_categories;

public:
    PhysicalCategoryManager(const Categories& categories, const CollisionMap& collision_map) {
        initialize(categories, collision_map);
    }
    ~PhysicalCategoryManager() = default;
};

}
}

