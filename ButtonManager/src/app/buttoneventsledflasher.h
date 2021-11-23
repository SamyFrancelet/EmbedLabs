/*
 * buttoneventsledflasher.h
 *
 *  Created on: 23 nov. 2021
 *      Author: franc
 */

#ifndef BUTTONEVENTSLEDFLASHER_H_
#define BUTTONEVENTSLEDFLASHER_H_

#include <interface/buttoneventshandlerobserver.h>
#include <led/ledstatesm.h>
#include <board/ledcontroller.h>
#include <vector>

class ButtonEventsLedFlasher: public interface::ButtonEventsHandlerObserver {
public:
	static ButtonEventsLedFlasher* getInstance();
	virtual ~ButtonEventsLedFlasher();

	void startLedsBehavior();

protected:
	void onButtonShortPressed(interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex);         ///< @brief Called by the subject upon a button short pressed.
    void onButtonLongPressed(interface::ButtonEventsHandlerObserver::ButtonIndex buttonIndex);          ///< @brief Called by the subject upon a button long pressed.

private:
    ButtonEventsLedFlasher();

    std::vector<LedStateSm*> leds;

    LedController lc;
};

#endif /* BUTTONEVENTSLEDFLASHER_H_ */
