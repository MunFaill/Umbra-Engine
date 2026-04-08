#pragma once

// STD
#include <string>

namespace Umbra
{
    void log_warning(std::string message);
    void log_fatal_error(std::string message);
    void log_error(std::string message);
    void log_message(std::string message);
} // namespace Umbra
