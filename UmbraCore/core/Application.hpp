#pragma once

#include "../input/Input.hpp"
#include "../renderer/Renderer.hpp"

namespace Umbra
{
    class Application
    {
        public:
            Application();
            virtual ~Application();
            void Run();
        private:
            bool m_Running = true;
            Input m_Input;
            Renderer m_Renderer;
    };
    Application* BindApplication();
}
