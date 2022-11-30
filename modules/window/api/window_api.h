#pragma once
#include <map>
#include <string>
//#include <null/math.hpp>
//#include <void-h/graphics/graphics.h>
namespace null
{
	class window_style
	{
		void* icon;
		void* cursor;
	};
	inline constexpr auto window_default_width = 1280;
	inline constexpr auto window_default_height = 720;
	inline constexpr auto window_default_title = L"VOID Window";
	class window_api
	{
	public:
		//auto setup_graphics(gfx::api api, const gfx::config& configuration)->gfx::context*;
		//template<typename Size = null::area<float>>
		//auto size()const->Size;
		//template<typename Size = null::area<float>>
		//auto frame_size()const->Size;
		// Do not use with Vulkan.
		static void gl_swap_buffers(void* native_handle);
		static void update(void* native_handle);
		// Checks if any events are triggered, process them, then calls the respective callbacks
		static void poll_events(void* native_handle);
		//
		static void wait_events(void* native_handle);
		// Shows the window
		static void show(void* native_handle);
		// Hides the window
		static void hide(void* native_handle);
		/** Modifies the visibility of the window
		* \param visibility whether the window should be visible or not
		*/
		static void set_visibility(void* native_handle, bool visibility);
		static auto title(void* native_handle) ->std::string;
		static auto wtitle(void* native_handle) ->std::wstring;
		// Returns a boolean indicating whether the current window is visible or not.
		static bool visible(void* native_handle);
		/** Constructs a Null++ window
		* \param width Initial width of the window
		* \param height Initial height of the window
		* \param title Initial title of the window
		* \param shown Initial visibility of the window
		* \param x Initial x-axis position of the window
		* \param y Initial y-axis position of the window
		* \param flags Flags for window creation
		*/
		template<typename Title>
		static constexpr auto create(
			int width = window_default_width,
			int height = window_default_height,
			const Title& title = window_default_title,
			bool shown = true,
			int x = 0,
			int y = 0,
			int flags = 0)->void*;
		// Triggered on deletion/destruction
		static auto create() -> void*;
		static void destroy(void* native_handle);
	private:
		//null::area<uint32_t> prev_size;
		//gfx::context* m_context = nullptr;
		// TODO: Add "void* window_ptr" parameter
		static inline auto create(int x, int y, int width, int height, const std::wstring& title, bool visible, int flags)-> void*;
		static inline auto create(int x, int y, int width, int height, const std::string& title, bool visible, int flags) -> void*;
		static inline auto create(int x, int y, int width, int height, const char* title, bool visible, int flags) -> void*;
		static inline auto create(int x, int y, int width, int height, const wchar_t* title, bool visible, int flags) -> void*;
		//
		class platform_specific;
	};
}