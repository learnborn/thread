#include "ThreadA.h"
#include <random>
#include <sstream>
#include <functional>
#include <iostream>


using namespace std;

#define RANDDOM_LEN 256;

ThreadA::ThreadA(EventBus* eventBus)
{
    mThread=NULL;
    mEventBus=eventBus;
    exitThread.store(false);
}

ThreadA::~ThreadA()
{
    stop();
}

void ThreadA::start(){
    stop();
    exitThread.store(false);
    mThread=new thread(&ThreadA::loop,this);
}

void ThreadA::stop(){
    if(mThread!=NULL){
        exitThread.store(true);
        mThread->join();
        delete mThread;
        mThread=NULL;
    }
}

void ThreadA::loop(){
    while(!exitThread.load()){
        string randstr=generateString();
        mEventBus->sendMsg(randstr);
    }
}

std::string ThreadA::generateString(){
    static std::default_random_engine random;
    int len=random()%RANDDOM_LEN;
    ostringstream os;
    for(int i=0;i<len;i++){
        char c=EventBus::LETTERS[random()%LETTER_LEN];
        os<<c;
    }
    return os.str();
}
