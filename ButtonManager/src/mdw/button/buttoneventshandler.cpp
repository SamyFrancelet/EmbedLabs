/*
 * buttoneventshandler.cpp
 *
 *  Created on: 18 nov. 2021
 *      Author: franc
 */

#include <button/buttoneventshandler.h>
#include <app/buttoneventslogger.h>
#include <board/buttonscontroller.h>

ButtonEventsHandler* ButtonEventsHandler::getInstance() {
	static ButtonEventsHandler beh;
	return &beh;
}

ButtonEventsHandler::ButtonEventsHandler() {
	// TODO Auto-generated constructor stub
	for(int i = 0; i < 4; i++) {
		buttons.push_back(new ButtonStateSm(i, this));
	}

	ButtonsController::getInstance()->registerCallback(this,
			(interface::ButtonsControllerCallbackProvider::CallbackMethod)&ButtonEventsHandler::onButtonChanged);
}

ButtonEventsHandler::~ButtonEventsHandler() {
	// TODO Auto-generated destructor stub
	for(ButtonStateSm* button : buttons) {
		delete button;
	}
}

void ButtonEventsHandler::startButtonsBehavior() {
	for(ButtonStateSm* button : buttons) {
		button->startBehavior();
	}
}

void ButtonEventsHandler::onButtonChanged(ButtonIndex buttonIndex, bool pressed) {
	buttons[buttonIndex]->onChanged(pressed);
}

bool ButtonEventsHandler::subscribe(interface::ButtonEventsHandlerObserver *observer) {
	if(observer != nullptr) {
		observers.push_back(observer);
		return true;
	}
	return false;
}

void ButtonEventsHandler::unsubscribe(interface::ButtonEventsHandlerObserver *observer) {
	observers.remove(observer);
}

void ButtonEventsHandler::notifyButtonShortPressed(ButtonIndex buttonIndex) {
	for(interface::ButtonEventsHandlerObserver* observer : observers) {
		observer->onButtonShortPressed(buttonIndex);
	}
}

void ButtonEventsHandler::notifyButtonLongPressed(ButtonIndex buttonIndex) {
	for(interface::ButtonEventsHandlerObserver* observer : observers) {
		observer->onButtonLongPressed(buttonIndex);
	}
}
