#ifndef BOX_CONTAINER_H
#define BOX_CONTAINER_H

#include <iostream>

template <typename T, size_t maximum> //* size_t maximum is a non-type template
class BoxContainer
{
    static const size_t DEFAULT_CAPACITY = 5;
    static const size_t EXPAND_STEPS = 5;

public:
    BoxContainer(size_t capacity = DEFAULT_CAPACITY);
    BoxContainer(const BoxContainer &source);
    ~BoxContainer();

    // Helper getter methods
    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; };

    T get_item(size_t index) const
    {
        return m_items[index];
    }

    // Method to add items to the box
    void add(const T &item);
    bool remove_item(const T &item);
    size_t remove_all(const T &item);

    // In class operators
    void operator+=(const BoxContainer<T, maximum> &operand);
    void operator=(const BoxContainer<T, maximum> &source);

private:
    void expand(size_t new_capacity);

private:
    T *m_items;
    size_t m_capacity{10};
    size_t m_size;
};

//! Definitions moved into here

template <typename T, size_t maximum> //* size_t maximum is a non-type template
BoxContainer<T, maximum> operator+(const BoxContainer<T, maximum> &left, const BoxContainer<T, maximum> &right);

template <typename T, size_t maximum> //* size_t maximum is a non-type template
inline std::ostream &operator<<(std::ostream &out, const BoxContainer<T, maximum> &operand)
{

    out << "BoxContainer: [ size: " << operand.size()
        << ", capacity: " << operand.capacity()
        << ", maximum: " << maximum
        << ", items: ";

    for (size_t i{0}; i < operand.size(); ++i)
    {
        out << operand.get_item(i) << " ";
    }
    out << "]";

    return out;
}

template <typename T, size_t maximum> //* size_t maximum is a non-type template
BoxContainer<T, maximum>::BoxContainer(size_t capacity)
{
    m_items = new T[capacity];
    m_capacity = capacity;
    m_size = 0;
}

template <typename T, size_t maximum> //* size_t maximum is a non-type template
BoxContainer<T, maximum>::BoxContainer(const BoxContainer<T, maximum> &source)
{

    m_items = new T[source.m_capacity];
    m_capacity = source.m_capacity;
    m_size = source.m_size;

    for (size_t i{}; i < source.size(); ++i)
    {
        m_items[i] = source.m_items[i];
    }
}

template <typename T, size_t maximum> //* size_t maximum is a non-type template
BoxContainer<T, maximum>::~BoxContainer()
{
    delete[] m_items;
}

template <typename T, size_t maximum> //* size_t maximum is a non-type template
void BoxContainer<T, maximum>::expand(size_t new_capacity)
{
    std::cout << "Expanding to " << new_capacity << std::endl;
    T *new_items_container;

    if (new_capacity <= m_capacity)
        return;

    new_items_container = new T[new_capacity];

    for (size_t i{}; i < m_size; ++i)
    {
        new_items_container[i] = m_items[i];
    }

    delete[] m_items;

    m_items = new_items_container;

    m_capacity = new_capacity;
}

template <typename T, size_t maximum> //* size_t maximum is a non-type template
void BoxContainer<T, maximum>::add(const T &item)
{
    //* Added a check for maximum capacity
    if (m_size == maximum)
    {
        std::cout << "Maximum capacity reched. Not adding item." << std::endl;
        return;
    }

    if (m_size == m_capacity)
        expand(m_size + EXPAND_STEPS); //* declared the EXPAND_STEPS in the class declration
    m_items[m_size] = item;
    ++m_size;
}

template <typename T, size_t maximum> //* size_t maximum is a non-type template
bool BoxContainer<T, maximum>::remove_item(const T &item)
{

    size_t index{m_capacity + 999};

    for (size_t i{0}; i < m_size; ++i)
    {
        if (m_items[i] == item)
        {
            index = i;
            break;
        }
    }

    if (index > m_size)
        return false;

    m_items[index] = m_items[m_size - 1];
    m_size--;
    return true;
}

template <typename T, size_t maximum> //* size_t maximum is a non-type template
size_t BoxContainer<T, maximum>::remove_all(const T &item)
{

    size_t remove_count{};

    bool removed = remove_item(item);
    if (removed)
        ++remove_count;

    while (removed == true)
    {
        removed = remove_item(item);
        if (removed)
            ++remove_count;
    }

    return remove_count;
}

template <typename T, size_t maximum> //* size_t maximum is a non-type template
void BoxContainer<T, maximum>::operator+=(const BoxContainer<T, maximum> &operand)
{

    if ((m_size + operand.size()) > m_capacity)
        expand(m_size + operand.size());

    for (size_t i{}; i < operand.m_size; ++i)
    {
        m_items[m_size + i] = operand.m_items[i];
    }

    m_size += operand.m_size;
}

template <typename T, size_t maximum> //* size_t maximum is a non-type template
BoxContainer<T, maximum> operator+(const BoxContainer<T, maximum> &left, const BoxContainer<T, maximum> &right)
{
    BoxContainer<T, maximum> result(left.size() + right.size());
    result += left;
    result += right;
    return result;
}

template <typename T, size_t maximum> //* size_t maximum is a non-type template
void BoxContainer<T, maximum>::operator=(const BoxContainer<T, maximum> &source)
{
    T *new_items;

    if (this == &source)
        return;

    if (m_capacity != source.m_capacity)
    {
        new_items = new T[source.m_capacity];
        delete[] m_items;
        m_items = new_items;
        m_capacity = source.m_capacity;
    }

    for (size_t i{}; i < source.size(); ++i)
    {
        m_items[i] = source.m_items[i];
    }

    m_size = source.m_size;
}

//! Definitions moved in the header

#endif // BOX_CONTAINER_H