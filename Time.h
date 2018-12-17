//
// Created by Rabia on 17/12/2018.
//

#ifndef TASKSSCHEDULER_TIME_H
#define TASKSSCHEDULER_TIME_H


class Time
{
public:
    Time (unsigned long)
    {};

    ~Time ()
    {};

    bool operator> (const Time &rhs)
    { return true; };

    Time &operator+= (const Time &rhs)
    {  };

    static unsigned long now();

private:


};


#endif //TASKSSCHEDULER_TIME_H
