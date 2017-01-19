#include "EventBus.h"
#include <iostream>

char EventBus::LETTERS[LETTER_LEN]={0};
using namespace std;

EventBus::EventBus()
{
    for(int i=0;i<LETTER_LEN;i++){
        if(i<10){
            LETTERS[i]='0'+i;
        }else{
            LETTERS[i]='a'+(i-10);
        }
    }
}

EventBus::~EventBus()
{
}

void EventBus::sendMsg(std::string& msg){
    std::unique_lock<std::mutex> lck(mtx);
    messages.push_back(msg);
    cv.notify_one();
}

std::string EventBus::getMsg(){
    std::unique_lock<std::mutex> lck(mtx);
    while(messages.empty())
        cv.wait(lck);
    string result=messages.front();
    messages.erase(messages.begin());
    return result;
}
