#ifndef _EVENT_LOOP_HPP
#define _EVENT_LOOP_HPP

class EventLoopBase {
public:
    int add_event_handler(EventHandler &handler);
    int remove_event_handler(EventHandler &handler);
    int loop();
    int start();
    int stop();
};

class EpollLoop : public EventLoopBase {

};

#endif