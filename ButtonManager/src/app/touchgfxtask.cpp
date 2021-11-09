#include "TouchGFX/App/app_touchgfx.h"
#include "gui/common/FrontendHeap.hpp"
#include "touchgfxtask.h"

#if defined(TOUCHGFX_ENABLED) && (TOUCHGFX_ENABLED != 0)

extern "C" void touchgfx_init();
extern "C" void touchgfx_taskEntry();

TouchGfxTask::TouchGfxTask():
    interval_(20)
{

}

void TouchGfxTask::initialize(ButtonEventsHandler & buttonEventsHandler)
{
    touchgfx_init();

    // Let the GUI model subscribe itself to button events
    FrontendHeap::getInstance().model.initialize(buttonEventsHandler);
}

void TouchGfxTask::start()
{
    startBehavior();
}

XFEventStatus TouchGfxTask::processEvent()
{
    if (getCurrentEvent()->getEventType() == XFEvent::Initial)
    {
        scheduleTimeout(1, 20);
    }

    // React on button events short and long pressed
    if (getCurrentEvent()->getEventType() == XFEvent::Timeout and
        getCurrentTimeout()->getId() == 1)
    {
        touchgfx_taskEntry();

        scheduleTimeout(1, 20);
    }

    return XFEventStatus::Consumed;
}

#endif // TOUCHGFX_ENABLED
