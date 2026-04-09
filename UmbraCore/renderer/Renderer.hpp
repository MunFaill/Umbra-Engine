#pragma once

#include <SDL3/SDL.h>

namespace Umbra
{
    class Renderer
    {
        public:
            void Init(SDL_Window* window);
            void BeginFrame();
            void EndFrame();
        private:
            SDL_Renderer* m_Renderer;
    };
}
