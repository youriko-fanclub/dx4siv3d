#pragma once
#include <unordered_map>
#include <Siv3D/FormatLiteral.hpp>
#include <Siv3D/Print.hpp>
#include "LogDefinition.hpp"

using namespace s3d::Literals::FormatLiterals;

namespace dx {
namespace dbg {

class LogDestinationText {
public:
    void setCategoryIsActive(const Category& category, bool is_active);
    void addCategoryIcon(const Category& category, const s3d::String& icon);
    template<typename ...Args>
    void send(Level level, const Category& category, const s3d::String& body, const Args&... args) {
        output(level, category, fillBody(body, args...));
    }
protected:
    virtual void output(Level level, const Category& category, const s3d::String& filled_body) const = 0;
    const s3d::String& icon(Level level) const { return m_level_icon.at(level); }
    s3d::String str(Level level) const { return denum::toString(level); }
private:
    template<typename... Args>
    s3d::String fillBody(const s3d::String& body, const Args&... args) {
        return Fmt(body)(args...);
    }
private: // field
    std::unordered_map<Category, bool> m_is_active;
    std::unordered_map<Category, s3d::String> m_category_icon;
    std::unordered_map<Level, s3d::String> m_level_icon;
public: // ctor/dtor
    LogDestinationText();
};

class LogDestinationConsole : public LogDestinationText {
protected:
    void output(Level level, const Category& category, const s3d::String& filled_body) const override {
        std::cout << U"{}:[{}] {}"_fmt(icon(level), category, filled_body) << std::endl;
    }
private: // field
};

class LogDestinationScreen : public LogDestinationText {
protected:
    void output(Level level, const Category& category, const s3d::String& filled_body) const override {
        s3d::Print << U"{}:[{}] {}"_fmt(str(level), category, filled_body);
    }
};

class LogDestinationConsoleAndScreen : public LogDestinationText {
protected:
    void output(Level level, const Category& category, const s3d::String& filled_body) const override {
        std::cout << U"{}:[{}] {}"_fmt(icon(level), category, filled_body) << std::endl;
        s3d::Print << U"{}:[{}] {}"_fmt(str(level), category, filled_body);
    }
};

}
}

