//
// Created by Rabia on 17/12/2018.
//

#ifndef TASKSSCHEDULER_SCHEDULER_H
#define TASKSSCHEDULER_SCHEDULER_H

#include "SharedPtr.h"
#include "Time.h"
#include "ITask.h"
#include <vector>


typedef std::pair <Time, SharedPtr<ITask> > TimedTask;

class Scheduler
{
public:

    Scheduler ();

    ~Scheduler ();

    void add (const SharedPtr<ITASK> task);

    void run ();


private:

    std::vector <TimedTask> tasks;

    // prevent copying
    Scheduler (Scheduler &other);

    Scheduler &operator= (Scheduler &rhs);

    // gets next task to run
    SharedPtr<ITask> nextTask ();

    // drops task when its finished
    void dropTask ();
};


bool operator< (const TimedTask &lhs, const TimedTask &rhs);

#endif //TASKSSCHEDULER_SCHEDULER_H
