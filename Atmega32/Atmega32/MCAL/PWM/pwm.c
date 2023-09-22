/*
 * pwm.c
 *
 * Created: 19/09/2023 20:55:52
 *  Author: Ahmed
 */ 
#include "pwm.h"
#include <math.h>


//--------------------------------
//		Generic Macros
//--------------------------------
#define MAX_DUTY_VALUE	100
#define MAX_PERCENTAGE	100
#define MIN_PERCENTAGE	0


//--------------------------------
//		Global Variables
//--------------------------------
pin_config_t pin = {.portOptionEnable = PORT_OPTION_DISABLE, .dioDirection = OUTPUT_MODE};
uint32_t g_counter[3] = {0, 0, 0};
uint32_t g_duty_value[3] = {0, 0, 0};
pwm_config_t g_pwm[3];
	



pwm_status_t MCAL_pwm_init(pwm_config_t * config){
		
		switch(config->pwmNumber){
		case PWM_NUMBER_0:{
			//Save a copy of configuration
			g_pwm[0] = *config;
			
			//Configuring OC0
			pin.pinNumber = PIN_3;
				
			MCAL_dio_init(PWM0_PORT, &pin);
			
			//Configuring the clock source 
			if (config->clkSource == TIMER_CLK_SOURCE_INTERNAL){
				TCCR0 |= config->prescaler;
			} else{
				TCCR0 |= config->clkSource;
			}
			
			break;
		}
		
		case PWM_NUMBER_1:{
			//Save a copy of configuration
			g_pwm[1] = *config;
			
			
			pin.pinNumber = PIN_5;
				
			MCAL_dio_init(PWM1_PORT, &pin);
			
			pin.pinNumber = PIN_4;
			
			MCAL_dio_init(PWM1_PORT, &pin);
			
			TCNT1H = 0xFF;
			TCNT1L = 0x00;
			
			//Configuring the clock source
			if (config->clkSource == TIMER_CLK_SOURCE_INTERNAL){
				TCCR1B |= config->prescaler;
				} else{
				TCCR1B |= config->clkSource;
			}
			
			break;
		}
		
		case PWM_NUMBER_2:{
			//Save a copy of configuration
			g_pwm[2] = *config;
			
			//Configuring OC2
			pin.pinNumber = PIN_7;
			
			MCAL_dio_init(PWM2_PORT, &pin);
			
			//Configuring the clock source
			if (config->clkSource == TIMER_CLK_SOURCE_INTERNAL){
				TCCR2 |= config->prescaler;
				} else{
				TCCR2 |= config->clkSource;
			}
			
			break;
		}
			
		
		default:
			return PWM_INIT_ERROR;
			break;
	}
	
	sei();
	
	return PWM_OK;
}


void MCAL_pwm_set_duty_cycle(uint8_t pwmX, uint32_t value){
	
	if (value > MAX_PERCENTAGE || value < MIN_PERCENTAGE){
		value = 0;
	}
	
	value = (uint32_t)ceil((double)(MAX_DUTY_VALUE * ((double)((double)value/100))));
	value = MAX_DUTY_VALUE - value;
	
	switch(pwmX){
		case PWM_NUMBER_0:
			g_duty_value[0] = value;
			//Configuring the Interrupt
			TIMSK |= (1 << 0);
			CLEAR_BIT(TIFR, 0);
			break;
		
		case PWM_NUMBER_1:
			g_duty_value[1] = value;
			//Configuring the Interrupt
			TIMSK |= (1 << 2);
			
			CLEAR_BIT(TIFR,2);
			break;
			
		case PWM_NUMBER_2:
			g_duty_value[2] = value;
			//Configuring the Interrupt
			TIMSK |= (1 << 6);
			
			CLEAR_BIT(TIFR, 6);
			
			break;
			
		default:
		break;
	}
	
	
		
}


ISR(TIMER0_OVF_vect){
	//TCNT0 = -16;
	
	g_counter[0] += 1;
	
	if (g_duty_value[0] == MAX_DUTY_VALUE){
		MCAL_dio_write_pin(PWM0_PORT, PIN_3, LOW);
	} else if (g_counter[0] >= g_duty_value[0]){
		MCAL_dio_write_pin(PWM0_PORT, PIN_3, HIGH);
		
		if (g_counter[0] == MAX_DUTY_VALUE){
			g_counter[0] = 0;
		}
		
	}else{
		MCAL_dio_write_pin(PWM0_PORT, PIN_3, LOW);
	}
	
	CLEAR_BIT(TIFR, 0);
	
}

ISR(TIMER1_OVF_vect){
	TCNT1H = 0xFF;
	TCNT1L = 0x00;
	
	g_counter[1] += 1;
	
	if (g_duty_value[1] == MAX_DUTY_VALUE){
		MCAL_dio_write_pin(PWM1_PORT, PIN_5, LOW);
		MCAL_dio_write_pin(PWM1_PORT, PIN_4, LOW);
		} else if (g_counter[1] >= g_duty_value[1]){
		MCAL_dio_write_pin(PWM1_PORT, PIN_5, HIGH);
		MCAL_dio_write_pin(PWM1_PORT, PIN_4, HIGH);
		
		if (g_counter[1] == MAX_DUTY_VALUE){
			g_counter[1] = 0;
		}
		
		}else{
		MCAL_dio_write_pin(PWM1_PORT, PIN_5, LOW);
		MCAL_dio_write_pin(PWM1_PORT, PIN_4, LOW);
	}
	
	CLEAR_BIT(TIFR, 2);
	
}

ISR(TIMER2_OVF_vect){
	TCNT2 = -16;
	
	g_counter[2] += 1;
	
	if (g_duty_value[2] == MAX_DUTY_VALUE){
		MCAL_dio_write_pin(PWM2_PORT, PIN_7, LOW);
	} else if (g_counter[2] >= g_duty_value[2]){
		MCAL_dio_write_pin(PWM2_PORT, PIN_7, HIGH);
		
		if (g_counter[2] == MAX_DUTY_VALUE){
			g_counter[2] = 0;
		}
		
	}else{
		MCAL_dio_write_pin(PWM2_PORT, PIN_7, LOW);
	}
	
	CLEAR_BIT(TIFR, 6);
	
}