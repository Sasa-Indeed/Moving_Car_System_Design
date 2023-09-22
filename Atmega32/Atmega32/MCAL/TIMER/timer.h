/*
 * timer.h
 *
 * Created: 08/09/2023 21:30:19
 *  Author: Ahmed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../INC/platform_types.h"
#include "../../INC/memory_map.h"
#include "../../INC/interrupt.h"
#include "../../INC/utilities.h"
#include "../DIO/dio.h"



typedef struct{
	uint8_t				timerNumber; /*Specifics which timer to program this parameter
									must be a value of @ref Timer_Number*/
	
	uint8_t				mode; /*Specifics the mode of which the timer will work on
								this parameter must be a value of @ref Timer_Mode*/
	
	uint8_t				clkSource; /*Specifics the clock source of the timer whether
								it is internal or external source this parameter must be
								 a value of @ref clkSource*/
	
	uint8_t				prescaler; /*Specifics the prescaler value of which the timer
								will work on this parameter must be a value of @ref prescaler*/
	
	uint8_t				interruptEnable; /*Specifics whether to enable or disable the interrupt
								this parameter must be a value of @ref interruptEnable*/
	
	void (* P_IRQ_callback)(void);  /*Set the C Function() which will be called once interrupt happens*/
	
	}timer_config_t;
	

typedef enum{
	TIMER_OK,
	TIMER_INIT_ERROR,
	}timer_status_t;


#define REGISTER_SIZE											256
#define FACTOR_MS_TO_US											1000

//@ref Timer_Number
#define TIMER_NUMBER_0											0
#define TIMER_NUMBER_1											1
#define TIMER_NUMBER_2											2

//@ref Timer_Mode
#define TIMER_MODE_NORMAL										((uint8_t)(0 << 3))
#define TIMER_MODE_PWM_PHASE_CORRECT							((uint8_t)(1 << 3))
#define TIMER_MODE_CTC											((uint8_t)(0x8))
#define TIMER_MODE_FAST_PWM_NON_INVERTING						((uint8_t)(0x68))
#define TIMER_MODE_FAST_PWM_INVERTING							((uint8_t)(0x78))
//For Timer1 ONLY!!!
#define TIMER1_MODE_FAST_PWM_NON_INVERTING_8_BIT				((uint8_t)(0x15))

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


//@ref interruptEnable
#define TIMER_INTERRUPT_DISABLE									0
#define TIMER_OUTPUT_COMPARE_FLAG_INTERRUPT_ENABLE				1
#define TIMER_OVERFLOW_FLAG_INTERRUPT_ENABLE					2

//------------------------------------------------------------------------------------------
//								APIs supported by "MCAL Timer Driver"
//------------------------------------------------------------------------------------------

/****************************************************************************
* Function Name: MCAL_timer_init
*
* Description : This function initializes a Timer to the preferred mode
*
* PARAMETER 1 : The timer which will be initialized
*
* Return Value: Status about the function 
*
* Note!!!	  : Nothing
******************************************************************************/
timer_status_t MCAL_timer_init(timer_config_t * config);

/****************************************************************************
* Function Name: MCAL_timer_delay_ms
*
* Description : This function creates a delay according to the input
*
* PARAMETER 1 : The delay you want but in milliseconds 
*
* Return Value: Nothing
*
* Note!!!	  : This function requires timer0 to work and timer0 in normal mode
******************************************************************************/
void MCAL_timer_delay_ms(uint64_t delay);


#endif /* TIMER_H_ */