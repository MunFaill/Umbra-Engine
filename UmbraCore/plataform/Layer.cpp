#include "Layer.hpp"

/*
Based on 'The Cherno Hazel Engine' layer system. https://www.youtube.com/@TheCherno
*/

namespace Umbra
{
    Layer::Layer(const std::string& debugName) : m_DebugName(debugName)
    {}

    Layer::~Layer()
    {}
} // namespace Umbra
