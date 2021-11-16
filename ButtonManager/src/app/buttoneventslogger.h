/*
 * buttoneventslogger.h
 *
 *  Created on: 9 nov. 2021
 *      Author: franc
 */

#ifndef BUTTONEVENTSLOGGER_H_
#define BUTTONEVENTSLOGGER_H_

#include "xf/behavior.h"
#include "interface/buttoneventshandlerobserver.h"

namespace app{

class ButtonEventsLogger : public interface::ButtonEventsHandlerObserver, public XFBehavior {
public:
	ButtonEventsLogger();
	virtual ~ButtonEventsLogger();

protected:

	typedef enum{
		Timeout_SAY_PEEP_id = 1
	} eTimeoutId;

	typedef enum{
		STATE_UNKNOWN = 0,
		STATE_INITIAL = 1,
		STATE_SAY_PEEP = 2
	} eState;

	eState currentState_;

	XFEventStatus processEvent();

	void onButtonShortPressed(interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex);         ///< @brief Called by the subject upon a button short pressed.
    void onButtonLongPressed(interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex);          ///< @brief Called by the subject upon a button long pressed.
};

}

#endif /* BUTTONEVENTSLOGGER_H_ */
