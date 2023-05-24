#pragma once

#include <string_view>

namespace GuiBase {
    enum class LogLevel : int {
        none = 0,
        critical,
        error,
        warning,
        trace,
        log
    };

    class Logger {
    public:
        static void log(std::string_view str);
        static void trace(std::string_view str);
        static void warning(std::string_view str);
        static void error(std::string_view str);
        static void critical(std::string_view str);
        static void setLogLevel(const LogLevel& lv);

    private:
        static void print(std::string_view str, std::string_view col = "", std::string_view reset = "\033[0m");

    private:
        static LogLevel level;
    };

}

#define LOG(str)        GuiBase::Logger::log(str);
#define TRACE(str)      GuiBase::Logger::trace(str);
#define WARN(str)       GuiBase::Logger::warning(str);
#define ERROR(str)      GuiBase::Logger::error(str);
#define CRIT(str)       GuiBase::Logger::critical(str);

