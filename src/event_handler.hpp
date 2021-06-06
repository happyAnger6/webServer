#ifndef _EVENT_HANDLER_HPP
#define _EVENT_HANDLER_HPP

#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

class EventHandler {
protected:
        int m_fd;
public:
    EventHandler(int fd): 
                     m_fd(fd) {}
    virtual int file_no() const final
    {
        return m_fd;
    }
    virtual int handle(int events) const ;
    virtual ~EventHandler() = default;
};

class EndPoint {
private:
    struct sockaddr_in addr;
public:
    EndPoint(struct sockaddr_in addr) : addr(addr) {}
    int port() {
        return ntohs(addr.sin_addr.sin_port);
    }

    int addr() {
        return ntohl(addr.sin_addr.s_addr);
    }

    int saddr(char *addr_s, int len) {
        return inet_ntop(AF_INET, &addr.sin_addr, addr_s, len);
    }

};

class ConnectorHandler : public EventHandler {
private:
    EndPoint ep;

public:
    ConnectorHandler(int fd, EndPoint ep) : EventHandler(fd), ep(ep) {}
    int handle(int events) const
    {
        return -1;
    }
};

class AcceptorHandler : public EventHandler {
public:
    AcceptorHandler(int fd) : EventHandler(fd) {}
    int handle(int events) const
    {
        int ret;
        if(events | EPOLLIN) 
            ret = handle_read();
    }

private:
    int handle_read()
    {
        struct sockaddr_in cli_addr{};
        int ret = accept(m_fd, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
        if(ret < 0)
            assert(ret == 0);
            return ret;
        }
        
        ConnectorHandler conn_handler = ConnectorHandler(ret, EndPoint(cli_addr));

    }
};


#endif