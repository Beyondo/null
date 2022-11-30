export module null.vulkan:app_info;
import null.c.vulkan;
import :engine_info;
export namespace null
{
    struct app_info
    {
        app_info()
        {
        }
        // app_info(const std::string& name, const uint32_t version, const vk::engine& engine = vk::default_engine)
        // {
        //     this->name = name.c_str();
        //     this->version = version;
        //     this->engine = engine;
        // }
    private:
        VkStructureType type = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        const void* pNext = nullptr;
    public:
        const char* name = "Null-Void App";
        uint32_t version = VK_MAKE_VERSION(0, 0, 1);
        engine_info engine = default_engine_info;
        uint32_t api_version = VK_API_VERSION_1_3;
    };
    inline app_info default_app_info;
}