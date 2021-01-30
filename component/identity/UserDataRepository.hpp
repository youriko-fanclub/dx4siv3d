#pragma once

#include <Siv3D/HashTable.hpp>
#include "Singleton.hpp"

namespace dx {
namespace ud {


template <typename ID, typename UserData>
class IUserDataRepogitory {
public: // static_const
    using Dictionary = s3d::HashTable<ID, const std::shared_ptr<UserData>>;
public: // public getter
    virtual bool isExist(ID id) const = 0;
    virtual const UserData* at(ID id) const = 0;
    virtual const Dictionary& data() const = 0;
public: // public setter
    virtual UserData* at(ID id) = 0;
    virtual bool add(ID<T> id, const T& value) = 0;
    virtual bool erase(ID<T> id) = 0;

private: // ctor/dtor
    IUserDataRepogitory() = default;
};


template <typename ID, typename UserData>
class UserDataRepository :
    public IUserDataRepository<ID, UserData>,
    public cmp::Singleton<UserDataRepository<ID, UserData>> {
public: // static_const/enum
public: // static
public: // public getter
    bool isExist(ID id) const override { return m_data.contains(id); }
    const UserData* at(ID id) const override {
        if (isExist(id)) {
            return m_data.at(id);
        }
        else {
            return nullptr;
        }
    }
    const Dictionary& data() const override { return m_data; }
public: // public setter
    UserData* at(ID id) override { return at(id); }
    bool add(ID<T> id, const UserData& value) override {
        if (isExist(id)) {
            return false;
        }
        else {
            m_data.emplace(id, std::make_unique<UserData>(value));
            return true;
        }
    }
    bool erase(ID<T> id) override {
        if (isExist(id)) {
            m_data.erase(id);
            return true;
        }
        else {
            return false;
        }
    }
    
protected: // protected function
    virtual void initialize() {}
protected: // field
    Dictionary m_data;
private: // private function
private: // ctor/dtor
    UserDataRepository() { initialize(); }
};


}
}

