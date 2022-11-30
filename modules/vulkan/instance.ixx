export module null.vulkan:instance;
import null.c.vulkan;
import :app_info;
import :extension;
import :layer;
import :physical_device;
import <vector>;
import <iostream>;
using namespace std;
export namespace null
{
	class instance
	{
	public:
		instance(const app_info& app, const vector<extension>& extensions, const vector<layer>& layers)
		{
			VkInstanceCreateInfo createInfo{};
			createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
			// App Info
			VkApplicationInfo appInfo = *reinterpret_cast<const VkApplicationInfo*>(&app);
			createInfo.pApplicationInfo = &appInfo;
			// Extensions
			auto extension_names = convert_to_names(extensions);
			createInfo.enabledExtensionCount = (uint32_t)extension_names.size();
			createInfo.ppEnabledExtensionNames = extension_names.data();
			// Layers
			auto layer_names = convert_to_names(layers);
			createInfo.enabledLayerCount = (uint32_t)layer_names.size();
			createInfo.ppEnabledLayerNames = layer_names.data();
			// Creation
			bool created = false;
			while (!created)
			{
				VkResult result = vkCreateInstance(&createInfo, nullptr, &this->m_handle);
				switch (result)
				{
				case VkResult::VK_SUCCESS:
					created = true;
					break;
				case VkResult::VK_ERROR_LAYER_NOT_PRESENT:
					if (createInfo.ppEnabledLayerNames != 0 && createInfo.ppEnabledLayerNames[0] == "VK_LAYER_KHRONOS_validation")
						std::cout << "LunarSDK is not installed - Creating instance without validation layers...";
					createInfo.enabledLayerCount = 0;
					createInfo.ppEnabledLayerNames = 0;
					break;
			
				default:
					throw std::exception("Failed to create Vulkan instance");
				}
			}
			// Pre-storing physical devices
			VkPhysicalDevice handles[16] = { 0 };
			uint32_t count;
			vkEnumeratePhysicalDevices(this->m_handle, &count, nullptr);
			vkEnumeratePhysicalDevices(this->m_handle, &count, handles); // would love to do with 1 call but Vulkan will crash in release mode so we doing it standard
			if (count == 0) throw std::runtime_error("No physical devices with Vulkan support were found");
			this->m_physical_devices.resize(count);
			int i = 0;
			for (auto& dev : this->m_physical_devices)
			{
				// We cannot use handles[--count] because that'd reverse the list. Order is important because it indicates priority.
				dev = physical_device(handles[i++]);
				uint32_t qfamily_count = 0;
				vkGetPhysicalDeviceQueueFamilyProperties(dev.m_handle, &qfamily_count, nullptr);
				VkQueueFamilyProperties qfamilies[32];
				vkGetPhysicalDeviceQueueFamilyProperties(dev.m_handle, &qfamily_count, qfamilies);
				dev.m_families = filterable<queue_family>(qfamily_count);
				for (uint32_t i = 0; i < qfamily_count; ++i)
				{
					queue_family& fam = dev.m_families[i];
					fam.m_parent = &dev;
					fam.m_properties = qfamilies[i];
					fam.m_index = i;
					fam.m_num_queues_requested = 1;
				}
			}
		}
	private:
		template<typename List>
		static auto convert_to_names(const List& list) -> std::vector<const char*>
		{
			std::vector<const char*> strings;
			strings.reserve(list.size());
			for (auto& it : list) strings.push_back(it.name);
			return strings;
		}
		std::vector<physical_device> m_physical_devices;
		VkInstance m_handle;
	};
}