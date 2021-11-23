/*
 * ledstatesm.h
 *
 *  Created on: 23 nov. 2021
 *      Author: franc
 */

#ifndef LED_LEDSTATESM_H_
#define LED_LEDSTATESM_H_

#include <xf/behavior.h>

class ButtonEventsLedFlasher;

#define TIMEOUT_BLINK_TIME 200
#define SHORT_BLINK 2
#define LONG_BLINK 4

class LedStateSm: public XFBehavior {
public:
	LedStateSm(int index, ButtonEventsLedFlasher* parent);
	virtual ~LedStateSm();

	void onShortPress();
	void onLongPress();

protected:
	typedef enum{
		TIMEOUT_BLINK = 111
	} eTimeoutId;

	typedef enum{
		STATE_UNKNOWN = 112,
		STATE_INITIAL,
		STATE_WAIT_PRESS,
		STATE_ON,
		STATE_OFF
	} eState;

	eState currentState;

	XFEventStatus processEvent();

private:
	int nBlink;

	int ledIndex;
	ButtonEventsLedFlasher* parent;
};

#endif /* LED_LEDSTATESM_H_ */
