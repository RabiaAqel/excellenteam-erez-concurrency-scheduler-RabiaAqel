//
// Created by Rabia on 17/12/2018.
//

#include "Scheduler.h"
#include <algorithm>


Scheduler::Scheduler ()
{
    std::make_heap (tasks.begin (), tasks.end ());
}


Scheduler::~Scheduler ()
{
//    delete tasks;
}


void Scheduler::add (const SharedPtr<ITask> task)
{
    Time startTime (task.get ()->getNextRunPeriod ());

    TimedTask timedTask = std::make_pair (startTime, task);

    tasks.push_back (timedTask);
    std::push_heap (tasks.begin (), tasks.end ());
}


void Scheduler::run ()
{

}


SharedPtr<ITask> Scheduler::nextTask ()
{

}


void Scheduler::dropTask ()
{

}


bool operator< (const TimedTask &lhs, const TimedTask &rhs)
{
    return true;
}



