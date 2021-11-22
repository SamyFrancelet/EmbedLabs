/*
 * buttoneventslogger.h
 *
 *  Created on: 9 nov. 2021
 *      Author: franc
 */

#ifndef BUTTONEVENTSLOGGER_H_
#define BUTTONEVENTSLOGGER_H_

#include <interface/buttoneventshandlerobserver.h>

namespace app{

class ButtonEventsLogger : public interface::ButtonEventsHandlerObserver {
public:
	ButtonEventsLogger();
	virtual ~ButtonEventsLogger();

protected:
	void onButtonShortPressed(interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex);         ///< @brief Called by the subject upon a button short pressed.
    void onButtonLongPressed(interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex);          ///< @brief Called by the subject upon a button long pressed.
};

}

#endif /* BUTTONEVENTSLOGGER_H_ */
