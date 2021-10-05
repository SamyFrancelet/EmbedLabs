
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

}

void XFTimeoutManager::returnTimeout(XFTimeout *pTimeout)
{

}

XFTimeoutManager::~XFTimeoutManager()
{

}

void XFTimeoutManager::start(std::function<void (uint32_t)> startTimeoutManagerTimer)
{

}

void XFTimeoutManager::scheduleTimeout(int32_t timeoutId, int32_t interval, interface::XFBehavior *pBehavior)
{

}

void XFTimeoutManager::unscheduleTimeout(int32_t timeoutId, interface::XFBehavior *pBehavior)
{

}

void XFTimeoutManager::tick()
{

}
