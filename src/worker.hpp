#ifndef _WORKER_HPP
#define _WORKER_HPP

class Worker {
public:
    virtual int start();
    virtual int stop();
    virtual ~Worker();
};

#endif