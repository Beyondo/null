#ifdef _WIN32
#include "window_api.h"
#include <vector>
#include <Windows.h>
#define NULL_CLASS_NAME L"VOID Operations"
namespace null
{
	class window_api::platform_specific
	{
		static inline WNDCLASS winclass = {};
		static inline bool class_registered = false;
		static inline LRESULT CALLBACK win32_winproc(HWND wHandle, UINT wMessage, WPARAM wParam, LPARAM lParam)
		{
			//window* win = reinterpret_cast<window*>(GetWindowLongPtr(wHandle, GWLP_USERDATA));
			//if (win)
			//{
			//	switch (wMessage)
			//	{
			//	case WM_SIZING:
			//		//if (win->m_context) win->m_context->frame_resized_handler();
			//		if (win->on_frame_resized.count())
			//		{
			//			window_frame_resized_event frame_e;
			//			frame_e.m_window = win;
			//			if (win->on_frame_resized.dispatch(frame_e))
			//				return true;
			//		}
			//		if (win->on_resizing.count())
			//		{
			//			RECT* new_rect = reinterpret_cast<RECT*>(lParam);
			//			window_resizing_event e;
			//			e.m_window = win;
			//			e.m_width = new_rect->right - new_rect->left;
			//			e.m_height = new_rect->bottom - new_rect->top;
			//			if (win->on_resizing.dispatch(e))
			//				return true;
			//		}
			//		break;
			//	case WM_SIZE:
			//		//if (win->m_context) win->m_context->frame_resized_handler();
			//		if (win->on_frame_resized.count())
			//		{
			//			window_frame_resized_event frame_e;
			//			frame_e.m_window = win;
			//			if (win->on_frame_resized.dispatch(frame_e))
			//				return true;
			//		}
			//		if (win && win->on_resized.count())
			//		{
			//			window_resized_event e;
			//			e.m_window = win;
			//			if (win->on_resized.dispatch(e))
			//				return true;
			//		}
			//		break;
			//	case WM_CLOSE:
			//		//if (win->m_context) win->m_context->window_closing_handler();
			//		if (win->on_closing.count())
			//		{
			//			window_closing_event e;
			//			e.m_window = win;
			//			if (win->on_closing.dispatch(e))
			//				return true;
			//		}
			//		win->state_running = false;
			//		DestroyWindow(wHandle);
			//		break;
			//	case WM_DESTROY:
			//		PostQuitMessage(0);
			//		return 0;
			//	}
			//}
			return DefWindowProc(wHandle, wMessage, wParam, lParam);
		}
		friend window_api;
	};
	//template<typename Size>
	//inline auto window_api::size()const->Size
	//{
	//	Size result;
	//	RECT rect;
	//	GetWindowRect((HWND)handle, &rect);
	//	result.width = static_cast<decltype(result.width)>(rect.right);
	//	result.height = static_cast<decltype(result.height)>(rect.bottom);
	//	return result;
	//}
	//template<typename Size>
	//inline auto window_api::frame_size()const->Size
	//{
	//	Size result;
	//	RECT rect;
	//	GetClientRect((HWND)handle, &rect);
	//	result.width = static_cast<decltype(result.width)>(rect.right);
	//	result.height = static_cast<decltype(result.height)>(rect.bottom);
	//	return result;
	//}
	inline void window_api::gl_swap_buffers(void* native_handle)
	{
		SwapBuffers(GetDC((HWND)native_handle));
	}
	inline void window_api::update(void* native_handle)
	{
		UpdateWindow((HWND)native_handle);
	}
	inline void window_api::wait_events(void* native_handle)
	{
		WaitMessage();
		poll_events(native_handle);
	}
	inline void window_api::poll_events(void* native_handle)
	{
		MSG msg = {};
		if (PeekMessage(&msg, (HWND)native_handle, 0u, 0u, PM_REMOVE))
		{
			//TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	inline void window_api::show(void* native_handle)
	{
		ShowWindow((HWND)native_handle, 1);
	}
	inline void window_api::hide(void* native_handle)
	{
		ShowWindow((HWND)native_handle, 0);
	}
	inline auto window_api::title(void* native_handle) ->std::string
	{
		char title[256] = { 0 };
		GetWindowTextA((HWND)native_handle, title, 256);
		return std::string(title);
	}
	inline auto window_api::wtitle(void* native_handle) ->std::wstring
	{
		wchar_t wtitle[256] = { 0 };
		GetWindowTextW((HWND)native_handle, wtitle, 256);
		return std::wstring(wtitle);
	}
	inline bool window_api::visible(void* native_handle)
	{
		return IsWindowVisible((HWND)native_handle);
	}
	inline void window_api::set_visibility(void* native_handle, bool visibility)
	{
		ShowWindow((HWND)native_handle, (int)visibility);
	}
	inline auto window_api::create()->void*
	{
		return create(0, 0, window_default_width, window_default_height, window_default_title, true, 0);
	}
	template<typename Title>
	constexpr auto window_api::create(int width, int height, const Title& title, bool visible, int x, int y, int flags)->void*
	{
		return create(x, y, width, height, title, visible, flags);
	}
	inline void window_api::destroy(void* native_handle)
	{
		///state_running = false;
	}

	inline auto window_api::create(int x, int y, int width, int height, const std::wstring& title, bool visible, int flags)->void*
	{
		return create(x, y, width, height, title.c_str(), visible, flags);
	}
	inline auto window_api::create(int x, int y, int width, int height, const std::string& title, bool visible, int flags)->void*
	{
		return create(x, y, width, height, std::wstring(title.begin(), title.end()), visible, flags);
	}
	inline auto window_api::create(int x, int y, int width, int height, const char* title, bool visible, int flags)->void*
	{
		// Converts char* to wchar_t* and calls create(int, int, int, int, const wchar_t*, bool, int)
		// Reason: Consistency
		auto sz = strlen(title) + 1;
		wchar_t* title_w = new wchar_t[sz];
		mbstowcs_s(nullptr, title_w, sz, title, sz - 1);
		void* native_handle = create(x, y, width, height, title_w, visible, flags);
		delete[] title_w;
		return native_handle;
	}
	inline auto window_api::create(int x, int y, int width, int height, const wchar_t* title, bool visible, int flags)->void*
	{
		if (!window_api::platform_specific::class_registered)
		{
			window_api::platform_specific::winclass.lpfnWndProc = window_api::platform_specific::win32_winproc;
			window_api::platform_specific::winclass.lpszClassName = NULL_CLASS_NAME;
			window_api::platform_specific::winclass.hInstance = GetModuleHandle(nullptr);
			window_api::platform_specific::winclass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
			window_api::platform_specific::winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
			RegisterClass(&window_api::platform_specific::winclass);
			window_api::platform_specific::class_registered = true;
		}
		void* native_handle = CreateWindow(window_api::platform_specific::winclass.lpszClassName, title,
			WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, x, y, width, height, NULL, NULL,
			window_api::platform_specific::winclass.hInstance, NULL);
		ShowWindow((HWND)native_handle, (int)visible);
		SetForegroundWindow((HWND)native_handle);
		SetFocus((HWND)native_handle);
		//SetWindowLongPtr(reinterpret_cast<HWND>(native_handle), GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
		return native_handle;
	}
	/* create overloads */
	template<typename NativeHandle>
	static inline void destroy_class(NativeHandle handle)
	{
		//UnregisterClass(NULL_CLASS_NAME, GetModuleHandle(nullptr));
	}
}
#endif