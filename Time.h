//
// Created by Rabia on 17/12/2018.
//

#ifndef TASKSSCHEDULER_TIME_H
#define TASKSSCHEDULER_TIME_H

#include <time.h>


class Time
{

public:

    Time (unsigned long);

    ~Time ();

    unsigned long now () const;

    unsigned long get () const;

    void set (unsigned long newTime);

    Time &operator+= (unsigned long rhs);

private:

    unsigned long m_time;

};



#endif //TASKSSCHEDULER_TIME_H
