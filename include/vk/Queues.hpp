#pragma once

#include "core/Types.hpp"

#include <vulkan/vulkan.h>

namespace usc::vk {
struct QueueFamilyIndices {
    u32 graphicsFamily;
};

QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device) {
    QueueFamilyIndices indices;

    return indices;
}
}