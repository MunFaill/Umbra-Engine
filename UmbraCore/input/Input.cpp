#include "Input.hpp"
#include "../core/Logger.hpp"

namespace Umbra
{
    void Input::Update()
    {
        for (int i = 0; i < SDL_SCANCODE_COUNT; i++)
        {
            m_KeysDown[i] = false;
            m_KeysUp[i] = false;
        }

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_EVENT_QUIT:
                    m_ShouldQuit = true;
                    break;

                case SDL_EVENT_WINDOW_RESIZED:
                    for (auto& cb : m_ResizeCallbacks)
                        cb(event.window.data1, event.window.data2);
                    break;

                case SDL_EVENT_MOUSE_MOTION:
                    for (auto& cb : m_MouseMotionCallbacks)
                        cb();
                    break;

                case SDL_EVENT_KEY_DOWN:
                    if (!m_Keys[event.key.scancode])
                    {
                        m_KeysDown[event.key.scancode] = true;
                    }
                    m_Keys[event.key.scancode] = true;
                    break;

                case SDL_EVENT_KEY_UP:
                    m_Keys[event.key.scancode] = false;
                    m_KeysUp[event.key.scancode] = true;
                    break;
            }
        }
    }

    void Input::TriggerSceneOpen()
    {
        for (auto& cb : m_SceneOpenCallbacks)
            cb();
    }

    bool Input::IsKeyPressed(Key key)
    {
        return m_Keys[(int)key];
    }
    bool Input::IsKeyDown(Key key)
    {
        return m_KeysDown[(int)key];
    }
    bool Input::IsKeyUp(Key key)
    {
        return m_KeysUp[(int)key];
    }
    bool Input::ShouldQuit() const
    {
        return m_ShouldQuit;
    }
}