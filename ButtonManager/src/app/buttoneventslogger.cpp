/*
 * buttoneventslogger.cpp
 *
 *  Created on: 9 nov. 2021
 *      Author: franc
 */

#include "app/buttoneventslogger.h"
#include "mdw/trace/trace.h"

namespace app {


ButtonEventsLogger::ButtonEventsLogger() {
	// TODO Auto-generated constructor stub
	currentState_ = STATE_INITIAL;
}

ButtonEventsLogger::~ButtonEventsLogger() {
	// TODO Auto-generated destructor stub
}

void ButtonEventsLogger::onButtonShortPressed(interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex) {
	Trace::out("Button " + to_string(buttonIndex) + " short pressed");
}

XFEventStatus ButtonEventsLogger::processEvent() {
	XFEventStatus eventStatus = XFEventStatus::Unknown;

	switch(currentState_) {
	case STATE_INITIAL:
		if(getCurrentEvent()->getEventType() == XFEvent::Initial) {
			scheduleTimeout(Timeout_SAY_PEEP_id, 1000);
			currentState_ = STATE_SAY_PEEP;
			eventStatus = XFEventStatus::Consumed;
		}
		break;

	case STATE_SAY_PEEP:
		if (getCurrentEvent()->getEventType() == XFEvent::Timeout
					&& getCurrentEvent()->getId() == Timeout_SAY_PEEP_id) {
			Trace::out("Peep");
			scheduleTimeout(Timeout_SAY_PEEP_id, 1000);
			currentState_ = STATE_SAY_PEEP;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	default:
		break;
	}

	return eventStatus;
}

void ButtonEventsLogger::onButtonLongPressed(interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex) {
	Trace::out("Button " + to_string(buttonIndex) + " long pressed");
}

}
