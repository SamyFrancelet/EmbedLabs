#include "trace/trace.h"
#include "touchgfxtask.h"
#include "factory.h"

namespace app
{

Factory::Factory()
{

}

// static
void Factory::initialize()
{
    Trace::initialize();

    // TODO: Initialize factory attributes here

#if defined(TOUCHGFX_ENABLED) && (TOUCHGFX_ENABLED != 0)
    getTouchGfxTask().initialize(_buttonEventsHandler);
#endif
}

// static
void Factory::build()
{
//    Trace::out("Factory: Creating app components...");

    // Start state machine(s)
	
    // TODO: Start state-machines here

#if defined(TOUCHGFX_ENABLED) && (TOUCHGFX_ENABLED != 0)
    getTouchGfxTask().start();
#endif
}

#if defined(TOUCHGFX_ENABLED) && (TOUCHGFX_ENABLED != 0)
// static
TouchGfxTask & Factory::getTouchGfxTask()
{
    static TouchGfxTask touchGfxTask;
    return touchGfxTask;
}
#endif // TOUCHGFX_ENABLED

} /* namespace app */

void Factory_initialize()
{
    app::Factory::initialize();
}

void Factory_build()
{
    app::Factory::build();
}
