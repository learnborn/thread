#include "ThreadC.h"
#include <iostream>
#include <chrono>

using namespace std;

ThreadC::ThreadC(ThreadB* b)
{
    mB=b;
    mThread=NULL;
    exitThread.store(false);
}

ThreadC::~ThreadC()
{
    stop();
}

void ThreadC::start(){
    stop();
    exitThread.store(false);
    mThread=new thread(&ThreadC::loop,this);
}

void ThreadC::stop(){
    if(mThread!=NULL){
        exitThread.store(true);
        mThread->join();
        delete mThread;
        mThread=NULL;
    }
}

void ThreadC::loop(){
    while(!exitThread.load()){
        long long sumChar=0;
        long long sumNum=0;
        mB->getSums(sumChar,sumNum);
        cout<<"the total char count:"<<sumChar
            <<" total number count:"<<sumNum<<endl;
        std::this_thread::sleep_for(chrono::seconds(5));
    }
}


