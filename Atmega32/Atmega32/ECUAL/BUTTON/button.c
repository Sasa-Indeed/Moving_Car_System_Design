/*
 * button.c
 *
 * Created: 26/08/2023 15:02:06
 *  Author: Ahmed
 */ 
#include "button.h"


button_status_t ECUAL_button_init(uint8_t portx, uint8_t pinNumber){
	pin_config_t pinconfig;
			
	pinconfig.dioDirection = INPUT_MODE;
	pinconfig.portOptionEnable = PORT_OPTION_DISABLE;
	pinconfig.pinNumber = pinNumber;
	
	
	return (MCAL_dio_init(portx, &pinconfig) != DIO_OK) ? BUTTON_INIT_ERROR : BUTTON_OK;
}


button_status_t ECUAL_button_read(uint8_t portx, uint8_t pinNumber, uint8_t * value){
	return (MCAL_dio_read_pin(portx, pinNumber, value) != DIO_OK) ? BUTTON_READ_ERROR : BUTTON_OK;	
}


button_status_t ECUAL_button_enable_EXTI(uint8_t EXTINumber, void (* callback)(void), uint8_t triggerCase){
	exti_config_t exti;
	
	exti.extiEnable = EXTI_ENABLE;
	
	exti.extiNumber = EXTINumber;
	
	exti.triggerCase = triggerCase;
	
	exti.P_IRQ_callback = callback;
	
	if (MCAL_EXTI_init(&exti) != EXTI_OK){
		return BUTTON_EXTI_ERROR;
	} 
	
	return BUTTON_OK;
}