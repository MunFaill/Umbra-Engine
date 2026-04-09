#include "Time.hpp"

namespace Umbra
{
    Time::Time()
    {
        Init();
    }
    void Time::Init()
    {
        previousTime = std::chrono::steady_clock::now();
    }
    void Time::CalculateTime()
    {
        auto CurrentTime = std::chrono::steady_clock::now();
        std::chrono::duration<float> elapsed = CurrentTime - previousTime;
        DeltaTime = elapsed.count();
        previousTime = CurrentTime;
    }
}
