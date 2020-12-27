#pragma once
#include "Singleton.hpp"
#include "LogETL.hpp"

using namespace s3d::Literals::FormatLiterals;

namespace dx {
namespace dbg {

class Log : public cmp::Singleton<Log> {
public: // static_const/enum
public: // static
    template<typename ...Args>
    static void debug(const Category& category, const s3d::String& body, const Args&... args) {
        instance()->logImpl(Level::Debug, category, body, args...);
    }
    template<typename ...Args>
    static void info(const Category& category, const s3d::String& body, const Args&... args) {
        instance()->logImpl(Level::Info, category, body, args...);
    }
    template<typename ...Args>
    static void error(const Category& category, const s3d::String& body, const Args&... args) {
        instance()->logImpl(Level::Error, category, body, args...);
    }
public: // public function
    void setCategoryIsActive(const Category& category, bool is_active) {
        m_etl->destination()->setCategoryIsActive(category, is_active);
    }
    void setCategoryIcon(const Category& category, const s3d::String& icon) {
        m_etl->destination()->setCategoryIcon(category, icon);
    }
private: // field
    std::shared_ptr<LogETL> m_etl;
private: // private function
    template<typename ...Args>
    void logImpl(Level level, const Category& category, const s3d::String& body, const Args&... args) {
        m_etl->send(level, category, body, args...);
    }
public: // ctor/dtor
    Log() :
    m_etl(std::make_shared<LogETL>()) {}
};

}
}
