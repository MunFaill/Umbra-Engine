#pragma once

#include "Logger.hpp"

extern Umbra::Application* Umbra::BindApplication();

int main()
{
    auto app = Umbra::BindApplication();
    app->Run();
    delete app;
}
