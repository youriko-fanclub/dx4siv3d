#pragma once

#include <unordered_map>

namespace dx {
namespace md {


template <typename ID, typename MasterData>
class IMasterDataRepository {
public: // public getter
    virtual bool isExist(ID id) const = 0;
    virtual const MasterData* at(ID id) const = 0;
    virtual const std::unordered_map<ID, const std::unique_ptr<MasterData>>& data() const = 0;

public: // ctor/dtor
};


template <typename ID, typename MasterData>
class MasterDataRepository :
    public IMasterDataRepository<ID, MasterData> {
public: // static_const/enum
    using Dictionary = std::unordered_map<ID, const std::unique_ptr<MasterData>>;
public: // static
public: // public function
    bool isExist(ID id) const override { return m_data.contains(id); }
    const MasterData* at(ID id) const override {
        if (isExist(id)) {
            return m_data.at(id).get();
        }
        else {
            return nullptr;
        }
    }
    const Dictionary& data() const override { return m_data; }
    
protected: // field
    Dictionary m_data;
private: // private function
public: // ctor/dtor
};


}
}
