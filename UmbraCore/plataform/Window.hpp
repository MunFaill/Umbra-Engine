#pragma once

class SDL_Window;

namespace Umbra
{
    class Window
    {
        public:
            Window(const char* title, int width, int height);
            virtual ~Window();
            SDL_Window* GetNativeWindow() const { return m_Window; }
        private:
            void CreateWindow();
            const char* m_Title;
            int m_Width, m_Height;
            SDL_Window* m_Window = {};
    };
}
