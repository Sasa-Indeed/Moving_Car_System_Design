/*
 * motor.h
 *
 * Created: 18/09/2023 21:49:53
 *  Author: Ahmed
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

//------------------------------------------------------------------------------------------
//										 Includes
//------------------------------------------------------------------------------------------

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/TIMER/timer.h"
#include "../../MCAL/PWM/pwm.h"

//------------------------------------------------------------------------------------------
//										 General Macros
//------------------------------------------------------------------------------------------

#define MOTOR_PORT						'a'
#define MOTOR_R_L_PORT					'b'
#define MOTOR_S1M_PIN					PIN_6
#define MOTOR_S2M_PIN					PIN_7

//------------------------------------------------------------------------------------------
//                              APIs supported by "ECUAL Motor Driver"
//------------------------------------------------------------------------------------------

/****************************************************************************
* Function Name: ECUAL_motor_init
*
* Description : This function initializes the motors 
*
* PARAMETERS  : Nothing
*
* Return Value: Nothing
*
* Note!!!	  : Nothing
******************************************************************************/
void ECUAL_motor_init(void);

/****************************************************************************
* Function Name: ECUAL_motor_move_forward
*
* Description : This function sets the motors to move forward 
*
* PARAMETERS  : Nothing
*
* Return Value: Nothing
*
* Note!!!	  : Motor must be initialized
******************************************************************************/
void ECUAL_motor_move_forward(void);

/****************************************************************************
* Function Name: ECUAL_motor_move_backward
*
* Description : This function sets the motors to move backward
*
* PARAMETERS  : Nothing
*
* Return Value: Nothing
*
* Note!!!	  : Motor must be initialized
******************************************************************************/
void ECUAL_motor_move_backward(void);

/****************************************************************************
* Function Name: ECUAL_motor_stop
*
* Description : This function sets the motors to stop moving move 
*
* PARAMETERS  : Nothing
*
* Return Value: Nothing
*
* Note!!!	  : Motor must be initialized
******************************************************************************/
void ECUAL_motor_stop(void);

/****************************************************************************
* Function Name: ECUAL_motor_move_all
*
* Description : This function makes the motors move according how they were
*configured
*
* PARAMETER1  : The percentage of the speed a value between 0% and 100% 
*
* Return Value: Nothing
*
* Note!!!	  : Must configure how to move first by using ECUAL_motor_move_backward 
* of ECUAL_motor_move_forward functions
******************************************************************************/
void ECUAL_motor_move_all(uint8_t speed);

/****************************************************************************
* Function Name: ECUAL_motor_move_right
*
* Description : This function makes the motors move to the right
*
* PARAMETER1  : The percentage of the speed a value between 0% and 100%
*
* Return Value: Nothing
*
* Note!!!	  : Must configure how to move first by using ECUAL_motor_move_backward
* of ECUAL_motor_move_forward functions
******************************************************************************/
void ECUAL_motor_move_right(uint8_t speed);

/****************************************************************************
* Function Name: ECUAL_motor_move_left
*
* Description : This function makes the motors move to the left
*
* PARAMETER1  : The percentage of the speed a value between 0% and 100%
*
* Return Value: Nothing
*
* Note!!!	  : Must configure how to move first by using ECUAL_motor_move_backward
* of ECUAL_motor_move_forward functions
******************************************************************************/
void ECUAL_motor_move_left(uint8_t speed);




#endif /* MOTOR_H_ */