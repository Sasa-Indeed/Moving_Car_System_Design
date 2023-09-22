/*
 * external_interrupt.h
 *
 * Created: 31/08/2023 13:27:46
 *  Author: Ahmed
 */ 


#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_

//--------------------------------
//			Includes
//--------------------------------

#include "../../INC/platform_types.h"
#include "../../INC/memory_map.h"
#include "../../INC/utilities.h"
#include "../../MCAL/DIO/dio.h"
#include "../../INC/Interrupt.h"

//--------------------------------
//Macros Configuration References
//--------------------------------

typedef enum{
	EXTI_OK,
	EXTI_INIT_ERROR
	}EXTI_status;

typedef struct{
	uint8_t			extiEnable; /*Specifics whether to enable or disable the interrupt
								this parameter must be a value of @ref EXTI_Enable*/
	
	uint8_t			extiNumber; /*Specifies Which external interrupt to enable
								this parameter must be a value of @ref EXTI_Number */
	
	uint8_t			triggerCase; /*Specifies the mode at which the interrupt will be trigged 
								this parameter must be a value of @ref Trigger_Cases*/
	
	void (* P_IRQ_callback)(void);  /*Set the C Function() which will be called once interrupt happens*/
		
	}exti_config_t;

//@ref EXTI_Enable
#define EXTI_DISABLE							0
#define EXTI_ENABLE								1


//@ref EXTI_Number
#define EXTI0									0
#define EXTI1									1
#define EXTI2									2


//@ref Trigger_Cases
/*
0 0 The low level generates an interrupt request.
0 1 Any logical change generates an interrupt request.
1 0 The falling edge generates an interrupt request.
1 1 The rising edge generates an interrupt request.
*/
//This for INT0 & INT1 ONLY!!!
#define TRIGGER_CASE_LOW_LEVEL					0
#define TRIGGER_CASE_ANY_CHANGE					1
#define TRIGGER_CASE_FALLING_EDGE				2
#define TRIGGER_CASE_RISING_EDGE				3

//This for INT2 ONLY!!!
#define TRIGGER_INT2_CASE_FALLING_EDGE			0
#define TRIGGER_INT2_CASE_RISING_EDGE			1



//------------------------------------------------------------------------------------------
//								APIs supported by "MCAL EXTI Driver"
//------------------------------------------------------------------------------------------

/****************************************************************************
* Function Name: MCAL_EXTI_init
*
* Description : This function configures how the external interrupt will work
*
* PARAMETER 1 : Structure with the preferred configuration 
*
* Return Value: Status about the function
*
* Note!!!	  : Nothing
******************************************************************************/
EXTI_status	MCAL_EXTI_init(exti_config_t* config);



#endif /* EXTERNAL_INTERRUPT_H_ */ 