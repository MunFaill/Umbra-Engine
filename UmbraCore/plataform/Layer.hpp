#pragma once

/*
Based on 'The Cherno Hazel Engine' layer system. https://www.youtube.com/@TheCherno
*/

#include <string>

namespace Umbra
{
    class Layer
    {
        public:
            Layer(const std::string& name = "Layer");
            virtual ~Layer();

            virtual void OnAttach() {}
            virtual void OnDetach() {}
            virtual void OnUpdate(float dt) {}

            inline const std::string& GetName() const { return m_DebugName; }
        private:
            std::string m_DebugName;
    };
} // namespace Umbra
