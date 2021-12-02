#ifndef EVBUTTONSHORTPRESS_H
#define EVBUTTONSHORTPRESS_H

#include "xf/customevent.h"
#include "events.h"

/**
 * @brief Event send when button is pressed.
 *
 * Used internally in state-machine handling one particular button.
 */
class evButtonShortPress : public XFCustomEvent
{
public:
	evButtonShortPress();
    evButtonShortPress(int buttonId);

    int buttonId;
};

#endif // EVBUTTONSHORTPRESS_H
