//
// Created by Rabia on 18/12/2018.
//

#include "ITask.h"
#include <random>
#include <unistd.h>

class DummyTask : public ITask
{

public:

    DummyTask ();

    ~DummyTask ();

    void run ();

    unsigned long getNextRunPeriod ();

private:

    static int rounds;
    static const int SLEEP_TIME = 3;
    static const int OPERATION_PER_RUN = 3;

};


int DummyTask::rounds = 4;


void DummyTask::run ()
{
    int i = 0;
    for (; i < OPERATION_PER_RUN; ++i)
    {
        printf ("Running...");
        sleep (SLEEP_TIME);
    }
}


unsigned long DummyTask::getNextRunPeriod ()
{
    // random for every round, then finished
    if (rounds-- != 0)
        return (rand () % 5);
    else
        return 0;
}