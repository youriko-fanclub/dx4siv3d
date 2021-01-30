#pragma once

#include <memory>
#include <Siv3D/HashTable.hpp>
#include "Singleton.hpp"
#include "Basic.hpp"
#include "ID.hpp"

namespace dx {

template <typename T>
class IRepogitory {
public: // public getter
    virtual bool isExist(ID<T> id) const = 0;
    virtual const T* at(ID<T> id) const = 0;
public: // public setter
    virtual T* at(ID<T> id) = 0;
    virtual bool add(ID<T> id, const T& value) = 0;
    virtual bool overwrite(ID<T> id, const T& value) = 0;
    virtual bool erase(ID<T> id) = 0;
    
private: // ctor/dtor
    IRepogitory() = default;
};


template <typename T>
class Repogitory : dx::cmp::Singleton<Repogitory<T>> {
public: // static_const/enum
public: // static
    static std::unique_ptr<DBImpl<T>>& get() {
        if (s_instance) {
            s_instance = STD_MAKE_UNIQUE(DBImpl<T>);
        }
        return s_instance;
    }
private:
    static std::unique_ptr<DBImpl<T>> s_instance;
    
public: // public getter
    bool isExist(const ID<T>& id) const {
        return m_data.contains(id);
    }
    const T* at(const ID<T>& id) const {
        return isExist(id) ? m_data.at(id) : throw std::error;
    }
public: // public setter
    T* at(const ID<T>& id) {
        return isExist(id) ? m_data.at(id) : nullptr;
    }
    bool add(const ID<T>& id, const T& value) {
        if (!isExist(id)) {
            m_data.emplace(id, value);
            return true;
        }
        else { return false; }
    }
    bool overwrite(const ID<T>& id, const T& value) {
        if (isExist(id)) {
            m_data.at(id) = value;
            return true;
        }
        else { return false; }
    }
    bool erase(const ID<T>& id) {
        if (isExist(id)) {
            m_data.erase(id);
            return true;
        }
        else { return false; }
    }
    
private: // field
    s3d::HashTable<int, T> m_data;
private: // private function
private: // ctor/dtor
    Repogitory() = default;
};

}
