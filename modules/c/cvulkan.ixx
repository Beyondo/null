export module null.c.vulkan;
export import "dep/vulkan/vulkan.h";
import <stdexcept>;
using namespace std;
#ifndef NULL_USE_VULKAN
#pragma warning( disable : 4297 )
#define VULKAN_NOT_USED_MSG "You've to define NULL_USE_VULKAN and link to vulkan-1 in order to use this module"
VKAPI_ATTR VkResult vkCreateInstance(
    const VkInstanceCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkInstance* pInstance)
{
    throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyInstance(
    VkInstance                                  instance,
    const VkAllocationCallbacks* pAllocator)
{
    throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDevices(
    VkInstance                                  instance,
    uint32_t* pPhysicalDeviceCount,
    VkPhysicalDevice* pPhysicalDevices)
{
    throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}

VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties* pProperties)
{
    throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2* pProperties)
{
    throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures* pFeatures)
{
    throw runtime_error(VULKAN_NOT_USED_MSG);
}

VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t* pQueueFamilyPropertyCount,
    VkQueueFamilyProperties* pQueueFamilyProperties)
{
    throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties2(
	VkPhysicalDevice                            physicalDevice,
	uint32_t* pQueueFamilyPropertyCount,
	VkQueueFamilyProperties2* pQueueFamilyProperties)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties(
	VkPhysicalDevice                            physicalDevice,
	VkPhysicalDeviceMemoryProperties* pMemoryProperties)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties2(
	VkPhysicalDevice                            physicalDevice,
	VkPhysicalDeviceMemoryProperties2* pMemoryProperties)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures2(
	VkPhysicalDevice                            physicalDevice,
	VkPhysicalDeviceFeatures2* pFeatures)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties(
	VkPhysicalDevice                            physicalDevice,
	VkFormat                                    format,
	VkFormatProperties* pFormatProperties)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties2(
	VkPhysicalDevice                            physicalDevice,
	VkFormat                                    format,
	VkFormatProperties2* pFormatProperties)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDevice(
	VkPhysicalDevice                            physicalDevice,
	const VkDeviceCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkDevice* pDevice)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDevice(
	VkDevice                                    device,
	const VkAllocationCallbacks* pAllocator)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(
	const char* pLayerName,
	uint32_t* pPropertyCount,
	VkExtensionProperties* pProperties)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceExtensionProperties(
	VkPhysicalDevice                            physicalDevice,
	const char* pLayerName,
	uint32_t* pPropertyCount,
	VkExtensionProperties* pProperties)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(
	uint32_t* pPropertyCount,
	VkLayerProperties* pProperties)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceLayerProperties(
	VkPhysicalDevice                            physicalDevice,
	uint32_t* pPropertyCount,
	VkLayerProperties* pProperties)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceQueue(
	VkDevice                                    device,
	uint32_t                                    queueFamilyIndex,
	uint32_t                                    queueIndex,
	VkQueue* pQueue)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit(
	VkQueue                                     queue,
	uint32_t                                    submitCount,
	const VkSubmitInfo* pSubmits,
	VkFence                                     fence)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueWaitIdle(
	VkQueue                                     queue)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR VkResult VKAPI_CALL vkDeviceWaitIdle(
	VkDevice                                    device)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAllocateMemory(
	VkDevice                                    device,
	const VkMemoryAllocateInfo* pAllocateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkDeviceMemory* pMemory)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR void VKAPI_CALL vkFreeMemory(
	VkDevice                                    device,
	VkDeviceMemory                              memory,
	const VkAllocationCallbacks* pAllocator)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR VkResult VKAPI_CALL vkMapMemory(
	VkDevice                                    device,
	VkDeviceMemory                              memory,
	VkDeviceSize                                offset,
	VkDeviceSize                                size,
	VkMemoryMapFlags                            flags,
	void** ppData)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR void VKAPI_CALL vkUnmapMemory(
	VkDevice                                    device,
	VkDeviceMemory                              memory)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR VkResult VKAPI_CALL vkFlushMappedMemoryRanges(
	VkDevice                                    device,
	uint32_t                                    memoryRangeCount,
	const VkMappedMemoryRange* pMemoryRanges)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR VkResult VKAPI_CALL vkInvalidateMappedMemoryRanges(
	VkDevice                                    device,
	uint32_t                                    memoryRangeCount,
	const VkMappedMemoryRange* pMemoryRanges)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceMemoryCommitment(
	VkDevice                                    device,
	VkDeviceMemory                              memory,
	VkDeviceSize* pCommittedMemoryInBytes)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory(
	VkDevice                                    device,
	VkBuffer                                    buffer,
	VkDeviceMemory                              memory,
	VkDeviceSize                                memoryOffset)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory(
	VkDevice                                    device,
	VkImage                                     image,
	VkDeviceMemory                              memory,
	VkDeviceSize                                memoryOffset)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements(
	VkDevice                                    device,
	VkBuffer                                    buffer,
	VkMemoryRequirements* pMemoryRequirements)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements(
	VkDevice                                    device,
	VkImage                                     image,
	VkMemoryRequirements* pMemoryRequirements)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements(
	VkDevice                                    device,
	VkImage                                     image,
	uint32_t* pSparseMemoryRequirementCount,
	VkSparseImageMemoryRequirements* pSparseMemoryRequirements)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties(
	VkPhysicalDevice                            physicalDevice,
	VkFormat                                    format,
	VkImageType                                 type,
	VkSampleCountFlagBits                       samples,
	VkImageUsageFlags                           usage,
	VkImageTiling                               tiling,
	uint32_t* pPropertyCount,
	VkSparseImageFormatProperties* pProperties)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueBindSparse(
	VkQueue                                     queue,
	uint32_t                                    bindInfoCount,
	const VkBindSparseInfo* pBindInfo,
	VkFence                                     fence)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateFence(
	VkDevice                                    device,
	const VkFenceCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkFence* pFence)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyFence(
	VkDevice                                    device,
	VkFence                                     fence,
	const VkAllocationCallbacks* pAllocator)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
}
VKAPI_ATTR VkResult VKAPI_CALL vkResetFences(
	VkDevice                                    device,
	uint32_t                                    fenceCount,
	const VkFence* pFences)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceStatus(
	VkDevice                                    device,
	VkFence                                     fence)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
VKAPI_ATTR VkResult VKAPI_CALL vkWaitForFences(
	VkDevice                                    device,
	uint32_t                                    fenceCount,
	const VkFence* pFences,
	VkBool32                                    waitAll,
	uint64_t                                    timeout)
{
	throw runtime_error(VULKAN_NOT_USED_MSG);
	return VK_NOT_READY;
}
#endif