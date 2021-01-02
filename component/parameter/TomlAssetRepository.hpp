#pragma once
#include <unordered_map>
#include "Path.hpp"
#include "Singleton.hpp"
#include "Enum.hpp"

namespace dx {
namespace cmp {

class TomlAssetImpl;

class TomlAssetRepository : public Singleton<TomlAssetRepository> {
public: // static_const/enum
    class TomlAssetData {
    public: // static_const/enum
    public: // static
    public: // public function
        bool is_hotreload;
        std::shared_ptr<TomlAssetImpl> impl;
    private: // field
    private: // private function
    public: // ctor/dtor
    };

public: // static
public: // public function
    std::shared_ptr<TomlAssetImpl> get(const s3d::String& filename) {
        return m_tomls.at(filename);
    }
    bool load(const s3d::String& filename, const app::Path& directory, bool is_hotreload = true);
    void unload(const s3d::String& filename);
    bool is_loaded(const s3d::String& filename) const {
        return m_tomls.contains(filename);
    }
    void update();
#if false
    void subscribe(const s3d::String& key, std::shared_ptr<TomlAssetImpl> toml);
    void unsubscribe(const s3d::String& key);
#endif
private: // field
    std::unordered_map<s3d::String, std::shared_ptr<TomlAssetImpl>> m_tomls;
    std::unordered_map<s3d::FilePath, std::unique_ptr<s3d::DirectoryWatcher>> m_watchers;
private: // private function
public: // ctor/dtor
    TomlAssetRepository();
};

}

#if false
namespace denum {

template <>
std::vector<s3d::FileAction> elems();
template <>
s3d::String toString(s3d::FileAction value);

}
#endif
}
