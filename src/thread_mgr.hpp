#ifndef _THREAD_MGR_HPP
#define _THREAD_MGR_HPP

#include "worker.hpp"

class ThreadMgr {
private:
    int thread_nums;
    Worker *pWorker;
public:
    explicit ThreadMgr(int thread_nums, Worker *pWorker) : 
            thread_nums(thread_nums),  pWoker(pWorker) {}
    virtual ~ThreadMgr();
    void wait();
    void shutdown();
};

#endif