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
    template<typename ConcreteParams>
    static std::shared_ptr<ConcreteParams> createParams(bool withSubscribe = true) {
        auto params = std::make_shared<ConcreteParams>();
        if (withSubscribe) {
            instance()->subscribe(params->filename(), params);
        }
        return params;
    }
    static std::shared_ptr<HotReloadableParameters> createParams(const s3d::String& filename, bool withSubscribe = true) {
        if (instance()->m_paramList.contains(filename)) {
            return instance()->m_paramList.at(filename);
        }
        auto params = std::make_shared<HotReloadableParameters>(filename);
        if (withSubscribe) {
            instance()->subscribe(params->filename(), params);
        }
        return params;
    }
    static std::shared_ptr<HotReloadableParameters> createParamsWithLoad(const s3d::String& filename, bool withSubscribe = true) {
        bool loadIsNeedless = instance()->m_paramList.contains(filename);
        auto param = createParams(filename, withSubscribe);
        if (!loadIsNeedless) { param->load(); }
        return param;
    }
public: // public function
    void update();
    void subscribe(const s3d::String& key, std::shared_ptr<HotReloadableParameters> params);
    void unsubscribe(const s3d::String& key);
private: // field
    std::unordered_map<s3d::String, std::shared_ptr<HotReloadableParameters>> m_paramList;
private: // private function
    s3d::FilePath m_directory;
    s3d::DirectoryWatcher m_watcher;
public: // ctor/dtor
    HotReloadManager();
};



}
}
