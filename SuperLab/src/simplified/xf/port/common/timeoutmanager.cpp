
#include <config/xf-config.h>

#if (USE_XF_COMMON_TIMEOUTMANAGER_CLASS != 0)

#include <cassert>
#include "xf/interface/behavior.h"
#include "xf/interface/mutex.h"
#include "timeoutmanager.h"

using Mutex = interface::XFMutex;       // Rename XFMutex interface class to Mutex for easier use.

interface::XFTimeoutManager * interface::XFTimeoutManager::getInstance()
{
    static ::XFTimeoutManager timeoutManager;
    return &timeoutManager;
}

// TODO: Implement code for XFTimeoutManager class  

#endif // USE_XF_COMMON_TIMEOUTMANAGER_CLASS

XFTimeoutManager::XFTimeoutManager()
{

}

void XFTimeoutManager::addTimeout(XFTimeout *pNewTimeout)
{
    /*if(timeouts_.empty()) { // First timeout
        pNewTimeout->setRelTicks(pNewTimeout->)
        timeouts_.push_back(pNewTimeout);
    } else {

    }*/
    timeouts_.push_back(pNewTimeout);
}

void XFTimeoutManager::returnTimeout(XFTimeout *pTimeout)
{
    pTimeout->getBehavior()->pushEvent(pTimeout);
}

XFTimeoutManager::~XFTimeoutManager()
{

}

void XFTimeoutManager::start(std::function<void (uint32_t)> startTimeoutManagerTimer)
{
    startTimeoutManagerTimer(tickInterval_);
}

void XFTimeoutManager::scheduleTimeout(int32_t timeoutId, int32_t interval, interface::XFBehavior *pBehavior)
{
    addTimeout(new XFTimeout(timeoutId, interval, pBehavior));
}

void XFTimeoutManager::unscheduleTimeout(int32_t timeoutId, interface::XFBehavior *pBehavior)
{
    for(XFTimeout* timeout : timeouts_) {
        if (timeout->getId() == timeoutId && timeout->getBehavior() == pBehavior) {
            timeouts_.remove(timeout);
        }
    }
}

void XFTimeoutManager::tick()
{
    for(XFTimeout* timeout : timeouts_) {
        timeout->substractFromRelTicks(tickInterval_);
        if (timeout->getRelTicks() <= 0) {
            returnTimeout(timeout);
            timeouts_.remove(timeout);
        }
    }
}
