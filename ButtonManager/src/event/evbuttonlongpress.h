#ifndef EVBUTTONLONGPRESS_H
#define EVBUTTONLONGPRESS_H

#include "xf/customevent.h"
#include "events.h"

/**
 * @brief Event send when button is pressed.
 *
 * Used internally in state-machine handling one particular button.
 */
class evButtonLongPress : public XFCustomEvent
{
public:
    evButtonLongPress();
};

#endif // EVBUTTONLONGPRESS_H
