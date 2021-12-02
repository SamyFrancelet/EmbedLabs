/*
 * buttoneventslogger.h
 *
 *  Created on: 9 nov. 2021
 *      Author: franc
 */

#ifndef BUTTONEVENTSLOGGER_H_
#define BUTTONEVENTSLOGGER_H_

#include <interface/buttoneventshandlerobserver.h>
#include <xf/behavior.h>

namespace app{

class ButtonEventsLogger : public interface::ButtonEventsHandlerObserver, public XFBehavior {
public:
	ButtonEventsLogger();
	virtual ~ButtonEventsLogger();

protected:
	void onButtonShortPressed(interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex);         ///< @brief Called by the subject upon a button short pressed.
    void onButtonLongPressed(interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex);          ///< @brief Called by the subject upon a button long pressed.

	typedef enum{

	} eTimeoutId;

	typedef enum{
		STATE_UNKNOWN = 202,
		STATE_INITIAL,
		STATE_WAIT_PRESS,
		STATE_SHORT_PRESS,
		STATE_LONG_PRESS
	} eState;

	eState currentState;

	XFEventStatus processEvent();

};

}

#endif /* BUTTONEVENTSLOGGER_H_ */
