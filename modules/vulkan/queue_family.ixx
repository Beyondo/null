export module null.vulkan:queue_family;
import null.c.vulkan;
export namespace null
{
	class physical_device;
	class instance;
	class queue_family
	{
	public:
		
	private:
		const physical_device* m_parent;
		uint32_t m_index;
		uint32_t m_num_queues_requested;
		float m_priorities[16] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
		VkQueueFamilyProperties m_properties;
		friend class instance;
	};
}