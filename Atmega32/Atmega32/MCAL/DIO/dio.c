/*
 * DIO.c
 *
 * Created: 25/08/2023 20:24:27
 *  Author: Ahmed
 */ 
#include "dio.h"

vuint8_t * dio_ports [] = {PORTA, PORTB, PORTC, PORTD};
vuint8_t * dio_DDRs [] = {DDRA, DDRB, DDRC, DDRD};
vuint8_t * dio_pins [] = {PINA, PINB, PINC, PIND};
	
uint8_t get_port_index (uint8_t portx)
{
	uint8_t i ;
	switch (portx){
		case 'A':
		case 'a':
		i = 0 ;
		break;
		case 'B' :
		case 'b':
		i = 1 ;
		break;
		case 'C':
		case 'c':
		i = 2 ;
		break;
		case 'D':
		case 'd':
		i = 3 ;
		break;
		default:
		i = 9; //Error
	}
	return i ;

}

dio_status MCAL_dio_init(uint8_t portx, pin_config_t * pinconfig){
	
	uint8_t index = get_port_index(portx);
	
	if (index == 9){
		return DIO_INIT_ERROR;
	} else {
		
		if (pinconfig->portOptionEnable == PORT_OPTION_ENABLE){

			if (pinconfig->dioDirection == OUTPUT_MODE){
				*dio_DDRs[index] |= 0xFF; //Output
			} else{
				*dio_DDRs[index] &= ~0xFF; //Input
			}

		}else{
		
			if (pinconfig->dioDirection == OUTPUT_MODE){
				*dio_DDRs[index] |= pinconfig->pinNumber; //Output
			} else{
				*dio_DDRs[index] &= ~pinconfig->pinNumber; //Input
			}

		}

	}
	
	return DIO_OK;
}

dio_status MCAL_dio_write_port(uint8_t portx,uint8_t data){
	uint8_t index = get_port_index(portx);
		
	if (index == 9){
		return DIO_PORT_WRITE_ERROR;
	} else {
		if (data == HIGH){
			*dio_ports[index] |= 0xFF; //Writing 1 
		} else{
			*dio_ports[index] &= ~0xFF; //Writing 0
		}
	}
		
	return DIO_OK;
}


dio_status MCAL_dio_write_pin(uint8_t portx, uint8_t pin, uint8_t data){
	uint8_t index = get_port_index(portx);
		
	if (index == 9){
		return DIO_PIN_WRITE_ERROR;
	} else {
		if (data == HIGH){
			*dio_ports[index] |= pin; //Writing 1
		} else if (data == LOW){
			*dio_ports[index] &= ~pin; //Writing 0
		}else{
			return DIO_PIN_WRITE_ERROR;
		}
	}
		
	return DIO_OK;
}

dio_status MCAL_dio_toggle_pin(uint8_t portx, uint8_t pin){
	uint8_t index = get_port_index(portx);
			
	if (index == 9){
		return DIO_PIN_TOGGLE_ERROR;
	} else {
		*dio_ports[index] ^= pin; //Writing 1
	}
			
	return DIO_OK;
}

dio_status MCAL_dio_read_pin(uint8_t portx, uint8_t pin, uint8_t* value){
	uint8_t index = get_port_index(portx);
		
	if (index == 9){
		return DIO_READ_PIN_ERROR;
	} else {
		 *value = ((*dio_pins[index] & pin) != LOW) ? HIGH : LOW; //Writing data
	}
		
	return DIO_OK;
}


dio_status MCAL_dio_read_port(uint8_t portx, uint8_t* value){
	uint8_t index = get_port_index(portx);
			
	if (index == 9){
		return DIO_READ_PIN_ERROR;
	} else {
		*value = *dio_pins[index]; //Writing data
	}
			
	return DIO_OK;
}