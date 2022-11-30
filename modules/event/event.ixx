export module null.event;
import <vector>;
import <algorithm>;
export namespace null
{
    class event
    {
    public:
        bool handled = false;
    };
    class cancellable_event
    {
    public:
        bool cancelled = false;
    };
    template<typename Event>
    using event_callback = void(*)(Event&);
    template<typename Event>
    class event_handler
    {
    public:
        /**
        * \return a boolean indicating whether the event was cancelled or not
        */
        constexpr inline bool dispatch(Event& args) const
        {
            for (auto& callback : callbacks)
            {
                callback(args);
                if constexpr (requires { &args.cancelled; })
                    if (args.cancelled) return true;
                    else if constexpr (requires { &args.handled; })
                        if (args.handled) return true;
            }
            return false;
        }
        constexpr inline void operator+=(const event_callback<Event>& callback)
        {
            callbacks.push_back(callback);
        }
        constexpr inline void operator-=(const event_callback<Event>& callback)
        {
            std::ranges::remove(callbacks, callback);
        }
        constexpr inline auto count()const->size_t
        {
            return this->callbacks.size();
        }
    private:
        std::vector<event_callback<Event>> callbacks;
    };
}