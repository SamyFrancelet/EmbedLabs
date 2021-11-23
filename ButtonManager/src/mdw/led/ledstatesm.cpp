/*
 * ledstatesm.cpp
 *
 *  Created on: 23 nov. 2021
 *      Author: franc
 */

#include <led/ledstatesm.h>
#include <event/events.h>
#include <board/ledcontroller.h>
#include <event/evbuttonlongpress.h>
#include <event/evbuttonshortpress.h>

LedStateSm::LedStateSm(int index, ButtonEventsLedFlasher* parent) {
	// TODO Auto-generated constructor stub
	this->ledIndex = index;
	this->parent = parent;
	currentState = STATE_INITIAL;
}

LedStateSm::~LedStateSm() {
	// TODO Auto-generated destructor stub
}

XFEventStatus LedStateSm::processEvent() {
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
				&& getCurrentEvent()->getId() == EventIds::evButtonShortPressId) {
			nBlink = SHORT_BLINK;
			currentState = STATE_ON;
			eventStatus = XFEventStatus::Consumed;
		} else if(getCurrentEvent()->getEventType() == XFEvent::Event
				&& getCurrentEvent()->getId() == EventIds::evButtonLongPressId) {
			nBlink = LONG_BLINK;
			currentState = STATE_ON;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_ON:
		if(getCurrentEvent()->getEventType() == XFEvent::Timeout
				&& getCurrentEvent()->getId() == TIMEOUT_BLINK) {
			currentState = STATE_OFF;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_OFF:
		if(getCurrentEvent()->getEventType() == XFEvent::Timeout
				&& getCurrentEvent()->getId() == TIMEOUT_BLINK) {
			currentState = STATE_ON;
			eventStatus = XFEventStatus::Consumed;
		} else if(getCurrentEvent()->getEventType() == XFEvent::NullTransition) {
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
		case STATE_ON:
			LedController::getInstance().setLed(ledIndex, true);
			scheduleTimeout(TIMEOUT_BLINK, TIMEOUT_BLINK_TIME);
			break;
		case STATE_OFF:
			LedController::getInstance().setLed(ledIndex, false);
			nBlink--;
			if (nBlink <= 0) {
				GEN(XFNullTransition());
			} else {
				scheduleTimeout(TIMEOUT_BLINK, TIMEOUT_BLINK_TIME);
			}
		default:
			break;
		}
	}

	return eventStatus;
}

void LedStateSm::onShortPress() {
	GEN(evButtonShortPress());
}

void LedStateSm::onLongPress() {
	GEN(evButtonLongPress());
}
