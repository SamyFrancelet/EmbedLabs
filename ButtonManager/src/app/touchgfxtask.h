#ifndef TOUCHGFXTASK_H
#define TOUCHGFXTASK_H

#include "config/touchgfx-config.h"

#if defined(TOUCHGFX_ENABLED) && (TOUCHGFX_ENABLED != 0)

#include "xf/behavior.h"
#include "mdw/button/buttoneventshandler.h"

/**
 * @brief TouchGFX task used in IDF and/or bare-metal environments to drive LCD display.
 */
class TouchGfxTask : public XFBehavior
{
public:
    TouchGfxTask();

    void initialize(ButtonEventsHandler & buttonEventsHandler);
    void start();

protected:
    XFEventStatus processEvent() override;

protected:
    const int32_t interval_;
};

#endif // TOUCHGFX_ENABLED
#endif // TOUCHGFXTASK_H
