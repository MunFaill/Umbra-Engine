#include <UmbraCore.hpp>

class App : public Umbra::Application
{
    public:
        App()
        {

        }
        ~App()
        {

        }
};

Umbra::Application* Umbra::BindApplication()
{
    return new App;
}
