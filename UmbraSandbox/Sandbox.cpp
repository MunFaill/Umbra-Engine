#include <UmbraCore.hpp>

class ExampleLayer : public Umbra::Layer
{
    public:
        ExampleLayer() : Layer("Example")
        {}
        void OnUpdate(float dt) override
        {
            Umbra::log_message("Example layer");
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
