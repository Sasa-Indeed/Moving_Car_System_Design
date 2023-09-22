/*
 * button.h
 *
 * Created: 26/08/2023 15:02:19
 *  Author: Ahmed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

//--------------------------------
//			Includes
//--------------------------------


#include "../../INC/platform_types.h"
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/EXTERNAL_INTERRUPT/external_interrupt.h"


//--------------------------------
//Macros Configuration References
//--------------------------------

#define BUTTON_SET									1
#define BUTTON_RESET								0

//@ref Button_ports
#define BUTTON_PORTA								'A'
#define BUTTON_PORTB								'B'
#define BUTTON_PORTC								'C'
#define BUTTON_PORTD								'D'

typedef enum{
	BUTTON_OK,
	BUTTON_INIT_ERROR,
	BUTTON_READ_ERROR,
	BUTTON_EXTI_ERROR
}button_status_t;


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


/*
 * For @ref EXTI_Number use these macros: 
 * EXTI0
 * EXTI1
 * EXTI2
 */

/*
 * For @ref Trigger_Cases use these macros:
 * This for INT0 & INT1 ONLY!!!
 * TRIGGER_CASE_LOW_LEVEL
 * TRIGGER_CASE_ANY_CHANGE	
 * TRIGGER_CASE_FALLING_EDGE
 * TRIGGER_CASE_RISING_EDGE

 * This for INT2 ONLY!!!
 * TRIGGER_INT2_CASE_FALLING_EDGE
 * TRIGGER_INT2_CASE_RISING_EDGE
 */

//------------------------------------------------------------------------------------------
//                              APIs supported by "ECUAL Button Driver"
//------------------------------------------------------------------------------------------

/****************************************************************************
* Function Name: ECUAL_button_init
*
* Description : This function initializes the buttons
*
* PARAMETER1  : The port on which the button is connected
*
* PARAMETER2  : The pin on which the button is connected
*
* Return Value: Status about the function
*
* Note!!!	  : In parameter 1,2 must be from @ref Button_ports, @ref pin_numbers respectively
******************************************************************************/
button_status_t ECUAL_button_init(uint8_t portx, uint8_t pinNumber);

/****************************************************************************
* Function Name: ECUAL_button_read
*
* Description : This function reads from a buttons
*
* PARAMETER1  : The port on which the button is connected
*
* PARAMETER2  : The pin on which the button is connected
*
* PARAMETER3  : The variable which will have the data from the button
*
* Return Value: Status about the function
*
* Note!!!	  : In parameter 1,2 must be from @ref Button_ports, @ref pin_numbers respectively
******************************************************************************/
button_status_t ECUAL_button_read(uint8_t portx, uint8_t pinNumber, uint8_t * value);

/****************************************************************************
* Function Name: ECUAL_button_enable_EXTI
*
* Description : This function makes the button works as external interrupt
*
* PARAMETER1  : The external interrupt you want to use
*
* PARAMETER2  : The function that will be called
*
* PARAMETER3  : The trigger case for the interrupt
*
* Return Value: Status about the function
*
* Note!!!	  : In parameter 1,3 must be from @ref EXTI_Number, @ref Trigger_Cases respectively
******************************************************************************/
button_status_t ECUAL_button_enable_EXTI(uint8_t EXTINumber, void (* callback)(void), uint8_t triggerCase);

#endif /* BUTTON_H_ */