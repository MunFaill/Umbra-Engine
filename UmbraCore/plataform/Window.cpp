#include "Window.hpp"
#include <SDL3/SDL.h>
#include "../core/Logger.hpp"

namespace Umbra
{
    Window::Window(const char* title, int width, int height) : m_Title(title), m_Width(width), m_Height(height)
    {
        log_message("Initializing window creation.");
        CreateWindow();
    }
    Window::~Window()
    {
        SDL_DestroyWindow(m_Window);
    }

    void Window::CreateWindow()
    {
        m_Window = SDL_CreateWindow(m_Title, m_Width, m_Height, SDL_WINDOW_RESIZABLE);
        if (!m_Window)
        {
            log_fatal_error(std::string("SDL Error: ") + SDL_GetError());
        }
        log_message("Window created with success");
    }
}
