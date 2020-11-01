#pragma once
#include <vector>
#include <Siv3D/DirectoryWatcher.hpp>
#include <Siv3D/TOMLReader.hpp>
#include "Enum.hpp"

namespace dx {
namespace cmp {

class HotReloadableParameters {
public: // static_const/enum
public: // static
public: // public function
    void update();
    void load();
    template<typename Type>
    Type get(const s3d::String& key) const { return m_reader[key].get<Type>(); }
public: // protected function
    virtual void loadImpl(const s3d::TOMLReader& toml) {}
private: // field
    const s3d::String m_filename;
    s3d::FilePath m_path;
    s3d::DirectoryWatcher m_watcher;
    s3d::TOMLReader m_reader;
private: // private function
protected: // ctor/dtor
    HotReloadableParameters(const s3d::String& filename);
    virtual ~HotReloadableParameters();
};

}

namespace denum {

template <>
std::vector<s3d::FileAction> elems();
template <>
s3d::String toString(s3d::FileAction value);

}
}
