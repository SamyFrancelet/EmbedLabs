
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
    pMutex_ = interface::XFMutex::create();
}

void XFTimeoutManager::addTimeout(XFTimeout *pNewTimeout)
{
    if(timeouts_.empty()) {
        timeouts_.push_back(pNewTimeout);
    } else {
        TimeoutList::iterator it;
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
    pTimeout->getBehavior()->pushEvent(pTimeout, true);
}

XFTimeoutManager::~XFTimeoutManager()
{
    for(XFTimeout* timeout : timeouts_) {
        delete timeout;
    }
}

void XFTimeoutManager::start(std::function<void (uint32_t)> startTimeoutManagerTimer)
{
    if (startTimeoutManagerTimer != nullptr) {
        startTimeoutManagerTimer(tickInterval_);
    }
}

void XFTimeoutManager::scheduleTimeout(int32_t timeoutId, int32_t interval, interface::XFBehavior *pBehavior)
{
    pMutex_->lock();
    addTimeout(new XFTimeout(timeoutId, interval, pBehavior));
    pMutex_->unlock();
}

void XFTimeoutManager::unscheduleTimeout(int32_t timeoutId, interface::XFBehavior *pBehavior)
{
    int relTicksToAdd = 0;

    pMutex_->lock();
    for(TimeoutList::iterator it = timeouts_.begin(); it != timeouts_.end(); it++) {
    	while ((*it)->getId() == timeoutId && (*it)->getBehavior() == pBehavior) {
    		relTicksToAdd = (*it)->getRelTicks();
    		it = timeouts_.erase(it);
    		(*it)->addToRelTicks(relTicksToAdd);
    	}
    }
    pMutex_->unlock();
}

void XFTimeoutManager::tick()
{
    //pMutex_->lock();
    if(!timeouts_.empty()) {
        timeouts_.front()->substractFromRelTicks(tickInterval_);
        while(timeouts_.front()->getRelTicks() <= 0) {
            returnTimeout(timeouts_.front());
            timeouts_.pop_front();
            if(timeouts_.empty()) { break; }
        }
    }
    //pMutex_->unlock();
}
