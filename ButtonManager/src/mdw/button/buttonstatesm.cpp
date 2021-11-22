/*
 * buttonstatesm.cpp
 *
 *  Created on: 22 nov. 2021
 *      Author: Samy Francelet
 */

#include <button/buttoneventshandler.h>
#include "event/evbuttonpressed.h"
#include "event/evbuttonreleased.h"
#include <button/buttonstatesm.h>
#include <event/events.h>

ButtonStateSm::ButtonStateSm(ButtonIndex buttonIndex, ButtonEventsHandler* parent) {
	// TODO Auto-generated constructor stub
	currentState = STATE_INITIAL;
	this->parent = parent;
	this->buttonIndex = buttonIndex;
}

ButtonStateSm::~ButtonStateSm() {
	// TODO Auto-generated destructor stub
}

void ButtonStateSm::onChanged(bool pressed) {
	//pushEvent((XFCustomEvent*)(pressed ? (new evButtonPressed()) : (new evButtonReleased())), false); ='(
	if(pressed)
		pushEvent(new evButtonPressed(), false);
	else
		pushEvent(new evButtonReleased(), false);
}

XFEventStatus ButtonStateSm::processEvent() {
	XFEventStatus eventStatus = XFEventStatus::NotConsumed;

	eState oldState = currentState;

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
				&& getCurrentEvent()->getId() == EventIds::evButtonPressedId) {
			currentState = STATE_PRESSED;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_PRESSED:
		if(getCurrentEvent()->getEventType() == XFEvent::Event
				&& getCurrentEvent()->getId() == EventIds::evButtonReleasedId) {
			currentState = STATE_SHORT_PRESS;
			eventStatus = XFEventStatus::Consumed;
		} else if (getCurrentEvent()->getEventType() == XFEvent::Timeout
				&& getCurrentEvent()->getId() == TIMEOUT_LONG_PRESS){
			currentState = STATE_LONG_PRESS;
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
		case STATE_PRESSED:
			scheduleTimeout(TIMEOUT_LONG_PRESS, LONG_PRESS_TIME);
			break;
		case STATE_SHORT_PRESS:
			unscheduleTimeout(TIMEOUT_LONG_PRESS);
			parent->notifyButtonShortPressed(this->buttonIndex);
			GEN(XFNullTransition);
			break;
		case STATE_LONG_PRESS:
			parent->notifyButtonLongPressed(this->buttonIndex);
			GEN(XFNullTransition);
			break;
		default:
			break;
		}
	}

	return eventStatus;
}
