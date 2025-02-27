#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <utility>
#include "MyVector.hpp"

template <typename T>
void Vector<T>::reallocate(size_t capacity)
{
    T *new_ptr = new T[capacity];
    for (size_t i = 0; i < m_size; i++)
    {
        new_ptr[i] = std::move(m_ptr[i]);
    }
    delete[] m_ptr;
    m_ptr = new_ptr;
    m_capacity = capacity;
}

// ===========================================
// ======== Constructor & Destructors ========
// ===========================================
template <typename T>
Vector<T>::Vector() // Default Constructor
    : m_ptr(nullptr), m_size(0), m_capacity(0)
{
}

template <typename T>
Vector<T>::Vector(size_t size) // Fill constructor
    : m_ptr(new T[size]), m_size(size), m_capacity(size)
{
    for (size_t i = 0; i < m_size; i++)
    {
        m_ptr[i] = 0;
    }
}

template <typename T>
Vector<T>::Vector(size_t size, const T &value) // Fill constructor
    : m_ptr(new T[size]), m_size(size), m_capacity(size)
{
    for (size_t i = 0; i < m_size; i++)
    {
        m_ptr[i] = value;
    }
}

template <typename T>
Vector<T>::Vector(const Vector &other) // Copy Constructor
    : m_ptr(new T[other.m_capacity]), m_size(other.m_size), m_capacity(other.m_capacity)
{
    for (size_t i = 0; i < m_size; i++)
    {
        m_ptr[i] = other.m_ptr[i];
    }
}

template <typename T>
Vector<T>::Vector(Vector &&other) noexcept // Move Constructor
    : m_ptr(other.m_ptr), m_size(other.m_size), m_capacity(other.m_capacity)
{
    other.m_ptr = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> list) // Initializer List Constructor
    : m_ptr(new T[list.size()]), m_size(list.size()), m_capacity(list.size())
{
    size_t i = 0;
    for (const auto &temp : list)
    {
        m_ptr[i++] = temp;
    }
}

template <typename T>
Vector<T>::~Vector() // Destructor
{
    delete[] m_ptr;
    m_size = 0;
    m_capacity = 0;
}

