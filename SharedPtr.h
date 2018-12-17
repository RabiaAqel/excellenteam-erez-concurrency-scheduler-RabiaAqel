//
// Created by Rabia on 10/12/2018.
//

#ifndef SHAREDPOINTER_SHAREDPTR_H
#define SHAREDPOINTER_SHAREDPTR_H


#include <iostream>

template<typename T>
class SharedPtr
{
public:

    explicit SharedPtr ();

    explicit SharedPtr (T *ptr);

    ~SharedPtr ();

    SharedPtr (const SharedPtr &other);

    T &operator* ();

    T *operator-> ();

    SharedPtr<T> &operator= (const SharedPtr<T> &rhs);

    operator bool () const;

    T *get () const;

    void print ();

    // For polymorphism
    template<typename U>
    SharedPtr<U> (const SharedPtr<U> &other);

    template<typename U>
    SharedPtr<U> &operator=
            (const SharedPtr<U> &rhs);

private:

    class ReferenceCount
    {
    private:

        size_t m_count;

    public:

        ReferenceCount ()
                : m_count (0)
        {};

        ReferenceCount (const ReferenceCount &other)
                : m_count (other.m_count)
        {}

        ~ReferenceCount ()
        {}

        void add ()
        { m_count++; }

        size_t release ()
        { return --m_count; }

        size_t getCount ()
        { return m_count; }
    };

    T *m_ptr;
    ReferenceCount *m_references;

};


template<typename T>
SharedPtr<T>::
SharedPtr ()
        :m_references (new ReferenceCount ()),
         m_ptr (NULL)
{
    m_references->add ();
}


template<typename T>
SharedPtr<T>::
SharedPtr (T *ptr)
        :m_references (new ReferenceCount ()),
         m_ptr (ptr)
{
    m_references->add ();
}


template<typename T>
SharedPtr<T>::
SharedPtr (const SharedPtr &other)
        :m_references (other.m_references),
         m_ptr (other.get ())
{
    m_references->add ();
}


template<typename T>
SharedPtr<T>::
~SharedPtr ()
{
    if (m_references->release () == 0)
    {
        delete m_references;
        delete m_ptr;
    }
}


template<typename T>
T &SharedPtr<T>::
operator* ()
{
    return *m_ptr;
}


template<typename T>
T *SharedPtr<T>::
operator-> ()
{
    return m_ptr;
}


template<typename T>
SharedPtr<T> &SharedPtr<T>::
operator= (const SharedPtr<T> &rhs)
{
    if (this != &rhs)
    {

        // release the current pointer
        if (m_references->release () == 0)
        {
            delete m_ptr;
            delete m_references;
        }

        // assign the rhs new ptr
        // and add referece
        // (now I'm also pointing)
        m_ptr = rhs.get ();
        m_references = rhs.m_references;
        m_references->add ();

    }

    return *this;
}


template<typename T>
SharedPtr<T>::
operator bool () const
{
    return m_ptr;
}


template<typename T>
T *
SharedPtr<T>::
get () const
{
    return m_ptr;
}


template<typename T>
void SharedPtr<T>::
print ()
{
    std::cout << "My ref count: " << m_references->getCount ();
}


template<typename T>
template<typename U>
SharedPtr<T>::
SharedPtr (const SharedPtr<U> &other)
        :m_references (new ReferenceCount ()),
         m_ptr (other.get ())
{
    m_references->add ();
}


template<typename T>
template<typename U>
SharedPtr<U> &SharedPtr<T>::
operator= (const SharedPtr<U> &rhs)
{
    if (this != &rhs)
    {

        // release the current pointer
        if (m_references->release () == 0)
        {
            delete m_ptr;
            delete m_references;
        }

        // assign the rhs new ptr
        // and add referece
        // (now I'm also pointing)
        m_ptr = rhs.get ();
        m_references = rhs.m_references;
        m_references->add ();

    }

    return *this;
}

#endif //SHAREDPOINTER_SHAREDPTR_H
