#pragma once

#include "Keycode.hpp"

namespace Umbra
{   
    class Input
    {
    public:
        void Update();

        bool IsKeyPressed(Key key);
        bool IsKeyDown(Key key);
        bool IsKeyUp(Key key);

        bool IsMouseMotion() const;
        bool ShouldQuit() const;

    private:
        bool m_Keys[SDL_SCANCODE_COUNT] = {};
        bool m_KeysDown[SDL_SCANCODE_COUNT] = {};
        bool m_KeysUp[SDL_SCANCODE_COUNT] = {};

        bool m_ShouldQuit = false;
    };
}