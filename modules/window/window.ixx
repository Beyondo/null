export module null.window;
import :api;
//import :events;
import null.meta;
import null.event;
export namespace null
{
	class window
	{
	public:
		void gl_swap_buffers()
		{
			window_api::gl_swap_buffers(this->m_handle);
		}
		void update()
		{
			window_api::update(this->m_handle);
		}
		/** Checks if any events are triggered, process them, then asynchronously calls the respective callbacks
		* \note This function is non-blocking
		*/
		void poll_events()
		{
			window_api::poll_events(this->m_handle);
		}
		/** Waits for events to be triggered then polls them
		* \note This function is blocking
		*/
		void wait_events()
		{
			window_api::wait_events(this->m_handle);
		}
		/** Shows the window
		*/
		void show()
		{
			window_api::show(this->m_handle);
		}
		/** Hides the window
		*/
		void hide()
		{
			window_api::hide(this->m_handle);
		}
		/** Modifies the visibility of the window
		* \param visibility whether the window should be visible or not
		*/
		void set_visibility(bool visibility)
		{
			window_api::set_visibility(this->m_handle, visibility);
		}
		window()
		{
			this->m_handle = window_api::create();
		}
		~window()
		{
			window_api::destroy(this->m_handle);
		}
		///** Triggered before the window is about to close */
		//event_handler<window_closing_event> on_closing;
		///** Triggered while the window is being resized */
		//event_handler<window_resizing_event> on_resizing;
		///** Triggered after the window has been resized */
		//event_handler<window_resized_event> on_resized;
		///** Triggered while the window is being resized */
		//event_handler<window_frame_resized_event> on_frame_resized;
	private:
		void* m_handle;
	};
}