#include "events.h"
#include "evbuttonlongpress.h"

evButtonLongPress::evButtonLongPress(int buttonId) :
    XFCustomEvent(evButtonLongPressId)
{
	this->buttonId = buttonId;
}

evButtonLongPress::evButtonLongPress() :
	XFCustomEvent(evButtonLongPressId){
		this->buttonId = 0;
}
