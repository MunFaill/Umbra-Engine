#pragma once

#include "Time.hpp"
#include "../input/Input.hpp"
#include "../renderer/Renderer.hpp"
#include "../plataform/LayerStack.hpp"

namespace Umbra
{
    class Application
    {
        public:
            Application();
            virtual ~Application();
            
            void Run();

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* overlay);
        private:
            bool m_Running = true;
            Input m_Input;
            Renderer m_Renderer;
            LayerStack m_LayerStack;
            Time m_Time{};
    };
    Application* BindApplication();
}
