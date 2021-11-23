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
#include <button/buttonstatesm.h>
#include <vector>
#include <list>

class ButtonEventsHandler: public interface::ButtonsControllerCallbackProvider,
		public interface::ButtonEventsHandlerSubject {

	friend class ButtonStateSm;
public:
	static ButtonEventsHandler* getInstance();
	virtual ~ButtonEventsHandler();

	void startButtonsBehavior();
	void onButtonChanged(ButtonIndex buttonIndex, bool pressed);

// ButtonEventHandlerSubject
public:
	bool subscribe(interface::ButtonEventsHandlerObserver * observer);			    ///< @brief Registers a new observer. Returns true on success.
	void unsubscribe(interface::ButtonEventsHandlerObserver * observer);	        ///< @brief Un-subscribes a registered observer.

protected:
	void notifyButtonShortPressed(ButtonIndex buttonIndex);	            ///< @brief Notifies observers about a button short pressed.
    void notifyButtonLongPressed(ButtonIndex buttonIndex);              ///< @brief Notifies observers about a button long pressed.

private:
    ButtonEventsHandler();

    std::list<interface::ButtonEventsHandlerObserver*> observers;
    std::vector<ButtonStateSm*> buttons;
};

#endif /* BUTTON_BUTTONEVENTSHANDLER_H_ */