// =====================================
// ======== Assignment Operator ========
// =====================================
template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &other) // Copy Assignment Operator
{
    if (this != &other)
    {
        delete[] m_ptr;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_ptr = new T[m_capacity];
        for (size_t i = 0; i < m_size; i++)
        {
            m_ptr[i] = other.m_ptr[i];
        }
    }
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector &&other) noexcept // Move Assignment Operator
{
    if (this != &other)
    {
        delete[] m_ptr;
        m_ptr = other.m_ptr;
        m_size = other.m_size;
        m_capacity = other.m_capacity;

        other.m_ptr = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(std::initializer_list<T> list) // Initializer List Assignment Operator
{
    while (list.size() > m_capacity)
    {
        if (m_capacity == 0)
            reallocate(1);
        else
            reallocate(m_capacity * 2);
    }
    m_size = list.size();
    size_t i = 0;
    for (const auto &temp : list)
    {
        m_ptr[i++] = temp;
    }
    return *this;
}

// ================================
// ======== Class Iterator ========
// ================================
template <typename T>
Vector<T>::Iterator::Iterator(T *ptr) : m_ptr(ptr)
{
}

template <typename T>
T &Vector<T>::Iterator::operator*()
{
    return *m_ptr;
}

template <typename T>
typename Vector<T>::Iterator &Vector<T>::Iterator::operator=(const Iterator &other)
{
    if (this != &other)
    {
        m_ptr = other.m_ptr;
    }
    return *this;
}

template <typename T>
typename Vector<T>::Iterator &Vector<T>::Iterator::operator++()
{
    ++m_ptr;
    return *this;
}

template <typename T>
typename Vector<T>::Iterator &Vector<T>::Iterator::operator--()
{
    --m_ptr;
    return *this;
}

template <typename T>
typename Vector<T>::Iterator &Vector<T>::Iterator::operator+(const size_t &step)
{
    m_ptr += step;
    return *this;
}

template <typename T>
typename Vector<T>::Iterator &Vector<T>::Iterator::operator-(const size_t &step)
{
    m_ptr -= step;
    return *this;
}

template <typename T>
bool Vector<T>::Iterator::operator!=(const Iterator &other)
{
    return m_ptr != other.m_ptr;
}

template <typename T>
bool Vector<T>::Iterator::operator==(const Iterator &other)
{
    return m_ptr == other.m_ptr;
}

template <typename T>
T *Vector<T>::Iterator::get_ptr() const
{
    return m_ptr;
}

// ===================================
// ============ Iterator =============
// ===================================
template <typename T>
typename Vector<T>::Iterator Vector<T>::begin() const noexcept
{
    return Iterator(m_ptr);
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end() const noexcept
{
    return Iterator(m_ptr + m_size);
}

// ====================================
// ============= Capacity =============
// ====================================
template <typename T>
size_t Vector<T>::size() const noexcept
{
    return m_size;
}

template <typename T>
size_t Vector<T>::capacity() const noexcept
{
    return m_capacity;
}

template <typename T>
bool Vector<T>::empty() const noexcept
{
    return m_size == 0;
}

template <typename T>
void Vector<T>::resize(size_t size)
{
    if (size < m_size)
    {
        m_size = size;
    }
    else
    {
        while (size > m_capacity)
        {
            if (m_capacity == 0)
                reallocate(1);
            else
                reallocate(m_capacity * 2);
        }
        for (size_t i = m_size; i < size; i++)
        {
            m_ptr[i] = T();
        }
        m_size = size;
    }
}

template <typename T>
void Vector<T>::resize(size_t size, const T &value)
{
    if (size < m_size)
    {
        m_size = size;
    }
    else
    {
        while (size > m_capacity)
        {
            if (m_capacity == 0)
                reallocate(1);
            else
                reallocate(m_capacity * 2);
        }
        for (size_t i = m_size; i < size; i++)
        {
            m_ptr[i] = value;
        }
        m_size = size;
    }
}

template <typename T>
void Vector<T>::reserve(size_t capacity)
{
    if (capacity > m_capacity)
    {
        reallocate(capacity);
    }
}

// ====================================
// ========== Element access ==========
// ====================================
template <typename T>
T &Vector<T>::operator[](size_t index) const
{
    return m_ptr[index];
}

template <typename T>
T &Vector<T>::at(size_t index) const
{
    if (index >= m_size)
    {
        throw std::out_of_range("Index out of range\n");
    }
    return m_ptr[index];
}

template <typename T>
T &Vector<T>::front() const
{
    if (m_size == 0)
    {
        throw std::out_of_range("Vector is empty\n");
    }
    return m_ptr[0];
}

template <typename T>
T &Vector<T>::back() const
{
    if (m_size == 0)
    {
        throw std::out_of_range("Vector is empty\n");
    }
    return m_ptr[m_size - 1];
}

template <typename T>
T *Vector<T>::data() const noexcept
{
    return m_ptr;
}

// ====================================
// ============ Modifiers =============
// ====================================
template <typename T>
void Vector<T>::push_back(const T &value)
{
    emplace_back(value);
}

template <typename T>
void Vector<T>::push_back(T &&value)
{
    emplace_back(std::move(value));
}

template <typename T>
void Vector<T>::pop_back()
{
    if (m_size > 0)
    {
        m_size--;
    }
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::insert(Iterator pos, const T &value)
{
    size_t index = pos.get_ptr() - m_ptr;
    if (m_size >= m_capacity)
    {
        if (m_capacity == 0)
            reallocate(1);
        else
            reallocate(m_capacity * 2);
    }

    for (size_t i = m_size; i > index; i--)
    {
        m_ptr[i] = m_ptr[i - 1];
    }
    m_size++;
    m_ptr[index] = value;

    return Iterator(m_ptr + index);
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::insert(Iterator pos, T &&value)
{
    size_t index = pos.get_ptr() - m_ptr;
    if (m_size >= m_capacity)
    {
        if (m_capacity == 0)
            reallocate(1);
        else
            reallocate(m_capacity * 2);
    }

    for (size_t i = m_size; i > index; i--)
    {
        m_ptr[i] = m_ptr[i - 1];
    }
    m_size++;
    m_ptr[index] = std::move(value);

    return Iterator(m_ptr + index);
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::insert(Iterator pos, std::initializer_list<T> list)
{
    size_t index = pos.get_ptr() - m_ptr;
    size_t count = list.size();
    while (m_size + count >= m_capacity)
    {
        if (m_capacity == 0)
            reallocate(1);
        else
            reallocate(m_capacity * 2);
    }

    for (size_t i = m_size + count - 1; i >= index + count - 1; i--)
    {
        m_ptr[i] = std::move(m_ptr[i - count]);
    }

    size_t i = index;
    for (const T &elem : list)
    {
        m_ptr[i++] = elem;
    }
    m_size += count;

    return Iterator(m_ptr + index);
}

template <typename T>
void Vector<T>::clear() noexcept
{
    m_size = 0;
}

template <typename T>
template <typename... Args>
void Vector<T>::emplace(Iterator pos, Args &&...args)
{
    size_t index = pos.get_ptr() - m_ptr;
    if (m_size >= m_capacity)
    {
        if (m_capacity == 0)
            reallocate(1);
        else
            reallocate(m_capacity * 2);
    }
    for (size_t i = m_size; i > index; i--)
    {
        m_ptr[i] = std::move(m_ptr[i - 1]);
    }

    new (m_ptr + index) T(std::forward<Args>(args)...);
    m_size++;
}

template <typename T>
template <typename... Args>
void Vector<T>::emplace_back(Args &&...args)
{
    if (m_size >= m_capacity)
    {
        if (m_capacity == 0)
            reallocate(1);
        else
            reallocate(m_capacity * 2);
    }

    new (m_ptr + m_size) T(std::forward<Args>(args)...);
    m_size++;
}