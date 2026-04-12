#pragma once

#include "Keycode.hpp"
#include <functional>
#include <vector>

namespace Umbra
{   
    using ResizeEventFn = std::function<void(int width, int height)>;
    using GenericEventFn = std::function<void()>;

    class Input
    {
    public:
        void Update();

        bool IsKeyPressed(Key key);
        bool IsKeyDown(Key key);
        bool IsKeyUp(Key key);
        bool ShouldQuit() const;

        void OnWindowResize(ResizeEventFn func) { m_ResizeCallbacks.push_back(func); }
        void OnMouseMotion(GenericEventFn func) { m_MouseMotionCallbacks.push_back(func); }
        void OnSceneOpen(GenericEventFn func)   { m_SceneOpenCallbacks.push_back(func); }

        void TriggerSceneOpen();

    private:
        bool m_Keys[SDL_SCANCODE_COUNT] = {};
        bool m_KeysDown[SDL_SCANCODE_COUNT] = {};
        bool m_KeysUp[SDL_SCANCODE_COUNT] = {};
        bool m_ShouldQuit = false;

        std::vector<ResizeEventFn> m_ResizeCallbacks;
        std::vector<GenericEventFn> m_MouseMotionCallbacks;
        std::vector<GenericEventFn> m_SceneOpenCallbacks;
    };
}