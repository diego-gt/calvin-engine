#include "vk/Start.hpp"
#include <iostream>

int main()
{
    usc::vk::Application app("Test", 800, 600);

    try {
        app.Run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
