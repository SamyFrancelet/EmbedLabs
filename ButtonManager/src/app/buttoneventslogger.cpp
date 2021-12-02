/*
 * buttoneventslogger.cpp
 *
 *  Created on: 9 nov. 2021
 *      Author: franc
 */

#include "app/buttoneventslogger.h"
#include "mdw/trace/trace.h"
#include "event/events.h"
#include "event/evbuttonlongpress.h"
#include "event/evbuttonshortpress.h"

namespace app {


ButtonEventsLogger::ButtonEventsLogger() {
	// TODO Auto-generated constructor stub
	currentState = STATE_INITIAL;
}

ButtonEventsLogger::~ButtonEventsLogger() {
	// TODO Auto-generated destructor stub
}

void ButtonEventsLogger::onButtonShortPressed(interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex) {
	GEN(evButtonShortPress(buttonIndex));
}

void ButtonEventsLogger::onButtonLongPressed(interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex) {
	GEN(evButtonLongPress(buttonIndex));
}

XFEventStatus ButtonEventsLogger::processEvent() {
	XFEventStatus eventStatus = XFEventStatus::NotConsumed;

	eState oldState = currentState;

	int buttonId = 0;

	// Switch conditions
	switch(currentState) {
	case STATE_INITIAL:
		if(getCurrentEvent()->getEventType() == XFEvent::Initial) {
			currentState = STATE_WAIT_PRESS;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_WAIT_PRESS:
		if(getCurrentEvent()->getEventType() == XFEvent::Event
				&& getCurrentEvent()->getId() == EventIds::evButtonShortPressId) {
			currentState = STATE_SHORT_PRESS;
			buttonId = static_cast<const evButtonShortPress*>(getCurrentEvent())->buttonId;
			eventStatus = XFEventStatus::Consumed;
		} else if(getCurrentEvent()->getEventType() == XFEvent::Event
				&& getCurrentEvent()->getId() == EventIds::evButtonLongPressId) {
			currentState = STATE_LONG_PRESS;
			buttonId = static_cast<const evButtonLongPress*>(getCurrentEvent())->buttonId;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_SHORT_PRESS:
	case STATE_LONG_PRESS:
		if(getCurrentEvent()->getEventType() == XFEvent::NullTransition) {
			currentState = STATE_WAIT_PRESS;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	default:
		break;
	}


	if(oldState != currentState) {
		// onExit actions
		switch(oldState) {
		default:
			break;
		}

		// onEntry actions
		switch(currentState) {
		case STATE_SHORT_PRESS:
			Trace::out("Button " + to_string(buttonId) + " short pressed");
			GEN(XFNullTransition);
			break;
		case STATE_LONG_PRESS:
			Trace::out("Button " + to_string(buttonId) + " long pressed");
			GEN(XFNullTransition);
			break;
		default:
			break;
		}
	}

	return eventStatus;
}

}
