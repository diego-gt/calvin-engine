#pragma once

#include "core/Types.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace usc::vk {
class Application {
public:
Application(std::string  title, i16 width, i16 height);
    void Run();
private:
    void InitializeGLFW();
    void InitializeVulkan();
    void MainLoop();
    void Cleanup();

    void CreateVulkanInstance();

    // glfw
    std::string m_title;
    i16 m_width, m_height;
    GLFWwindow* m_window;

    // vulkan
    VkInstance m_instance;
};
}