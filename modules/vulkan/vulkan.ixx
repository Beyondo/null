export module null.vulkan;
import null.c.vulkan;
import :engine_info;
import :app_info;
import :extension;
import :layer;
import :instance;
import :device;
import :command_pool;
import <vector>;
using namespace std;
#define use(m) using m = m
export namespace null
{
    class vk
    {
    public:
        vk(const vk&) = delete;
        /* Handles */

        using offset2d = VkOffset2D;
        using bool32 = uint32_t;
        using flags = uint32_t;
        using pipeline_stage_flags = flags;
        using swapchain_handle = VkSwapchainKHR;
        using pipeline = VkPipeline;
        using pipeline_layout = VkPipelineLayout;
        using image = VkImage;
        using framebuffer = VkFramebuffer;
        using image_view = VkImageView;
        using semaphore = VkSemaphore;
        using fence = VkFence;
		
        /* Enums */
        
        /* KHR */ 
        
        /* Structures */
		
        // A structure specifying information about a Vulkan app.
        use(app_info);
		// A structure specifying information about a Vulkan engine.
        use(engine_info);
        // A structure specifying information about a Vulkan extension.
        use(extension);
        // A structure specifying information about a Vulkan layer.
        use(layer);
		
        /* Objects */
		
		// An object managing a Vulkan instance.
        use(instance);
		// An object managing a Vulkan command pool.
        use(command_pool);

		/* Methods */

        /** Creates a Vulkan instance
        * \param info Information about the vulkan application
        * \param extensions The extensions to create the Vulkan instance with
        * \param layers The layers to create the Vulkan instance with
        * \return A Vulkan instance
        */
        static auto create(
            const app_info& info = default_app_info,
            const vector<vk::extension>& extensions = {},
            const vector<vk::layer>& layers = {}
        ) -> instance* {
            return new vk::instance(info, extensions, layers);
        }
        ////
        //static constexpr uint32_t undetermined_extent = std::numeric_limits<uint32_t>::max();
        static const inline vk::app_info default_app_info = default_app_info;
        static const inline vk::engine_info default_engine_info = default_engine_info;
        static vk::extension swapchain_extension;
    };
    // None of the following would concern anyone but me.
    // ------------------------------------------------------------------------------------
    // The main module was built using "using" instead of forward declarations due to the fact that C++, at least in MSVC,
	// would only import the "empty" forward declarations of the subclasses and not the definitions.
    // This is a problem because these subclasses are not defined in the main unit, but in a partitioned module.
	// Thus something like "class vk::instance {};" in another module file would not work
	// 1. It'd cause a cyclic dependency between the main module and the partitioned module.
	// 2. And if you seprated the main unit into an interface to prevent cyclism, it'd work but would cause another error.
    // ------------------------------------------------------------------------------------
    // Thus there 5 ways to fix this problem:
	// 1. Use "namespace vk" instead of "class vk" in the main module (which would result in conflicts if someone used it).
	// 2. Implement everything in the main module (which is hellishly messy).
	// 3. Use "using" instead of forward declarations and name the sub-units with other names. (which is also messy)
	// 4. Use vk_ instead of vk:: for all sub-units (which is not so C++-like).
    // 4. Wait for the C++ comitte to implement a feature like "namespace class" which is basically a namespace
    //    that cannot be used with "using namespace" or a class that can be expanded by multiple units making our life easier
	//    but I think we all know that wouldn't happen.
	// -> Option 3 was chosen.
}