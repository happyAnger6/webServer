#ifndef _TCP_SERVER_HPP
#define _TCP_SERVER_HPP

#include <string>

#include "event_loop.hpp"
#include "worker.hpp"

using namespace std;

class TcpServer : public Worker {
private:
    string addr;
    short port;
    int flags;  // reuse or not.
    int on_accept();
    EventLoopBase *pReactor;
public:
    TcpServer(string addr, short port, flags = 0) : addr(addr), port(port) {}
    int start();
    int stop();
};

#endif