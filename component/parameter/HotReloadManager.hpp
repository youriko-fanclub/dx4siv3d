#pragma once
#include <unordered_map>
#include <Siv3D/DirectoryWatcher.hpp>
#include "HotReloadableParameters.hpp"
#include "Singleton.hpp"

namespace dx {
namespace cmp {

class HotReloadManager : public Singleton<HotReloadManager> {
public: // static_const/enum
public: // static
public: // public function
    void update();
    void registrate(const s3d::String& key, HotReloadableParameters* params);
    void unregistrate(const s3d::String& key);
private: // field
    std::unordered_map<s3d::String, HotReloadableParameters*> m_paramList;
private: // private function
    s3d::FilePath m_directory;
    s3d::DirectoryWatcher m_watcher;
public: // ctor/dtor
    HotReloadManager();
};



}
}
