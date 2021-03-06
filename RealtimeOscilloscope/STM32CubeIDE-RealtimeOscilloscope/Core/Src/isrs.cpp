/*
 * isrs.cpp
 *
 *  Created on: Dec 14, 2021
 *      Author: Samy Francelet
 */

#include "stm32f7xx_hal.h"
#include "main.h"
#include "board/buttonscontroller.h"

extern "C" uint16_t adcValuesBuffer[ADC_VALUES_BUFFER_SIZE];// Defined in main.c

extern "C" void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	switch(GPIO_Pin) {
	case BUTTON0_Pin:
	case BUTTON1_Pin:
	case BUTTON2_Pin:
	case BUTTON3_Pin:
		ButtonsController::getInstance().onIrq();
		break;
	default:
		break;
	}
}

extern "C" void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
	volatile uint32_t value = HAL_ADC_GetValue(hadc);
	static uint8_t i = 0;
	adcValuesBuffer[i] = value;
	i++;
	if(i == ADC_VALUES_BUFFER_SIZE)
		i = 0;

}

extern "C" void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim) {
	/*static GPIO_PinState pinState = GPIO_PIN_RESET;

	if(htim->Instance == TIM1) {
		if(pinState == GPIO_PIN_RESET) {
			pinState = GPIO_PIN_SET;
		} else {
			pinState = GPIO_PIN_RESET;
		}

		HAL_GPIO_WritePin(TEST_TIM1_GPIO_Port, TEST_TIM1_Pin, pinState);
	}*/
}
