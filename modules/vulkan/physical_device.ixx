export module null.vulkan:physical_device;
import null.c.vulkan;
import :queue_family;
import null.filterable;
export namespace null
{
	class instance;
	class physical_device
	{
	public:
		VkPhysicalDeviceProperties properties{};
		physical_device() {}
	private:
		inline physical_device(const VkPhysicalDevice& handle) : m_handle(handle)
		{
			vkGetPhysicalDeviceProperties(this->m_handle, &this->properties);
			vkGetPhysicalDeviceFeatures(this->m_handle, &this->m_features);

		}
		VkPhysicalDevice m_handle;
		VkPhysicalDeviceFeatures m_features{};
		filterable<queue_family> m_families;
		friend class instance;
	};
}