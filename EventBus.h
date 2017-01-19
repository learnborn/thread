#ifndef EVENTBUS_H
#define EVENTBUS_H

#include <vector>
#include <string>
#include <condition_variable>
#include <mutex>

#define LETTER_LEN 36

class EventBus
{
public:
    EventBus();
    ~EventBus();
    void sendMsg(std::string& msg);
    std::string getMsg();
    static char LETTERS[LETTER_LEN];
private:
    std::mutex mtx;
    std::condition_variable cv;
    std::vector<std::string> messages;
};

#endif // EVENTBUS_H
