#include "Logger.h"

#include <iostream>

// example <https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal>
// other codes <https://en.wikipedia.org/wiki/ANSI_escape_code#Colors>
// TODO windows colors <https://gist.github.com/Ph0enixKM/5a0d48c440a6dd664d7ae4c807c53008>

namespace GuiBase {
    LogLevel Logger::level = LogLevel::log;

    void Logger::critical(std::string_view str) {
        if (level >= LogLevel::critical) {
            // 41 red bg, 37 white fg
            print(str, "\033[41;37m[crit]: ");
        }
    }

    void Logger::error(std::string_view str) {
        if (level >= LogLevel::error) {
            // 31 red fg, 40 black bg
            print(str, "\033[31;40m[error]: ");
        }
    }

    void Logger::warning(std::string_view str) {
        if (level >= LogLevel::warning) {
            // 33 yellow fg, 40 black bg
            print(str, "\033[33;40m[warn]: ");
        }
    }

    void Logger::trace(std::string_view str) {
        if (level >= LogLevel::trace) {
            // 36 cyan fg, 40 black bg
            print(str, "\033[36;40m[trace]: ");
        }
    }

    void Logger::log(std::string_view str) {
        if (level >= LogLevel::log) {
            print(str, std::string{"[log]: "});
        }
    }

    void Logger::setLogLevel(const LogLevel& lv) {
        level = lv;
    }

    void Logger::print(std::string_view str, std::string_view col, std::string_view reset) {
        std::cout << col << str << reset << '\n';
    }
}
