#pragma once
#include <unordered_map>
// #include <Siv3D/DirectoryWatcher.hpp>
#include "Path.hpp"
#include "TomlAsset.hpp"
#include "Singleton.hpp"
#include "Enum.hpp"

namespace dx {
namespace cmp {

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
    std::shared_ptr<TomlAssetImpl> getOrLoad(const s3d::String& filename, const app::Path& directory, bool is_hotreload = true) {
        if (!m_tomls.contains(filename)) {
            m_tomls.insert(std::make_pair(filename, std::make_shared<TomlAssetImpl>(filename, directory)));
        }
        return m_tomls.at(filename);
    }
    bool load(const s3d::String& filename, const app::Path& directory, bool is_hotreload = true) {
        if (!is_loaded(filename)) {
            m_tomls.insert(std::make_pair(filename, std::make_shared<TomlAssetImpl>(filename, directory)));
            return true;
        }
        const auto key = (directory / filename).full();
        if (!m_watchers.contains(key)) {
            m_watchers.insert(std::make_pair(key, std::make_unique<s3d::DirectoryWatcher>()));
        }
        return false;
    }
    void unload(const s3d::String& filename) {
        if (is_loaded(filename)) {
            m_tomls.erase(filename);
        }
    }
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
private: // private function
    std::unordered_map<s3d::FilePath, std::unique_ptr<s3d::DirectoryWatcher>> m_watchers;
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
