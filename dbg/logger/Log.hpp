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
    static void debug(const s3d::String& category, const s3d::String& body, const Args&... args) {
        instance()->logImpl(Level::Debug, category, body, args...);
    }
    template<typename ...Args>
    static void info(const s3d::String& category, const s3d::String& body, const Args&... args) {
        instance()->logImpl(Level::Info, category, body, args...);
    }
    template<typename ...Args>
    static void error(const s3d::String& category, const s3d::String& body, const Args&... args) {
        instance()->logImpl(Level::Error, category, body, args...);
    }
private:
    template<typename ...Args>
    void logImpl(Level level, const s3d::String& category, const s3d::String& body, const Args&... args) {
        m_etl->send(level, category, body, args...);
    }

public: // public function
    std::shared_ptr<LogETL> m_etl;
private: // field
private: // private function
public: // ctor/dtor
    Log() :
    m_etl(std::make_shared<LogETL>()) {}
};

}
}
