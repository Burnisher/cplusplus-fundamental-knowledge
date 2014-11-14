#ifndef AUTOPTR_HPP_
#define AUTOPTR_HPP_

#include <stddef.h>

template <typename T>
class AutoPtr
{
public:
    typedef T element_type;
    typedef T *pointer;
    typedef T &reference;

    AutoPtr(T *ptr = NULL);
    AutoPtr(AutoPtr<T> &other);
    ~AutoPtr() { delete ptr_; }

    AutoPtr &operator=(AutoPtr &other) throw();

    reference operator*() const throw()
    {
        return *ptr_;
    }

    pointer operator->() const throw()
    {
        return ptr_;
    }

    void reset(T *ptr = NULL) throw()
    {
        if(ptr_ != ptr)
        {
            delete ptr_;
            ptr_ = ptr;
        }
    }

    pointer release() throw()
    {
        pointer temp(ptr_);
        ptr_ = NULL;
        return temp;
    }

    operator bool()
    {
        return ptr_ != NULL;
    }

private:
    element_type *ptr_;
};

template <typename T>
AutoPtr<T>::AutoPtr(T *ptr)
    :ptr_(ptr)
{
    
}

template <typename T>
AutoPtr<T>::AutoPtr(AutoPtr<T> &other)
    :ptr_(other.release())
{
    
}

template<typename T>
AutoPtr<T> &AutoPtr<T>::operator=(AutoPtr<T> &other) throw()
{
    if(ptr_ != other.ptr_)
    {
        reset(other.release());
        return *this;
    }
}


#endif //AUTOPTR_HPP_
