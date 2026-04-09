#include "Renderer.hpp"
#include "../core/Logger.hpp"
namespace Umbra
{
    void Renderer::Init(SDL_Window* window)
    {
        m_Renderer = SDL_CreateRenderer(window, NULL);

        if (!m_Renderer)
        {
            Umbra::log_fatal_error("Error: No renderer found or created");
        }
    }

    void Renderer::BeginFrame()
    {
        SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);
        SDL_RenderClear(m_Renderer);
    }

    void Renderer::EndFrame()
    {
        SDL_RenderPresent(m_Renderer);
    }
}
