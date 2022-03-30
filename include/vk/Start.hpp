#pragma once

#include "core/Types.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
#include <vector>

namespace usc::vk {
class Application {
public:
    // Create a Vulkan/GLFW application instance with a window.
    Application(std::string title, i16 width, i16 height);
    // Entrypoint of the application
    void Run();

private:
    // "Run" API
    // These functions get called by the public API Run();
    // Initializes GLFWwindow instance
    void InitializeGLFW();
    // Initializes Vulkan resources (instance, physical devices, validation layers, etc)
    void InitializeVulkan();
    // acts as a game loop (essentially infinite loop) until we close the window
    void MainLoop();
    // Destroys & frees GLFW and Vulkan resources
    void Cleanup();

    // "Private" API
    // API related to background activities that are called from the Run API, mostly

    // Creates a vulkan instance with the neccessary options for the project.
    // If built in debug mode, this enables validation layers and their outputs.
    void CreateVulkanInstance();

    // Lists all physical devices in the system with Vulkan support
    // and chooses one based on our requirements.
    void PickPhysicalDevice();

    // Evaluates a given physical device given certain criteria.
    static bool IsPhysicalDeviceSuitable(VkPhysicalDevice device);

    // debugging helpers (messenger and callbacks)

    // Validates that the validation layers required for the application are present in the system.
    bool CheckValidationLayerSupport();

    // Gets required Vulkan extensions for GLFW and validation layer support.
    std::vector<const char*> GetRequiredExtensions();

    // Formats and prints out debug info from validation layers.
    static VKAPI_ATTR VkBool32 VKAPI_CALL m_debug_callback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData);

    // Setup a debug messenger for the private Vulkan instance
    void SetupDebugMessenger();

    // Handle creation of a debug messenger for a given Vulkan instance.
    static VkResult CreateDebugUtilsMessengerEXT(VkInstance instance,
        const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDebugUtilsMessengerEXT* pDebugMessenger);

    // Handle deletion of a debug messenger for a given Vulkan instance.
    static void DestroyDebugUtilsMessengerEXT(VkInstance instance,
        VkDebugUtilsMessengerEXT debugMessenger,
        const VkAllocationCallbacks* pAllocator);

    // Set debug messenger settings (message severity, types, etc)
    static void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    // ++ data members ++ //
    // glfw
    // Title of the application.
    std::string m_title;
    // Dimensions of the application's window.
    i16 m_width, m_height;
    // GLFW window handle
    GLFWwindow* m_window;

    // vulkan
    // Private, main Vulkan instance
    VkInstance m_instance;
    // Physical device in charge of handling Vulkan instructions
    VkPhysicalDevice m_physical_device = VK_NULL_HANDLE;
    // Debug messenger to handle validation layers outputs
    VkDebugUtilsMessengerEXT m_debug_messenger;

    // Required validation layers for the application
    const std::vector<const char*> m_validation_layers = { "VK_LAYER_KHRONOS_validation" };

    // Only enable validation layers if project is built in a Debug configuration
#ifdef NDEBUG
    const bool m_enable_validation_layers = false;
#else
    const bool m_enable_validation_layers = true;
#endif
};
}