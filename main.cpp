#include <iostream>
#include "EventBus.h"
#include "ThreadA.h"
#include "ThreadB.h"
#include "ThreadC.h"

int main(int argc, char **argv)
{
    EventBus eventBus;
    ThreadA threadA(&eventBus);
    ThreadB threadB(&eventBus);
    ThreadC threadC(&threadB);
    threadA.start();
    threadB.start();
    threadC.start();
    char in;
    std::cin>>in;
    threadC.stop();
    threadB.stop();
    threadA.stop();
    return 0;
}
