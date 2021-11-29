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
	_callbackProvider = nullptr;
	_callbackMethod = nullptr;
	btnInterrupt = new evButtonIrq();
}

ButtonsController::~ButtonsController() {
	// TODO Auto-generated destructor stub
}

bool ButtonsController::registerCallback(
		interface::ButtonsControllerCallbackProvider *callbackProvider,
		interface::ButtonsControllerCallbackProvider::CallbackMethod callbackMethod) {

	if(callbackProvider != nullptr && callbackMethod != nullptr) {
		_callbackProvider = callbackProvider;
		_callbackMethod = callbackMethod;
		return true;
	}

	return false;
}

void ButtonsController::onIrq() {
	//GEN(evButtonIrq::evButtonIrq(EVENT_IRQ));
	pushEvent(btnInterrupt, true);
}

XFEventStatus ButtonsController::processEvent() {
	XFEventStatus eventStatus = XFEventStatus::NotConsumed;

	eState oldState = currentState;

	// Switch conditions
	switch(currentState) {
	case STATE_INITIAL:
		if(getCurrentEvent()->getEventType() == XFEvent::Initial) {
			//Trace::out("ButtonsController SM started");
			currentState = STATE_CHECK_BUTTONS;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_CHECK_BUTTONS:
		if(getCurrentEvent()->getEventType() == XFEvent::Event
				&& getCurrentEvent()->getId() == EventIds::evButtonIrqId) {
			currentState = STATE_DEBOUNCE;
			eventStatus = XFEventStatus::Consumed;
		}
		break;
	case STATE_DEBOUNCE:
		if (getCurrentEvent()->getEventType() == XFEvent::Timeout
				&& getCurrentEvent()->getId() == TIMEOUT_DEBOUNCE) {
			currentState = STATE_CHECK_BUTTONS;
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
		case STATE_CHECK_BUTTONS:
			if(oldState == STATE_DEBOUNCE) {
				//Trace::out("Buttons states :");
				doCheckButtons();
			}
			break;

		case STATE_DEBOUNCE:
			//Trace::out("Waiting for debounce...");
			scheduleTimeout(TIMEOUT_DEBOUNCE, DEBOUNCE_TIME);
			break;

		default:
			break;
		}
	}


	return eventStatus;
}

void ButtonsController::doCheckButtons() {
	static bool btnState[4] = {false, false, false, false};

	bool newBtnState[4];

	newBtnState[0] = !HAL_GPIO_ReadPin(BUTTON0_GPIO_Port, BUTTON0_Pin);
	newBtnState[1] = !HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
	newBtnState[2] = !HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
	newBtnState[3] = !HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);

	uint16_t i = 0;
	for(i = 0; i < 4; i++) {
		if(btnState[i] != newBtnState[i]) {
			btnState[i] = newBtnState[i];
			if(_callbackProvider != nullptr) {
				(_callbackProvider->*_callbackMethod)(i, btnState[i]);
			}
			//Trace::out("Button %d %s", i, btnState[i]?"pressed":"released");
		}
	}
}
