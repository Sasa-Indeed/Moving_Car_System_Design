/*
 * application.h
 *
 * Created: 26/08/2023 16:06:52
 *  Author: Ahmed
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_


//--------------------------------
//			Includes
//--------------------------------
#include "../ECUAL/LED/led.h"
#include "../ECUAL/BUTTON/button.h"
#include "../ECUAL/MOTOR/motor.h"
#include "../INC/platform_types.h"


typedef enum{
	APPLICATION_OK,
	APPLICATION_INIT_ERROR,
	APPLICATION_SYSTEM_ERROR
	}application_status_t;
	
//------------------------------------------------------------------------------------------
//                              APIs supported by "Application"
//------------------------------------------------------------------------------------------

/****************************************************************************
* Function Name: application_car_moving_system_init
*
* Description : This function initializes the entire system
*
* PARAMETERS  : Nothing
*
* Return Value: Status about the function
*
* Note!!!	  : Nothing
******************************************************************************/
application_status_t application_car_moving_system_init(void);

/****************************************************************************
* Function Name: application_car_moving_system_init
*
* Description : This function make the cars moves as follow:
* 1-The car starts initially from 0 speed
* 2-When PB1  is pressed, the car will move forward after 1 second
* 3-The car will move forward to create the longest side of the rectangle 
* for 3 seconds with 50% of its maximum speed
* 4-After finishing the first longest side the car will stop for 0.5 seconds,
*  rotate 90 degrees to the right, and stop for 0.5 second
* 5-The car will move to create the short side of the rectangle at 30% of 
* its speed for 2 seconds
* 6-After finishing the shortest side, the car will stop for 0.5 seconds, 
* rotate 90 degrees to the right, and stop for 0.5 second
* 7-Steps 3 to 6 will be repeated infinitely until you press the stop button (PB2)
* 8-PB2 acts as a sudden break, and it has the highest priority
*
*
* PARAMETERS  : Nothing
*
* Return Value: Nothing
*
* Note!!!	  : The system must be initialized before calling this function
******************************************************************************/
void application_car_moving_system(void);


#endif /* APPLICATION_H_ */