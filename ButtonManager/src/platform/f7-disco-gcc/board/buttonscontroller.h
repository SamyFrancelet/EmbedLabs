/*
 * buttonscontroller.h
 *
 *  Created on: 11 nov. 2021
 *      Author: franc
 */

#ifndef F7_DISCO_GCC_BOARD_BUTTONSCONTROLLER_H_
#define F7_DISCO_GCC_BOARD_BUTTONSCONTROLLER_H_

#include "xf/behavior.h"
#include "interface/buttonirq.h"
#include "interface/buttonscontrollercallbackcaller.h"
#include "interface/buttonscontrollercallbackprovider.h"

#define DEBOUNCE_TIME 100

class ButtonsController : public interface::ButtonIrq, public interface::ButtonsControllerCallbackCaller, public XFBehavior{
public:
	static ButtonsController* getInstance();
	void onIrq();	///< @brief Called by the ISR.
	virtual ~ButtonsController();

protected :
    /**
     * @brief Registers a callback method with its called pointer (callback provider).
     *
     * @return Returns true of the callback provider could be registered, otherwise false.
     */
    bool registerCallback(interface::ButtonsControllerCallbackProvider * callbackProvider,
                                  interface::ButtonsControllerCallbackProvider::CallbackMethod callbackMethod);

	typedef enum{
		TIMEOUT_DEBOUNCE = 1
	} eTimeoutId;

	typedef enum{
		STATE_UNKNOWN = 0,
		STATE_INITIAL = 1,
		STATE_CHECK_BUTTONS = 2,
		STATE_DEBOUNCE = 3
	} eState;

	eState currentState;

	XFEventStatus processEvent();

private:
	ButtonsController();

	void doCheckButtons();

	interface::ButtonsControllerCallbackProvider* _callbackProvider;
	interface::ButtonsControllerCallbackProvider::CallbackMethod _callbackMethod;
};

#endif /* F7_DISCO_GCC_BOARD_BUTTONSCONTROLLER_H_ */
