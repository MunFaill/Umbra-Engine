#include "Application.hpp"

#include "Logger.hpp"

namespace Umbra
{
    Application::Application()
    {
        log_message("Umbra Application Constructor ready");
    }

    Application::~Application()
    {
        log_warning("Umbra Application deleted");
    }

    void Application::Run()
    {
        log_message("Application running");
        while (m_Running);
    }
}
