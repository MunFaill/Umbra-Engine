#pragma once

/*
Based on 'The Cherno Hazel Engine' layer system. https://www.youtube.com/@TheCherno
*/

#include "Layer.hpp"
#include <vector>

namespace Umbra
{
    class LayerStack
    {
        public:
            LayerStack();
            ~LayerStack();

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* overlay);
            void PopLayer(Layer* Layer);
            void PopOverlay(Layer* overlay);

            std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
            std::vector<Layer*>::iterator end() { return m_Layers.end(); }
        private:
            std::vector<Layer*> m_Layers;
            std::vector<Layer*>::iterator m_LayerInsert;
    };
} // namespace Umbra
