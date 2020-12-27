#pragma once

#include <unordered_map>
#include "Singleton.hpp"

namespace dx {
namespace md {


template <typename ID, typename MasterData>
class IMasterDataRepogitory {
public: // static_const
    using Dictionary = std::unordered_map<ID, const std::unique_ptr<MasterData>>;
public: // public getter
    virtual bool isExist(ID id) const = 0;
    virtual const MasterData* at(ID id) const = 0;
    virtual const Dictionary& data() const = 0;

private: // ctor/dtor
    IMasterDataRepogitory() = default;
};


template <typename ID, typename MasterData>
class MasterDataRepository :
    public IMasterDataRepository<ID, MasterData>,
    public cmp::Singleton<MasterDataRepository<ID, MasterData>> {
public: // static_const/enum
public: // static
    static bool isExist(ID id) { return instance()->isExist(id); }
    static const MasterData* at(ID id) { return instance()->at(id); }
    static const Dictionary& data() { return instance()->data(id); }
public: // public function
    bool isExist(ID id) const override { return m_data.contains(id); }
    const MasterData* at(ID id) const override {
        if (isExist(id)) {
            return m_data.at(id);
        }
        else {
            return nullptr;
        }
    }
    const Dictionary& data() const override { return m_data; }
    
private: // field
    Dictionary m_data;
private: // private function
public: // ctor/dtor
};


}
}
