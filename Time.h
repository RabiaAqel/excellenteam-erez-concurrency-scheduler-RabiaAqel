//
// Created by Rabia on 17/12/2018.
//

#ifndef TASKSSCHEDULER_TIME_H
#define TASKSSCHEDULER_TIME_H

#include <time.h>


class Time
{

public:

    Time (unsigned long)
    {};

    ~Time ()
    {};

    Time &operator+= (const Time &rhs)
    {};

    static unsigned long now();

private:

    timespec m_time;

};


bool operator< (const Time &lhs, const Time &rhs)
{ return true; };


#endif //TASKSSCHEDULER_TIME_H
