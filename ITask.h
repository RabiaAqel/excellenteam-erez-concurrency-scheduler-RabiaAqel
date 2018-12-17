//
// Created by Rabia on 17/12/2018.
//

#ifndef TASKSSCHEDULER_ITASK_H
#define TASKSSCHEDULER_ITASK_H


typedef struct ITask
{
    virtual ~ITask () = 0;

    virtual void run () = 0;

    virtual unsigned long getNextRunPeriod () = 0; // in milliseconds
} ITASK;


#endif //TASKSSCHEDULER_ITASK_H
