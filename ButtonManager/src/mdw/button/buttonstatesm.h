/*
 * buttonstatesm.h
 *
 *  Created on: 22 nov. 2021
 *      Author: Samy Francelet
 */

#ifndef BUTTON_BUTTONSTATESM_H_
#define BUTTON_BUTTONSTATESM_H_

#include <xf/behavior.h>

#define LONG_PRESS_TIME 1000

class ButtonEventsHandler;

class ButtonStateSm: public XFBehavior {
	typedef uint8_t ButtonIndex;

public:
	ButtonStateSm(ButtonIndex buttonIndex, ButtonEventsHandler* parent);
	virtual ~ButtonStateSm();

	void onChanged(bool pressed);

protected:
	typedef enum{
		TIMEOUT_LONG_PRESS = 11
	} eTimeoutId;

	typedef enum{
		STATE_UNKNOWN = 12,
		STATE_INITIAL,
		STATE_WAIT_PRESS,
		STATE_PRESSED,
		STATE_SHORT_PRESS,
		STATE_LONG_PRESS
	} eState;

	eState currentState;

	XFEventStatus processEvent();

private:
	ButtonEventsHandler* parent;
	ButtonIndex buttonIndex;
};

#endif /* BUTTON_BUTTONSTATESM_H_ */
