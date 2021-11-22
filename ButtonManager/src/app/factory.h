#ifndef FACTORY_H
#define FACTORY_H

//
// What is seen only by the C++ compiler
//
#ifdef __cplusplus

#include "config/touchgfx-config.h"

// TODO: Add C++ specific includes here
#include "app/buttoneventslogger.h"
#include "board/buttonscontroller.h"
#include "button/buttoneventshandler.h"

namespace app
{

/**
 * @brief Application factory responsible to create needed objects.
 */
class Factory
{
public:
    Factory();

    static void initialize();           ///< Initializes the factory
    static void build();                ///< Creates components and initializes relations

#if defined(TOUCHGFX_ENABLED) && (TOUCHGFX_ENABLED != 0)
    static TouchGfxTask & getTouchGfxTask();
#endif

protected:
    // TODO: Add static attributes here
    static ButtonEventsLogger* btnEvLog;
    static ButtonsController* btnCtrl;
    static ButtonEventsHandler* btnEvHand;
};

} /* namespace app */
#endif // __cplusplus

//
// What is seen by the C and C++ compiler
//
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void Factory_initialize();
void Factory_build();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // FACTORY_H
