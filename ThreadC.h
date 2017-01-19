#ifndef THREADC_H
#define THREADC_H
#include "ThreadB.h"
#include <thread>
#include <string>

class ThreadC
{
public:
    ThreadC(ThreadB* b);
    ~ThreadC();
    void start();
    void stop();
    void loop();
private:
    std::thread* mThread;
    ThreadB* mB;
    std::atomic_bool exitThread;
};

#endif // THREADC_H
