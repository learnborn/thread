#ifndef THREADB_H
#define THREADB_H
#include <thread>
#include <string>
#include "EventBus.h"
#include <atomic>
#include <mutex>

class ThreadB
{
public:
    ThreadB(EventBus* eventBus);
    ~ThreadB();
    void start();
    void stop();
    void loop();
    void getSums(long long& charSum,long long& numSum);
private:
    std::thread* mThread;
    EventBus* mEventBus;
    std::atomic_bool exitThread;
    long long mCharSum;
    long long mNumSum;
    std::mutex mtx;
};

#endif // THREADB_H
