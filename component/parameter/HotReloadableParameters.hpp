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
    const s3d::String& filename() const { return m_filename; }
    void load();
    
    template<typename Type>
    Type get(const s3d::String& key) const { return m_reader[key].get<Type>(); }
    s3d::Vec2 getVec2(const s3d::String& key) const;
    s3d::Size getSize(const s3d::String& key) const;
    s3d::ColorF getColorF(const s3d::String& key) const;
    std::shared_ptr<s3d::Font> getFontPtr(const s3d::String& key) const;
public: // protected function
    virtual void loadImpl(const s3d::TOMLReader& toml) {}
private: // field
    const s3d::String m_filename;
    s3d::FilePath m_path;
    s3d::DirectoryWatcher m_watcher;
    s3d::TOMLReader m_reader;
private: // private function
public: // ctor/dtor
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
