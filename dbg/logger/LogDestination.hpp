#pragma once
#include <Siv3D/FormatLiteral.hpp>
#include <Siv3D/Print.hpp>
#include "LogDefinition.hpp"

using namespace s3d::Literals::FormatLiterals;

namespace dx {
namespace dbg {

class LogDestinationText {
public:
    template<typename ...Args>
    void send(Level level, const s3d::String& category, const s3d::String& body, const Args&... args) {
        output(convertToString(level, category, body, args...));
    }
protected:
    virtual void output(const s3d::String& text) const = 0;
private:
    template<typename ...Args>
    s3d::String convertToString(Level level, const s3d::String& category, const s3d::String& body, const Args&... args) {
        const s3d::String filled_body = fillBody(&body, args...);
        return U"[{}|{}] {}"_fmt(denum::toString(level), category, filled_body);
    }
    template<typename... Args>
    s3d::String fillBody(const s3d::String* body, const Args&... args) {
        return Fmt(*body)(args...);
    }
public: // ctor/dtor
    LogDestinationText() = default;
};

class LogDestinationConsole : public LogDestinationText {
protected:
    void output(const s3d::String& text) const override {
        std::cout << text << std::endl;
    }
};

class LogDestinationScreen : public LogDestinationText {
protected:
    void output(const s3d::String& text) const override {
        s3d::Print << text;
    }
};

class LogDestinationConsoleAndScreen : public LogDestinationText {
protected:
    void output(const s3d::String& text) const override {
        std::cout << text << std::endl;
        s3d::Print << text;
    }
};

}
}

