#include "ThreadB.h"

using namespace std;

ThreadB::ThreadB(EventBus* eventBus)
{
    mThread=NULL;
    mCharSum=0;
    mNumSum=0;
    mEventBus=eventBus;
    exitThread.store(false);
}

ThreadB::~ThreadB()
{
     stop();
}

void ThreadB::start(){
    stop();
    exitThread.store(false);
    mThread=new thread(&ThreadB::loop,this);
}

void ThreadB::stop(){
    if(mThread!=NULL){
        exitThread.store(true);
        mThread->join();
        delete mThread;
        mThread=NULL;
    }
}

void ThreadB::loop(){
    while(!exitThread.load()){
        string randstr=mEventBus->getMsg();
        int char_n=0;
        int num_n=0;
        for(int i=0;i<randstr.size();i++){
            if(randstr[i]>='0'&&randstr[i]<='9'){
                num_n++;
            }else{
                char_n++;
            }
        }
        std::unique_lock<std::mutex> lck(mtx);
        mCharSum+=char_n;
        mNumSum+=num_n;
    }
}

void ThreadB::getSums(long long& charSum,long long& numSum){
    std::unique_lock<std::mutex> lck(mtx);
    charSum=mCharSum;
    numSum=mNumSum;
}
