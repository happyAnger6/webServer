#ifndef _EVENT_LOOP_HPP
#define _EVENT_LOOP_HPP

#include <map>

using namespace std;

class EventHandler;

class EventEngine {
private:
    map<int, EventHandler*> m_handlers;
protected:
    int add_handler(EventHandler *pHandler);
    int remove_handler(EventHandler *pHandler);
public:
    int start();
    int stop();
    int register(EventHandler *pHandler, int events);
    int unregister(EventHandler *pHandler);
};

class EpollEngine : public EventEngine {

};

#endif