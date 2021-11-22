/*
 * buttoneventshandler.h
 *
 *  Created on: 18 nov. 2021
 *      Author: franc
 */

#ifndef BUTTON_BUTTONEVENTSHANDLER_H_
#define BUTTON_BUTTONEVENTSHANDLER_H_

#include <board/interface/buttonscontrollercallbackprovider.h>
#include <interface/buttoneventshandlersubject.h>

class ButtonEventsHandler: public interface::ButtonsControllerCallbackProvider,
		public interface::ButtonEventsHandlerSubject {
public:
	ButtonEventsHandler();
	virtual ~ButtonEventsHandler();

// ButtonEventHandlerSubject
public:
	bool subscribe(ButtonEventsHandlerObserver * observer);			    ///< @brief Registers a new observer. Returns true on success.
	void unsubscribe(ButtonEventsHandlerObserver * observer);	        ///< @brief Un-subscribes a registered observer.

protected:
	void notifyButtonShortPressed(ButtonIndex buttonIndex);	            ///< @brief Notifies observers about a button short pressed.
    void notifyButtonLongPressed(ButtonIndex buttonIndex);              ///< @brief Notifies observers about a button long pressed.
};

#endif /* BUTTON_BUTTONEVENTSHANDLER_H_ */
