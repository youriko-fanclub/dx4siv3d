#pragma once

#include "Singleton.hpp"
#include "ApplicationManager.hpp"
#include "AssetManager.hpp"

namespace dx {
namespace app {

class ISequenceManager {
public:
    virtual void initialize() = 0;
    virtual bool update() = 0;
    virtual void draw() const = 0;
protected:
    ISequenceManager() = default;
    virtual ~ISequenceManager() = default;
};


class ExecutiveManager final : public cmp::Singleton<ExecutiveManager> {
public: // static_const/enum
    class Desc {
    public:
        ApplicationManager::Desc application;
        std::vector<AssetManager::FontDesc> font;
        std::vector<AssetManager::TextureDesc> texture;
        std::vector<AssetManager::AudioDesc> audio;
    };
public: // static
public: // public function
    void initialize();
    bool update();
    void draw() const;
    void finalize() override;
    // void transScene();
private: // field
    ISequenceManager* m_sequencer = nullptr;
private: // private function
public: // ctor/dtor
};


}
}
