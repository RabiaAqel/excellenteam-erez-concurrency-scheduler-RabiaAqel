//
// Created by Rabia on 17/12/2018.
//

#include "Scheduler.h"
#include <algorithm>


Scheduler::Scheduler ()
{
    std::make_heap (tasks.begin (), tasks.end ());
//    setStatus (SCHEDULING);
}


Scheduler::~Scheduler ()
{
//    delete tasks;
}


void Scheduler::add (const SharedPtr<ITask> task)
{

    tasks.push_back (std::make_pair (Time (task.get ()->getNextRunPeriod ()), task));
    std::push_heap (tasks.begin (), tasks.end ());
}


void Scheduler::run ()
{
    SharedPtr <ITask> next = nextTask ();

    while (next)
    {
        next->run ();
        next = nextTask ();
    }
}


SharedPtr<ITask> Scheduler::nextTask ()
{

//    if (tasks.empty())
//    {
//        setStatus (DONE);
//    }

    SharedPtr <ITask> temp(tasks.front ().second);

    pop_heap (tasks.begin (), tasks.end ());

    return temp;
}


void Scheduler::dropTask ()
{

}


bool operator< (const TimedTask &lhs, const TimedTask &rhs)
{
    // We Use not since we are using max heap
    // while we want the task which
    // has to run earlier
    return !(lhs.first < rhs.first);
}



