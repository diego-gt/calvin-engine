#pragma once

#include "core/Types.hpp"

#include <optional>
#include <vector>
#include <vulkan/vulkan.h>

namespace usc::vk {

struct QueueFamilyIndices {
    std::optional<u32> graphicsFamily;
};

QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device)
{
    QueueFamilyIndices result;

    u32 queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

    return result;
}

}