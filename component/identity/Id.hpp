#pragma once

#include <unordered_map>
#include <Siv3D/FormatInt.hpp>

namespace dx {

template <typename T>
class ID {
public: // static_const/enum
public: // static
public: // public function
    bool operator == (const ID<T>& another) const {
        return m_id == another.m_id;
    }
    bool operator != (const ID<T>& another) const {
        return m_id != another.m_id;
    }
    int toInt() const { return m_id; }
    s3d::String toStr() const { return s3d::ToString(m_id); }

    template<typename DST_ID>
    DST_ID convert() const { return DST_ID(toInt()); }

    ID<T>& operator ++ () {
        ++m_id;
        return *this;
    }
private: // field
    int m_id;
private: // private function
public: // ctor/dtor
    explicit ID(int id): m_id(id) {}
};

template <typename T, int INVALID_ID>
class NullableID : public ID<T> {
public: // static_const/enum
    static const NullableID<T, INVALID_ID> NULL_ID;
public: // public function
    bool isNull() const { return *this == NULL_ID; }
public: // ctor/dtor
    explicit NullableID(int id): ID<T>(id) {}
};

template <typename T, int INVALID_ID>
const NullableID<T, INVALID_ID> NullableID<T, INVALID_ID>::NULL_ID = NullableID<T, INVALID_ID>(INVALID_ID);

}

namespace std {

template<typename T>
struct hash<dx::ID<T>> {
public:
    size_t operator()(const dx::ID<T>& data) const noexcept {
        return std::hash<int>()(data.toInt());
    }
};

}

#define ID_UOMAP(IDType, ValueType) std::unordered_map<IDType, ValueType, dx::idHash<IDType>>

#define ID_DEFINITION(Type)    \
class Type;                    \
using Type##ID = dx::ID<Type>; \
using Type##IDCR = const dx::ID<Type>&;

#define ID_DEFINITION_NS(NameSpace, Type)   \
namespace NameSpace {                       \
    class Type;                             \
    using Type##ID = dx::ID<Type>;          \
    using Type##IDCR = const dx::ID<Type>&; \
}
