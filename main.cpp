#include <iostream>
#include <deque>
#include <algorithm>

template < class T, class Container = std::deque<T>>
class priority_queue
{
public:
    using container_type = Container;
    using value_type = typename container_type::value_type;
    using size_type = typename Container::size_type;
    using reference	= typename Container::reference;
    using const_reference = typename Container::const_reference;
private:
    container_type storage;
public:

    priority_queue() = default;
    priority_queue(std::initializer_list<value_type> _list)
    {
        for(typename std::initializer_list<value_type>::iterator i = _list.begin(); i != _list.end(); ++i)
            storage.push_back(*i);
    }
    reference top()
    {
        return storage.front();
    }
    bool empty() const
    {
        return storage.empty();
    }
    size_type size() const
    {
        return storage.size();
    }
    void push(const value_type& value)
    {
        storage.push_front(value);
        std::sort(storage.begin(), storage.end());
    }
    void pop()
    {
        storage.pop_front();
    }
    void swap(priority_queue<value_type>& other) noexcept
    {
        priority_queue<value_type> temp;
        temp = other;
        other = *this;
        *this = temp;
    }
};
int main()
{
    priority_queue<int> arr;
    for(int i = 0; i < 15; ++i)
    {
        arr.push(rand()%50);
    }
    for(int i = 0; i < 15; ++i)
    {
        std::cout << arr.top() << " ";
        arr.pop();
    }
    return 0;
}
