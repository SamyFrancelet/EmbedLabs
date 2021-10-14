
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
    if(timeouts_.empty()) {
        timeouts_.push_back(pNewTimeout);
    } else {
        std::list<XFTimeout*>::iterator it;
        bool insert = false;
        for(it = timeouts_.begin(); it != timeouts_.end(); it++) {
            if(pNewTimeout->getRelTicks() < (*it)->getRelTicks()) {
                (*it)->substractFromRelTicks(pNewTimeout->getRelTicks());
                insert = true;
                break;
            } else {
                pNewTimeout->substractFromRelTicks((*it)->getRelTicks());
            }
        }

        if (insert) {
            timeouts_.insert(it, pNewTimeout);
        } else {
            timeouts_.push_back(pNewTimeout);
        }
    }
}

void XFTimeoutManager::returnTimeout(XFTimeout *pTimeout)
{
    pTimeout->getBehavior()->pushEvent(pTimeout);
}

XFTimeoutManager::~XFTimeoutManager()
{
    for(XFTimeout* timeout : timeouts_) {
        delete timeout;
    }
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
    timeouts_.front()->substractFromRelTicks(tickInterval_);
    if(timeouts_.front()->getRelTicks() <= 0) {
        returnTimeout(timeouts_.front());
        timeouts_.pop_front();
    }
}
