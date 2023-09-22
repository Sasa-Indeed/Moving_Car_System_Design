/*
 * led.c
 *
 * Created: 26/08/2023 13:04:09
 *  Author: Ahmed
 */ 

#include "led.h"

led_status_t ECUAL_led_init(uint8_t portx, uint8_t pinNumber){
	pin_config_t pinconfig;
	
	
	pinconfig.dioDirection = OUTPUT_MODE;
	pinconfig.portOptionEnable = PORT_OPTION_DISABLE;
	pinconfig.pinNumber = pinNumber;
	
	return (MCAL_dio_init(portx, &pinconfig) != DIO_OK) ? LED_INIT_ERROR : LED_OK;
		
}

led_status_t ECUAL_led_on(uint8_t portx, uint8_t pinNumber,uint8_t workCondtion){
	return (MCAL_dio_write_pin(portx, pinNumber, workCondtion) != DIO_OK) ? LED_ON_ERROR : LED_OK;
}

led_status_t ECUAL_led_off(uint8_t portx, uint8_t pinNumber, uint8_t workCondtion){
	
	if (workCondtion == HIGH){
		return (MCAL_dio_write_pin(portx, pinNumber, LOW) != DIO_OK) ? LED_OFF_ERROR : LED_OK;
	} else if (workCondtion == LOW) {
		return (MCAL_dio_write_pin(portx, pinNumber, HIGH) != DIO_OK) ? LED_OFF_ERROR : LED_OK;
	}else {
		return LED_OFF_ERROR;
	}
	
}

led_status_t ECUAL_led_toggle(uint8_t portx, uint8_t pinNumber){
	return (MCAL_dio_toggle_pin(portx, pinNumber) != DIO_OK) ? LED_TOGGLE_ERROR : LED_OK;
}
