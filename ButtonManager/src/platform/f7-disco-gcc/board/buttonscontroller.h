/*
 * buttonscontroller.h
 *
 *  Created on: 11 nov. 2021
 *      Author: franc
 */

#ifndef F7_DISCO_GCC_BOARD_BUTTONSCONTROLLER_H_
#define F7_DISCO_GCC_BOARD_BUTTONSCONTROLLER_H_

#include "interface/buttonirq.h"
#include "interface/buttonscontrollercallbackcaller.h"
#include "interface/buttonscontrollercallbackprovider.h"

class ButtonsController : interface::ButtonIrq, interface::ButtonsControllerCallbackCaller{
public:
	ButtonsController();
	virtual ~ButtonsController();

    /**
     * @brief Registers a callback method with its called pointer (callback provider).
     *
     * @return Returns true of the callback provider could be registered, otherwise false.
     */
    bool registerCallback(interface::ButtonsControllerCallbackProvider * callbackProvider,
                                  interface::ButtonsControllerCallbackProvider::CallbackMethod callbackMethod);

    void onIrq();	///< @brief Called by the ISR.
};

#endif /* F7_DISCO_GCC_BOARD_BUTTONSCONTROLLER_H_ */
