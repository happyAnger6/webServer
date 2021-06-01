#ifndef _EVENT_HANDLER_HPP
#define _EVENT_HANDLER_HPP

class Event {
    int evt_type;
};

class EventHandler {
public:
    int Fileno();
    int Handle(Event &evt);
};

class AcceptorHandler : public EventHandler {

};

class ConnectorHandler : public EventHandler {

};

#endif