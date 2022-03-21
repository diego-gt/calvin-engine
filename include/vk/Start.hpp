#pragma once

#include "core/Types.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
#include <vector>

namespace usc::vk {
class Application {
public:
    Application(std::string title, i16 width, i16 height);
    void Run();

private:
    void InitializeGLFW();
    void InitializeVulkan();
    void MainLoop();
    void Cleanup();

    // background activities
    void CreateVulkanInstance();
    void PickPhysicalDevice();
    static bool IsPhysicalDeviceSuitable(VkPhysicalDevice device);

    // debugging (messenger and callbacks)
    bool CheckValidationLayerSupport();
    std::vector<const char*> GetRequiredExtensions();

    static VKAPI_ATTR VkBool32 VKAPI_CALL m_debug_callback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData);

    void SetupDebugMessenger();

    static VkResult CreateDebugUtilsMessengerEXT(VkInstance instance,
        const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDebugUtilsMessengerEXT* pDebugMessenger);

    static void DestroyDebugUtilsMessengerEXT(VkInstance instance,
        VkDebugUtilsMessengerEXT debugMessenger,
        const VkAllocationCallbacks* pAllocator);

    static void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    // ++ data ++ //
    // glfw
    std::string m_title;
    i16 m_width, m_height;
    GLFWwindow* m_window;

    // vulkan
    VkInstance m_instance;
    VkPhysicalDevice m_physical_device = VK_NULL_HANDLE;
    VkDebugUtilsMessengerEXT m_debug_messenger;

    const std::vector<const char*> m_validation_layers = { "VK_LAYER_KHRONOS_validation" };
#ifdef NDEBUG
    const bool m_enable_validation_layers = false;
#else
    const bool m_enable_validation_layers = true;
#endif
};
}