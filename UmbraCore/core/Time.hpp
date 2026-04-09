#pragma once
#include <chrono>

namespace Umbra
{
    class Time
    {
      public:
        Time();
        float DeltaTime;
        void CalculateTime();
        void Init();
    private:
        std::chrono::time_point<std::chrono::steady_clock> previousTime;
    };
}
