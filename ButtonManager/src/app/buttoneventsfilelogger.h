/*
 * buttoneventsfilelogger.h
 *
 *  Created on: 23 nov. 2021
 *      Author: franc
 */

#ifndef BUTTONEVENTSFILELOGGER_H_
#define BUTTONEVENTSFILELOGGER_H_

#include <interface/buttoneventshandlerobserver.h>

class ButtonEventsFileLogger: public interface::ButtonEventsHandlerObserver {
public:
	static ButtonEventsFileLogger* getInstance();

protected:
	virtual void onButtonShortPressed(ButtonIndex buttonIndex);         ///< @brief Called by the subject upon a button short pressed.
    virtual void onButtonLongPressed(ButtonIndex buttonIndex);          ///< @brief Called by the subject upon a button long pressed.

private:
    ButtonEventsFileLogger();

};

#endif /* BUTTONEVENTSFILELOGGER_H_ */
