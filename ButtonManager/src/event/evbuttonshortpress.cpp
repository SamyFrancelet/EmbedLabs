#include "events.h"
#include "evbuttonshortpress.h"

evButtonShortPress::evButtonShortPress() :
	XFCustomEvent(evButtonShortPressId)
{
	this->buttonId = 0;
}

evButtonShortPress::evButtonShortPress(int buttonId) :
    XFCustomEvent(evButtonShortPressId)
{
	this->buttonId = buttonId;
}
