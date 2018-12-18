//
// Created by Rabia on 18/12/2018.
//

#include "Time.h"
#include <iostream>


Time::Time (unsigned long time)
{ m_time = time; }


Time::~Time ()
{}


unsigned long Time::now () const
{ return time(0); }


size_t Time::get () const
{ return m_time; }


void Time::set (unsigned long newTime)
{ m_time = newTime; }


Time &Time::operator+= (unsigned long rhs)
{
    m_time += rhs;
    return *this;
}


bool operator< (const Time &lhs, const Time &rhs)
{ return true; };


int main()
{
    Time t(4);
    std::cout << t.get ();
}
