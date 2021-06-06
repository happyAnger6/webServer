#include <cassert>

#include "event_loop.hpp"

int EventEngine::add_handler(EventHandler *pHandler)
{
    int file_no = pHandler->file_no();
    auto ret = m_handlers.insert({file_no, pHandler});
    if(ret.second)
        return 0;

    assert(0);
    return -1;
}

int EventEngine::remove_handler(EventHandler *pHandler)
{
    int file_no = pHandler->file_no();
    auto ret = m_handlers.erase(file_no);
    assert(ret != 0);

    return 0;
}