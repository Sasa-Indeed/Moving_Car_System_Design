/*
 * pwm.h
 *
 * Created: 19/09/2023 20:56:04
 *  Author: Ahmed
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "../../INC/platform_types.h"
#include "../../INC/memory_map.h"
#include "../../INC/utilities.h"
#include "../DIO/dio.h"
#include "avr/interrupt.h"



typedef struct{
	uint8_t				pwmNumber; /*Specifics which timer to program this parameter
									must be a value of @ref Timer_Number*/
	
	uint8_t				clkSource; /*Specifics the clock source of the timer whether
								it is internal or external source this parameter must be
								 a value of @ref clkSource*/
	
	uint8_t				prescaler; /*Specifics the prescaler value of which the timer
								will work on this parameter must be a value of @ref prescaler*/
		
	}pwm_config_t;
	

typedef enum{
	PWM_OK,
	PWM_INIT_ERROR
	}pwm_status_t;


//@ref PWM_Number
#define PWM_NUMBER_0											0
#define PWM_NUMBER_1											1
#define PWM_NUMBER_2											2

//@ref clkSource
#define TIMER_CLK_SOURCE_NONE									0
#define TIMER_CLK_SOURCE_INTERNAL								1
#define TIMER_CLK_SOURCE_EXTERNAL_ON_T0_PIN_FALLING_EDGE		6
#define TIMER_CLK_SOURCE_EXTERNAL_ON_T0_PIN_RISING_EDGE			7


//@ref prescaler
#define TIMER_PRESCALER_NONE									1
#define TIMER_PRESCALER_8										2
#define TIMER_PRESCALER_64										3
#define TIMER_PRESCALER_256										4
#define TIMER_PRESCALER_1024									5

//@ref PWM Ports
#define PWM0_PORT												'b'
#define PWM1_PORT												'd'
#define PWM2_PORT												'd'

//------------------------------------------------------------------------------------------
//								APIs supported by "MCAL PWM Driver"
//------------------------------------------------------------------------------------------
/****************************************************************************
* Function Name: MCAL_pwm_init
*
* Description : This function initializes a Timer to work as like pwm mode 
* using normal mode
*
* PARAMETER 1 : The timer which will be initialized
*
* Return Value: Status about the function
*
* Note		  : Nothing
******************************************************************************/
pwm_status_t MCAL_pwm_init(pwm_config_t * config);


/****************************************************************************
* Function Name: MCAL_pwm_set_duty_cycle
*
* Description : Sets duty cycle for the PWM using normal mode
*
* PARAMETER 1 : The timer which will be used. It must be set from @ref PWM_Number
*
* Return Value: Nothing
*
* Note!!!	  : Must initialize the timer using MCAL_pwm_init function
******************************************************************************/
void MCAL_pwm_set_duty_cycle(uint8_t pwmX, uint32_t value);




#endif /* PWM_H_ */