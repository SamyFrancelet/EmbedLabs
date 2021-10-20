#include <cassert>
#include <config/xf-config.h>

#if (USE_XF_COMMON_DISPATCHER_CLASS != 0)
#if (XF_TRACE_EVENT_PUSH_POP != 0)
    #include "trace/trace.h"
#endif // XF_TRACE_EVENT_PUSH_POP
#include "xf/eventstatus.h"
#include "xf/interface/timeoutmanager.h"
#include "xf/interface/behavior.h"
#include "xf/interface/mutex.h"
#include "dispatcher.h"

using interface::XFTimeoutManager;      // Allows to use expression 'XFTimeoutManager' instead of 'interface::XFTimeoutManager'.
using interface::XFBehavior;            // Expression XFBehavior used in code below is in fact the XFBehavior interface class.
using Mutex = interface::XFMutex;       // Rename XFMutex interface class to Mutex for easier use.

interface::XFDispatcher * interface::XFDispatcher::getInstance()
{
    static ::XFDispatcher dispatcher;
    return &dispatcher;
}

// TODO: Implement code for XFDispatcher class  

#endif // USE_XF_COMMON_DISPATCHER_CLASS

XFDispatcher::XFDispatcher()
{

}

XFDispatcher::~XFDispatcher()
{

}

void XFDispatcher::pushEvent(XFEvent *pEvent, bool fromISR)
{
    _events.push(pEvent, fromISR);
}

void XFDispatcher::scheduleTimeout(int timeoutId, int interval, interface::XFBehavior *pBehavior)
{
    interface::XFTimeoutManager::getInstance()->scheduleTimeout(timeoutId, interval, pBehavior);
}

void XFDispatcher::unscheduleTimeout(int timeoutId, interface::XFBehavior *pBehavior)
{
    interface::XFTimeoutManager::getInstance()->unscheduleTimeout(timeoutId, pBehavior);
}

void XFDispatcher::executeOnce()
{
    // Pops an event, and dispatches it to every stateMachine
	bool isEmpty = _events.empty();
    if (!isEmpty) {
        dispatchEvent(_events.front());
        _events.pop();      // Deletes it from Queue
    }
}

int XFDispatcher::execute(const void *param)
{
    while(true) {
        executeOnce();
    }
}

void XFDispatcher::dispatchEvent(const XFEvent *pEvent) const
{
    bool killBehavior = pEvent->getBehavior()->process(pEvent);
    if (killBehavior) {
        delete pEvent->getBehavior();
        delete pEvent;
    }
}
