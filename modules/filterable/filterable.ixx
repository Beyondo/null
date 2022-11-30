export module null.filterable;
import <stdexcept>;
import <algorithm>;
import <ranges>;
import <vector>;
export namespace null
{
    template<typename T>
    class filterable
    {
    public:
        constexpr filterable()
        {
			
        }
        constexpr filterable(uint32_t count)
        {
            list = std::vector<T>(count);
        }
        constexpr void resize(size_t new_size)
        {
            this->list.resize(new_size);
        }
        constexpr void push_back(const T& item)
        {
            this->list.push_back(item);
        }
        constexpr auto first() -> T&
        {
            if (this->list.empty()) throw std::out_of_range("The list is empty");
            return this->list[0];
        }
        constexpr bool empty()
        {
            return this->list.empty();
        }
        template<typename Index>
        constexpr auto operator[](Index i)->T&
        {
            return this->list[i];
        }
        constexpr auto begin()
        {
            return this->list.begin();
        }
        constexpr auto end()
        {
            return this->list.end();
        }
        constexpr auto begin()const
        {
            return this->list.begin();
        }
        constexpr auto end() const
        {
            return this->list.end();
        }
        constexpr auto data() -> T*
        {
            return this->list.data();
        }
        constexpr auto size() const->size_t
        {
            return this->list.size();
        }
        template<class Param1>
        auto filter(bool (T::* member_function)(const Param1&) const, const Param1& param1, uint64_t count = INT64_MAX)const->filterable
        {
            filterable<T> filtered;
            uint64_t i = 0;
            for (auto& item : this->list)
            {
                if ((item.*member_function)(param1))
                {
                    filtered.list.push_back(item);
                    ++i;
                }
                if (i >= count)
                    break;
            }
            return filtered;
        }
        template<class Param1>
        auto filter(bool (T::* member_function)(const Param1*) const, Param1* param1, uint64_t count = INT64_MAX)const->filterable
        {
            filterable<T> filtered;
            uint64_t i = 0;
            for (auto& item : this->list)
            {
                if ((item.*member_function)(param1))
                {
                    filtered.list.push_back(item);
                    ++i;
                }
                if (i >= count)
                    break;
            }
            return filtered;
        }
        template<typename Bit>
        auto filter(Bit bit, uint64_t count = INT64_MAX)const->filterable
        {
            filterable<T> filtered;
            uint64_t i = 0;
            for (auto& item : this->list)
            {
                if (item & bit)
                {
                    filtered.list.push_back(item);
                    ++i;
                }
                if (i >= count)
                    break;
            }
            return filtered;
        }
        auto contains(const T& x)const->bool
        {
            for (auto& item : this->list)
                if (item == x)
                    return true;
            return false;
        }
        constexpr void operator<<=(const filterable& source)
        {
            for (auto& item : source)
            {
                // Scans for item if exists
                int i = 0;
                for (i = 0; i < this->size(); ++i)
                    if (item == this->list[i])
                        break;
                // If doesn't exist, push
                if (i == this->size())
                    this->push_back(item);
            }
            //std::ranges::unique_copy(source.list, this->list);
        }
        /* Concatenates only the unique elements from the filterable source to this list
        */
        constexpr auto operator<<(const filterable& source)const->filterable
        {
            filterable<T> result(this->list);
            result <<= source;
            return result;
        }
        template<typename Bit>
        constexpr auto operator&(Bit bit)const->filterable
        {
            return this->filter(bit);
        }
        auto operator+(const filterable& filterable_list)const->filterable
        {
            filterable<T> result(this->list);
            std::ranges::copy(filterable_list.list, std::back_inserter(result.list));
            return result;
        }

    private:
        filterable(const std::vector<T>& vec) : list(vec)
        {

        }
        std::vector<T> list;
    };
}