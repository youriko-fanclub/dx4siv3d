#pragma once
#include <unordered_map>
#include "Path.hpp"
#include "Singleton.hpp"
#include "Enum.hpp"

namespace dx {
namespace toml {

class TomlAssetImpl;

class TomlAssetRepository : public cmp::Singleton<TomlAssetRepository> {
public: // static_const/enum
public: // static
public: // public function
    TomlAssetImpl* get(const s3d::String& filename) {
        return m_tomls.at(filename).get();
    }
    bool load(const s3d::String& filename, const app::Path& directory, bool is_hotreload = true);
    void unload(const s3d::String& filename);
    bool isLoaded(const s3d::String& filename) const {
        return m_tomls.contains(filename);
    }
    void update();
private: // field
    std::unordered_map<s3d::String, std::shared_ptr<TomlAssetImpl>> m_tomls;
    std::unordered_map<s3d::FilePath, std::unique_ptr<s3d::DirectoryWatcher>> m_watchers;
private: // private function
public: // ctor/dtor
    TomlAssetRepository() = default;
};

}

namespace denum {

template <>
std::vector<s3d::FileAction> elems();
template <>
s3d::String toString(s3d::FileAction value);

}
}
