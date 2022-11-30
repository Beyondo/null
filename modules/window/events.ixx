export module null.window:events;
import null.event;
export namespace null
{
    class window;
    class window_closing_event : public null::cancellable_event
    {
    public:
        constexpr auto window()const->window*
        {
            return this->m_window;
        }
    private:
        null::window* m_window;
        friend null::window;
    };
    class window_resizing_event : public null::event
    {
    public:
        inline constexpr auto window()const->window*
        {
            return this->m_window;
        }
        inline constexpr auto width()const->int
        {
            return this->m_width;
        }
        inline constexpr auto height()const->int
        {
            return this->m_height;
        }
    private:
        int m_width, m_height;
        null::window* m_window;
        friend null::window;
    };
    class window_resized_event : public null::event
    {
    public:
        constexpr auto window()const->window*
        {
            return this->m_window;
        }
    private:
        null::window* m_window;
        friend null::window;
    };
    class window_frame_resized_event : public null::event
    {
    public:
        inline constexpr auto window()const->window*
        {
            return this->m_window;
        }
    private:
        null::window* m_window;
        friend null::window;
    };
}