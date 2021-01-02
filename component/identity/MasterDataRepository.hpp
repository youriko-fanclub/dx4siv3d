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
    // 見つからなければ例外を投げる
    const MasterData* at(ID id) const override { return m_data.at(id).get(); }
    const Dictionary& data() const override { return m_data; }
    
protected: // field
    Dictionary m_data;
private: // private function
public: // ctor/dtor
};


}
}
