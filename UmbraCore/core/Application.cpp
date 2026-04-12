#include "Application.hpp"

#include "Logger.hpp"
#include "../plataform/Window.hpp"

namespace Umbra
{
    Application::Application()
    {
        m_Input.OnWindowResize([this](int w, int h)
        {
            for (Layer* layer : m_LayerStack)
            {
                layer->OnWindowResize(w, h);
            }
        });


        log_message("Umbra Application Constructor ready");
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            log_warning("Failed to initialize SDL");
        }
    }

    Application::~Application()
    {
        log_warning("Umbra Application deleted");
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer* overlay)
    {
        m_LayerStack.PushOverlay(overlay);
    }

    void Application::Run()
    {
        log_message("Application running");
        Window window("Umbra Engine", 800, 600);
        m_Renderer.Init(window.GetNativeWindow());
        while (!m_Input.ShouldQuit())
        {
            m_Time.CalculateTime();
            m_Input.Update();
            m_Renderer.BeginFrame();
            m_Renderer.EndFrame();

            for (Layer* layer : m_LayerStack)
            {
                layer->OnUpdate(m_Time.DeltaTime);
            }
        }
    }
}
