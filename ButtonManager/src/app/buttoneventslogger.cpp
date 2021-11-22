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
}

ButtonEventsLogger::~ButtonEventsLogger() {
	// TODO Auto-generated destructor stub
}

void ButtonEventsLogger::onButtonShortPressed(interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex) {
	Trace::out("Button " + to_string(buttonIndex) + " short pressed");
}

void ButtonEventsLogger::onButtonLongPressed(interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex) {
	Trace::out("Button " + to_string(buttonIndex) + " long pressed");
}

}
