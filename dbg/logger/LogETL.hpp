#pragma once
#include "LogDestination.hpp"

namespace dx {
namespace dbg {

class LogExtracter {};
class LogTransformer {};
class LogLoader {};
class LogETL {
public:
    template<typename ...Args>
    void send(Level level, const s3d::String& category, const s3d::String& body, const Args&... args) {
        m_dest->send(level, category, body, args...);
    }
private: // field
    std::shared_ptr<LogDestinationText> m_dest;
public: // ctor/dtor
    LogETL() :
    m_dest(std::make_shared<LogDestinationConsoleAndScreen>()) {}
};

}
}

