#include "Logger.hpp"

// STD
#include <iostream>
#include <stdexcept>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

std::string return_current_time_and_date() {
    // Get the current time point
    auto now = std::chrono::system_clock::now();

    // Convert to a C-style time_t
    std::time_t in_time_t = std::chrono::system_clock::to_time_t(now);

    // Convert to local time (note: std::localtime may not be thread-safe)
    std::tm buf = {};
    #ifdef _WIN32
    localtime_s(&buf, &in_time_t); // Use safer Windows version
    #else
    localtime_r(&in_time_t, &buf); // Use safer POSIX version (if available)
    #endif

    // Format the time into a string
    std::stringstream ss;
    ss << std::put_time(&buf, "%Y-%m-%d %X"); // %Y-%m-%d %X is YYYY-MM-DD HH:MM:SS format
    return ss.str();
}

namespace Umbra
{
    void log_warning(std::string message)
    {
        std::cout << "\033[1;33m[" << return_current_time_and_date() << "]" << " " << message << "\033[0m\n";
    }
    void log_fatal_error(std::string message)
    {
        throw std::runtime_error("\033[1;31m[" + return_current_time_and_date() + "] " + message + "\033[0m\n");
    }
    void log_error(std::string message)
    {
        std::cout << "\033[1;31m[" << return_current_time_and_date() << "]" << " " << message << "\033[0m\n";
    }
    void log_message(std::string message)
    {
        std::cout << "\033[1;34m[" << return_current_time_and_date() << "]" << " " << message << "\033[0m\n";
    }
} // namespace Umbra
