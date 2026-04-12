#include <UmbraCore.hpp>

class ExampleLayer : public Umbra::Layer
{
    public:
        ExampleLayer() : Layer("Example")
        {}
        
        void OnWindowResize(int w, int h) override
        {
        }
};

class App : public Umbra::Application
{
    public:
        App()
        {
            PushLayer(new ExampleLayer());
        }
        ~App()
        {}
};

Umbra::Application* Umbra::BindApplication()
{
    return new App;
}
