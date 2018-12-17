//
// Created by Rabia on 17/12/2018.
//

#ifndef TASKSSCHEDULER_SCHEDULER_H
#define TASKSSCHEDULER_SCHEDULER_H

#include "SharedPtr.h"
#include "Time.h"
#include "ITask.h"
#include <utility>
#include <vector>


typedef std::pair<Time, SharedPtr<ITASK> > TimedTask;

class Scheduler
{
public:

    Scheduler ();

    ~Scheduler ();

    void add ();

    void run ();


private:

    std::vector<TimedTask> tasks;

    // prevent copying
    Scheduler (Scheduler &other);

    Scheduler &operator= (Scheduler &rhs);

    // gets next task to run
    ITASK scheduleTask ();

    // drops task when its finished
    void dropTask ();
};


#endif //TASKSSCHEDULER_SCHEDULER_H
