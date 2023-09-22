/*
 * led.h
 *
 * Created: 26/08/2023 13:03:56
 *  Author: Ahmed
 */ 


#ifndef LED_H_
#define LED_H_


//--------------------------------
//			Includes
//--------------------------------


#include "../../INC/platform_types.h"
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/TIMER/timer.h"



//--------------------------------
//Macros Configuration References
//--------------------------------

//@ref led_ports
#define LED_PORTA								'A'
#define LED_PORTB								'B'
#define LED_PORTC								'C'
#define LED_PORTD								'D'

typedef enum{
	LED_OK,
	LED_INIT_ERROR,
	LED_ON_ERROR,
	LED_OFF_ERROR,
	LED_TOGGLE_ERROR,
	LED_BLINK_ERROR
	}led_status_t;

/*@ref pin_numbers
 * PIN_0
 * PIN_1
 * PIN_2
 * PIN_3
 * PIN_4
 * PIN_5
 * PIN_6
 * PIN_7
 */

/*@ref work_condtions
 * HIGH: set if you want the led to work with high configuration
 * LOW: set if you want the led to work with low configuration
 */


//------------------------------------------------------------------------------------------
//                              APIs supported by "ECUAL LED Driver"
//------------------------------------------------------------------------------------------


/****************************************************************************
* Function Name: ECUAL_led_init
*
* Description : This function initializes the LEDs
*
* PARAMETER1  : The port on which the LED is connected
*
* PARAMETER2  : The pin on which the LED is connected
*
* Return Value: Status about the function
*
* Note!!!	  : In parameter 1,2 must be from @ref led_ports ,@ref pin_numbers respectively
******************************************************************************/
led_status_t ECUAL_led_init(uint8_t portx, uint8_t pinNumber);


/****************************************************************************
* Function Name: ECUAL_led_on
*
* Description : This function turns on a certain led
*
* PARAMETER1  : The port on which the LED is connected
*
* PARAMETER2  : The pin on which the LED is connected
*
* PARAMETER3  : How the LED will work by high or low
*
* Return Value: Status about the function
*
* Note!!!	  : In parameter 1,2,3 must be from @ref led_ports ,@ref pin_numbers,
* @ref work_condtions respectively
******************************************************************************/
led_status_t ECUAL_led_on(uint8_t portx, uint8_t pinNumber, uint8_t workCondtion);


/****************************************************************************
* Function Name: ECUAL_led_off
*
* Description : This function turns on a certain led
*
* PARAMETER1  : The port on which the LED is connected
*
* PARAMETER2  : The pin on which the LED is connected
*
* PARAMETER3  : How the LED turned on whether by high or low
*
* Return Value: Status about the function
*
* Note!!!	  : In parameter 1,2,3 must be from @ref led_ports ,@ref pin_numbers,
* @ref work_condtions respectively
******************************************************************************/
led_status_t ECUAL_led_off(uint8_t portx, uint8_t pinNumber, uint8_t workCondtion);


/****************************************************************************
* Function Name: ECUAL_led_toggle
*
* Description : This function toggles a certain led
*
* PARAMETER1  : The port on which the LED is connected
*
* PARAMETER2  : The pin on which the LED is connected
*
* Return Value: Status about the function
*
* Note!!!	  : In parameter 1,2 must be from @ref led_ports ,@ref pin_numbers, respectively
******************************************************************************/
led_status_t ECUAL_led_toggle(uint8_t portx, uint8_t pinNumber);

#endif /* LED_H_ */