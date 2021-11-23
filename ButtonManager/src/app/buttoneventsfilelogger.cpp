/*
 * buttoneventsfilelogger.cpp
 *
 *  Created on: 23 nov. 2021
 *      Author: franc
 */

#include <app/buttoneventsfilelogger.h>

ButtonEventsFileLogger* ButtonEventsFileLogger::getInstance() {
	static ButtonEventsFileLogger befl;
	return &befl;
}

void ButtonEventsFileLogger::onButtonShortPressed(ButtonIndex buttonIndex) {
}

void ButtonEventsFileLogger::onButtonLongPressed(ButtonIndex buttonIndex) {
}

ButtonEventsFileLogger::ButtonEventsFileLogger() {
	// TODO Auto-generated constructor stub

}

