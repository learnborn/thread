#ifndef THREADA_H
#define THREADA_H
#include <thread>
#include <string>
#include "EventBus.h"
#include <atomic>

class ThreadA
{
public:
    ThreadA(EventBus* eventBus);
    ~ThreadA();
    void start();
    void stop();
    void loop();
private:
    std::string generateString();
    std::thread* mThread;
    EventBus* mEventBus;
    std::atomic_bool exitThread;
};

#endif // THREADA_H
