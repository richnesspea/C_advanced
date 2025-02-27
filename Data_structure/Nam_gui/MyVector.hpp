#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <initializer_list>

template <typename T>
class Vector
{
private:
    T *m_ptr;
    size_t m_size;
    size_t m_capacity;

    void reallocate(size_t capacity);

public:
    class Iterator
    {
    private:
        T *m_ptr;

    public:
        Iterator(T *ptr);
        T &operator*();
        Iterator &operator=(const Iterator &other);
        Iterator &operator++();
        Iterator &operator--();
        Iterator &operator+(const size_t &step);
        Iterator &operator-(const size_t &step);
        bool operator!=(const Iterator &other);
        bool operator==(const Iterator &other);
        T *get_ptr() const;
    };

public:
    // Constructor & Destructors
    Vector();                              // Default Constructor
    Vector(size_t size);                   // Fill constructor
    Vector(size_t size, const T &value);   // Fill constructor
    Vector(const Vector &other);           // Copy Constructor
    Vector(Vector &&other) noexcept;       // Move Constructor
    Vector(std::initializer_list<T> list); // Initializer List Constructor 
    ~Vector();                             // Destructor

    // Assignment Operator
    Vector &operator=(const Vector &other);           // Copy Assignment Operator
    Vector &operator=(Vector &&other) noexcept;       // Move Assignment Operator
    Vector &operator=(std::initializer_list<T> list); // Initializer List Assignment Operator

    // Iterators
    Iterator begin() const noexcept;
    Iterator end() const noexcept;

    // Capacity
    size_t size() const noexcept;
    void resize(size_t size);
    void resize(size_t size, const T &value);
    size_t capacity() const noexcept;
    bool empty() const noexcept;
    void reserve(size_t capacity);

    // Element access
    T &operator[](size_t index) const;
    T &at(size_t index) const;
    T &front() const;
    T &back() const;
    T *data() const noexcept;

    // Modifiers
    void push_back(const T &value);
    void push_back(T &&value);
    void pop_back();
    Iterator insert(Iterator pos, const T &value);
    Iterator insert(Iterator pos, T &&value);
    Iterator insert(Iterator pos, std::initializer_list<T> list);
    void clear() noexcept;
    template <typename... Args>
    void emplace(Iterator pos, Args &&...args);
    template <typename... Args>
    void emplace_back(Args &&...args);
};

#include "MyVector.tpp"

#endif /* MY_VECTOR_H */