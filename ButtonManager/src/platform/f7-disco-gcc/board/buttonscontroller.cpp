/*
 * buttonscontroller.cpp
 *
 *  Created on: 11 nov. 2021
 *      Author: franc
 */

#include <board/buttonscontroller.h>

#include "event/evbuttonirq.h"
#include "event/events.h"
#include "mdw/trace/trace.h"
#include "main.h"

ButtonsController* ButtonsController::getInstance() {
	static ButtonsController bc;
	return &bc;
}

ButtonsController::ButtonsController() {
	// TODO Auto-generated constructor stub
	currentState = STATE_INITIAL;
}

ButtonsController::~ButtonsController() {
	// TODO Auto-generated destructor stub
}

bool ButtonsController::registerCallback(
		interface::ButtonsControllerCallbackProvider *callbackProvider,
		interface::ButtonsControllerCallbackProvider::CallbackMethod callbackMethod) {
	return false;
}

void ButtonsController::onIrq() {
	//GEN(evButtonIrq::evButtonIrq(EVENT_IRQ));
	pushEvent(new evButtonIrq(), true);
}

XFEventStatus ButtonsController::processEvent() {
	XFEventStatus eventStatus = XFEventStatus::Unknown;

	switch(currentState) {
	case STATE_INITIAL:
		if(getCurrentEvent()->getEventType() == XFEvent::Initial) {
			Trace::out("ButtonsController SM started");
			currentState = STATE_CHECK_BUTTONS;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_CHECK_BUTTONS:
		if(getCurrentEvent()->getEventType() == XFEvent::Event
				&& getCurrentEvent()->getId() == EventIds::evButtonIrqId) {
			currentState = STATE_DEBOUNCE;
			Trace::out("Waiting for debounce");
			scheduleTimeout(TIMEOUT_DEBOUNCE, DEBOUNCE_TIME);
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_DEBOUNCE:
		if (getCurrentEvent()->getEventType() == XFEvent::Timeout
					&& getCurrentEvent()->getId() == TIMEOUT_DEBOUNCE) {
			currentState = STATE_CHECK_BUTTONS;
			Trace::out("Checking buttons...");
			doCheckButtons();
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	default:
		break;
	}

	return eventStatus;
}

void ButtonsController::doCheckButtons() {
	if(!HAL_GPIO_ReadPin(GPIOI, BUTTON0_Pin)) {
		Trace::out("Button 0 pressed");
	} else {
		Trace::out("Button 0 not pressed");
	}

	if(!HAL_GPIO_ReadPin(GPIOI, BUTTON1_Pin)) {
		Trace::out("Button 1 pressed");
	} else {
		Trace::out("Button 1 not pressed");
	}

	if(!HAL_GPIO_ReadPin(GPIOG, BUTTON2_Pin)) {
		Trace::out("Button 2 pressed");
	} else {
		Trace::out("Button 2 not pressed");
	}

	if(!HAL_GPIO_ReadPin(GPIOG, BUTTON3_Pin)) {
		Trace::out("Button 3 pressed");
	} else {
		Trace::out("Button 3 not pressed");
	}
}
