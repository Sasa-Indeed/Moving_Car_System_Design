/*
 * DIO.h
 *
 * Created: 25/08/2023 20:24:14
 *  Author: Ahmed
 */ 
#ifndef DIO_H_
#define DIO_H_

//--------------------------------
//			Includes
//--------------------------------

#include "../../INC/platform_types.h"
#include "../../INC/memory_map.h"

//--------------------------------
//Macros Configuration References
//--------------------------------

typedef struct{
	uint8_t			pinNumber;			/*Specifies the DIO pins to be configured
								this parameter must be a value of @ref DIO_PINS_DEFINE*/
	
	uint8_t			dioDirection;		/*Specifies the operating mode for the selected pins
	 	 	 	 	 	 	   this parameter must be a value of @ref DIO_MODE_DEFINE*/

	uint8_t			portOptionEnable;	/*Specifies the if you want to configure the whole port. Note enabling this
	 	 	 	 	 	 	   will disregard the pinNumber this parameter mus be a value of @ref PORT_OPTION*/
	}pin_config_t;

//@ref DIO_PINS_DEFINE
#define PIN_0					((uint8_t)0x01) // Pin 0 with shifting
#define PIN_1					((uint8_t)0x02) // Pin 1 with shifting
#define PIN_2					((uint8_t)0x04) // Pin 2 with shifting
#define PIN_3					((uint8_t)0x08) // Pin 3 with shifting
#define PIN_4					((uint8_t)0x10) // Pin 4 with shifting
#define PIN_5					((uint8_t)0x20) // Pin 5 with shifting
#define PIN_6					((uint8_t)0x40) // Pin 6 with shifting
#define PIN_7					((uint8_t)0x80) // Pin 7 with shifting

//@ref DIO_MODE_DEFINE
#define INPUT_MODE					0
#define OUTPUT_MODE					1

//@ref PORT_OPTION
#define PORT_OPTION_ENABLE			0
#define PORT_OPTION_DISABLE			1

//Status definition 
typedef enum{
	DIO_OK,
	DIO_INIT_ERROR,
	DIO_PORT_WRITE_ERROR,
	DIO_PIN_WRITE_ERROR,
	DIO_PIN_TOGGLE_ERROR,
	DIO_READ_PIN_ERROR,
	DIO_READ_PORT_ERROR
	}dio_status;

//@ref data_value
#define LOW							0
#define HIGH						1

//------------------------------------------------------------------------------------------
//								APIs supported by "MCAL DIO Driver"
//------------------------------------------------------------------------------------------
/****************************************************************************
* Function Name: MCAL_dio_init
*
* Description : This function initialize the I/O of the microcontroller according
* to the configured data
*
* PARAMETER 1 : The port to which to be configured 
*
* PARAMETER 2 : Structure with the preferred configuration
*
* Return Value: Status about the function
*
* Note		  : In parameter 1 may write 'a' for PortA and like wise for the others ports
******************************************************************************/
dio_status MCAL_dio_init(uint8_t portx, pin_config_t * pinconfig);

/****************************************************************************
* Function Name: MCAL_dio_write_port
*
* Description : This function writes on the whole port according to the input 
*
* PARAMETER 1 : The port to which to be written on
*
* PARAMETER 2 : The data which to be written on the port
*
* Return Value: Status about the function
*
* Note!!!	  : In parameter 2 must be from @ref data_value while,
* parameter 1 can be 'a' for PortA and like wise
******************************************************************************/
dio_status MCAL_dio_write_port(uint8_t portx, uint8_t data);


/****************************************************************************
* Function Name: MCAL_dio_write_pin
*
* Description : This function writes on a specific pin according to the input
*
* PARAMETER 1 : The port on which the pin is located
*
* PARAMETER 2 : The pin to which to be written on
*
* PARAMETER 3 : The data which to be written on the pin
*
* Return Value: Status about the function
*
* Note!!!	  : In parameter 2,3 must be from @ref data_value ,@ref DIO_PINS_DEFINE 
* Respectively while, parameter 1 can be 'a' for PortA and like wise
******************************************************************************/
dio_status MCAL_dio_write_pin(uint8_t portx, uint8_t pin, uint8_t data);


/****************************************************************************
* Function Name: MCAL_dio_toggle_pin
*
* Description : This function toggles a specific pin according to the input
*
* PARAMETER 1 : The port on which the pin is located
*
* PARAMETER 2 : The pin to which to be toggled
*
* Return Value: Status about the function
*
* Note!!!	  : In parameter 2 must be from @ref DIO_PINS_DEFINE while,
* parameter 1 can be 'a' for PortA and like wise
******************************************************************************/
dio_status MCAL_dio_toggle_pin(uint8_t portx, uint8_t pin);


/****************************************************************************
* Function Name: MCAL_dio_read_pin
*
* Description : This function reads data from a specific pin according to the input
*
* PARAMETER 1 : The port on which the pin is located
*
* PARAMETER 2 : The pin to which to be read from
*
* PARAMETER 3 : The data which will be take the value from the pin
*
* Return Value: Status about the function
*
* Note!!!	  : In parameter 2 must be from @ref DIO_PINS_DEFINE while,
* parameter 1 can be 'a' for PortA and like wise
******************************************************************************/
dio_status MCAL_dio_read_pin(uint8_t portx, uint8_t pin, uint8_t* value);


/****************************************************************************
* Function Name: MCAL_dio_read_port
*
* Description : This function reads from whole port according to the input
*
* PARAMETER 1 : The port to which the data will be read from
*
* PARAMETER 2 : The data which will have the value from the port
*
* Return Value: Status about the function
*
* Note!!!	  : Parameter 1 can be 'a' for PortA and like wise
******************************************************************************/
dio_status MCAL_dio_read_port(uint8_t portx, uint8_t* value);


#endif /* DIO_H_ */