#pragma once

#include "../input/Input.hpp"

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
    };
    Application* BindApplication();
}
