#include <cassert>
#include <config/xf-config.h>

#if (USE_XF_IDF_STM32_XF_CLASS != 0)

#include "xf/interface/timeoutmanager.h"
#include "xf/interface/dispatcher.h"
#include "xf/xf.h"

using interface::XFTimeoutManager;

extern bool XF::isInitialized_;
extern bool XF::isRunning_;

void XF_initialize(int timeInterval)
{
    XF::initialize(timeInterval);
}

void XF_exec()
{
    XF::exec();
}

void XF_execOnce()
{
    XF::execOnce();
}

void XF::initialize(int timeInterval, int argc, char *argv[]) {
    if (!isInitialized_) {
        interface::XFTimeoutManager::getInstance()->initialize(timeInterval);
        interface::XFTimeoutManager::getInstance()->start();
        
        isInitialized_ = true;
    }
}

int XF::exec() {
    isRunning_ = true;
    while(1) {
        execOnce();
    }
}

int XF::execOnce() {
	isRunning_ = true;
    interface::XFDispatcher::getInstance()->executeOnce();

    return 0;
}

bool XF::isRunning() {
	return isRunning_ && isInitialized_;
}

// TODO: Implement code for XF class

#endif // USE_XF_IDF_STM32_XF_CLASS
