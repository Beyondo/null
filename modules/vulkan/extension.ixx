export module null.vulkan:extension;
import null.c.vulkan;
export namespace null
{
	struct extension
	{
		operator char*()
		{
			return this->name;
		}
		char name[VK_MAX_EXTENSION_NAME_SIZE]; // Extension name
		uint32_t version; // Extension spec version
	};
}