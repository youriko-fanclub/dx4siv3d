#pragma once

#include <memory>

namespace dx {
namespace cmp {

template<class T>
class Singleton {
public: // static_const/enum
public: // static
    static inline const std::unique_ptr<T>& instance() {
        static auto instance = std::make_unique<T>();
        return instance;
    }
    
public: // public function
    // virtual bool initialize() = 0;
    virtual void finalize() {}
private: // field
    bool m_has_initialized;
    
protected: // ctor/dtor
    Singleton() = default;
    virtual ~Singleton() = default;
public:
    Singleton(const Singleton&  obj) = delete;
    Singleton(const Singleton&& obj) = delete;
    void operator=(const Singleton&  obj) = delete;
    void operator=(const Singleton&& obj) = delete;
};

}
}
