/*
 * buttoneventsledflasher.cpp
 *
 *  Created on: 23 nov. 2021
 *      Author: franc
 */

#include <app/buttoneventsledflasher.h>

ButtonEventsLedFlasher* ButtonEventsLedFlasher::getInstance() {
	static ButtonEventsLedFlasher ledFlash;
	return &ledFlash;
}

ButtonEventsLedFlasher::ButtonEventsLedFlasher() {
	// TODO Auto-generated constructor stub
	for(int i = 0; i < 4; i++) {
		leds.push_back(new LedStateSm(i, this));
	}
}

ButtonEventsLedFlasher::~ButtonEventsLedFlasher() {
	// TODO Auto-generated destructor stub
}

void ButtonEventsLedFlasher::startLedsBehavior() {
	for(int i = 0; i < 4; i++) {
		leds[i]->startBehavior();
	}
}

void ButtonEventsLedFlasher::onButtonShortPressed(
		interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex) {
	leds[buttonIndex]->onShortPress();
}

void ButtonEventsLedFlasher::onButtonLongPressed(
		interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex) {
	leds[buttonIndex]->onLongPress();
}
