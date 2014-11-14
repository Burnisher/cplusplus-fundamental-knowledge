#ifndef COUNTER_HPP_
#define COUNTER_HPP_

template <typename T>
class CounterPtr
{
public:
    typedef T value_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;

    CounterPtr(T *p = NULL);
    CounterPtr(const CounterPtr<T> &other);
    ~CounterPtr();

    CounterPtr<T> &operator=(const CounterPtr<T> &other);

    reference operator*() const throw()
    {
        return *ptr_;
    }

    pointer operator->() const throw()
    {
        return ptr_;
    }

    size_t count() const 
    {
        return *count_;
    }

    void swap(CounterPtr<T> &other) throw()
    {
        std::swap(ptr_, other.ptr_);
        std::swap(count_, other.count_);
    }

    void reset(T *ptr = NULL) throw()
    {
        dispose();
        ptr_ = ptr;
        count_ = new size_t(1);
    }

    pointer get() const throw()
    {
        return ptr_;
    }
    
    bool unique() const throw()
    {
        return *count_ == 1;
    }

    operator bool()
    {
        return ptr_ != NULL;
    }

private:
    void dispose()
    {
        if(--*count_ == 0)
        {
            delete ptr_;
            delete count_;
        }
    }

    T *ptr_;
    size_t *count_;

};

template <typename T>
CounterPtr<T>::CounterPtr(T *p)
    :ptr_(p), count_(new size_t(1))
{

}

template <typename T>
CounterPtr<T>::CounterPtr(const CounterPtr<T> &other)
    :ptr_(other.ptr_), count_(other.count_)
{
    ++*count_;
}

template <typename T>
CounterPtr<T>::~CounterPtr()
{
    dispose();
}


template <typename T>
CounterPtr<T> &CounterPtr<T>::operator=(const CounterPtr<T> &other)
{
    ++(*other.count_);
    if(ptr_ != other.ptr_)
    {
        ptr_ = other.ptr_;
        count_ = other.count_;
    }
    dispose();
    return *this;
}


#endif //COUNTER_HPP_
