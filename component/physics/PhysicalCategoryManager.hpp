#pragma once
#include <Siv3D/Array.hpp>
#include <Siv3D/HashTable.hpp>
#include <Siv3D/Physics2D.hpp>

namespace dx {
namespace phys {

class PhysicalCategoryManager {
public:
    using bitflag = s3d::uint16;
    using Categories = s3d::Array<bitflag>;
    using CollisionMap = s3d::HashTable<bitflag, bool>;
public:
    static void initialize(const s3d::Array<bitflag>& categories, const s3d::HashTable<bitflag, bool>& collision_map);
    static bitflag mask(bitflag category);
    static s3d::P2Filter filter(bitflag category);
    static const s3d::Array<bitflag>& categories() { return m_categories; }

private:
    static s3d::HashTable<bitflag, bool> m_collision_map;
    static s3d::HashTable<bitflag, bitflag> m_masks;
    static s3d::Array<bitflag> m_categories;

public:
    PhysicalCategoryManager(const Categories& categories, const CollisionMap& collision_map) {
        initialize(categories, collision_map);
    }
    ~PhysicalCategoryManager() = default;
};

}
}

