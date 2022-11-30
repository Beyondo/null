export module null.vulkan:engine_info;
import null.c.vulkan;
export namespace null
{
    struct engine_info
    {
        const char* name = "VoidOps Engine / Null © voidops.com";
        uint32_t version = VK_MAKE_VERSION(0, 1, 0);
    };
    inline engine_info default_engine_info;
}