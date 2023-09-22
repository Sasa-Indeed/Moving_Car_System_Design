/*
 * timer.c
 *
 * Created: 08/09/2023 21:29:57
 *  Author: Ahmed
 */ 
#include "timer.h"
#include <math.h>
#define Fcpu			1000000   

timer_config_t timers[3];

uint16 get_prescaler(uint8_t index);

timer_status_t MCAL_timer_init(timer_config_t * config){
	switch(config->timerNumber){
		case TIMER_NUMBER_0:{
			
			//Save a copy of the configurations
			timers[0] = *config; 
			
			//Configuring the timer mode
			TCCR0 |= config->mode;
			
			if (config->mode == TIMER_MODE_FAST_PWM_NON_INVERTING || config->mode == TIMER_MODE_FAST_PWM_INVERTING){
				pin_config_t pin;
				
				pin.portOptionEnable = PORT_OPTION_DISABLE;
				
				pin.dioDirection = OUTPUT_MODE;
				
				pin.pinNumber = PIN_3;
				
				MCAL_dio_init('b', &pin);
			}
			
			//Configuring the clock source 
			if (config->clkSource == TIMER_CLK_SOURCE_INTERNAL){
				TCCR0 |= config->prescaler;
			} else{
				TCCR0 |= config->clkSource;
			}
				
			//Configuring the interrupt
			if (config->interruptEnable != TIMER_INTERRUPT_DISABLE){
				if (config->interruptEnable == TIMER_OUTPUT_COMPARE_FLAG_INTERRUPT_ENABLE){
					TIMSK |= (1 << 0);
				} else {
					TIMSK |= (1 << 1);
				}
			}
			
			
			break;
		}
		
		case TIMER_NUMBER_1:{
			//Save a copy of the configurations
			timers[1] = *config;
			
			//Configuring the timer mode
			switch (config->mode){
				case TIMER1_MODE_FAST_PWM_NON_INVERTING_8_BIT :
					//For enabling PWM 8 bit mode 
					TCCR1A |= (1 << 0);
					TCCR1B |= (1 << 3);
					/*For Clearing OC1A on compare match, set
					OC1A at BOTTOM, (non-inverting mode)*/
					TCCR1A |= (2 << 6);
					break;
					
				case TIMER_MODE_NORMAL:
					TCCR1A = 0x00;
					TCCR1B = 0x00;
			}
			
			if (config->mode == TIMER1_MODE_FAST_PWM_NON_INVERTING_8_BIT){
				pin_config_t pin;
				
				pin.portOptionEnable = PORT_OPTION_DISABLE;
				
				pin.dioDirection = OUTPUT_MODE;
				
				pin.pinNumber = PIN_5;
				
				MCAL_dio_init('d', &pin);
			}
			
			//Configuring the clock source
			if (config->clkSource == TIMER_CLK_SOURCE_INTERNAL){
				TCCR1B |= config->prescaler;
				} else{
				TCCR1B |= config->clkSource;
			}
			
			//Configuring the interrupt
			
			break;
		}
		
		case TIMER_NUMBER_2:{
			//Save a copy of the configurations
			timers[2] = *config;
			
			//Configuring the timer mode
			TCCR2 |= config->mode;
			
			if (config->mode == TIMER_MODE_FAST_PWM_NON_INVERTING || config->mode == TIMER_MODE_FAST_PWM_INVERTING){
				pin_config_t pin;
				
				pin.portOptionEnable = PORT_OPTION_DISABLE;
				
				pin.dioDirection = OUTPUT_MODE;
				
				pin.pinNumber = PIN_7;
				
				MCAL_dio_init('d', &pin);
			}
			
			//Configuring the clock source
			if (config->clkSource == TIMER_CLK_SOURCE_INTERNAL){
				TCCR2 |= config->prescaler;
				} else{
				TCCR2 |= config->clkSource;
			}
			
			//Configuring the interrupt
			if (config->interruptEnable != TIMER_INTERRUPT_DISABLE){
				if (config->interruptEnable == TIMER_OUTPUT_COMPARE_FLAG_INTERRUPT_ENABLE){
					TIMSK |= (1 << 7);
					} else {
					TIMSK |= (1 << 6);
				}
			}
			
			break;
		}
			
		
		default:
			return TIMER_INIT_ERROR;
			break;
	}
	
	return TIMER_OK;
}

void MCAL_timer_delay_ms(uint64_t delay){
	
	delay *= FACTOR_MS_TO_US;
	
	uint16 prescaler = get_prescaler(timers[0].prescaler);
	
	uint64_t Tticks = prescaler, Noverflows, overflowCount = 0;
	uint64_t Tmax = Tticks * REGISTER_SIZE;
	
	if (delay < Tmax){
		TCNT0 = (Tmax - delay) / Tticks;
		
		while(!READ_BIT(TIFR,1));//Checking overflow flag
	}else if (delay > Tmax) {
		Noverflows = (uint64_t)ceil((double)delay/Tmax);
		TCNT0 = REGISTER_SIZE - ((delay/Tticks)/Noverflows);
		
		while(overflowCount < Noverflows){
			
			while(!READ_BIT(TIFR,1));//Checking overflow flag
			
			CLEAR_BIT(TIFR,0);//Clear overflow flag

			overflowCount++;
		}
		
	}else{
		TCNT0 = 0x00;
		
		while(!READ_BIT(TIFR,1));//Checking overflow flag
	}
	
	CLEAR_BIT(TIFR,0);//Clear overflow flag
}


uint16 get_prescaler(uint8_t index){
	switch(index){
		case  TIMER_PRESCALER_NONE:
		return 1;
		
		case  TIMER_PRESCALER_8:
		return 8;
		
		case  TIMER_PRESCALER_64:
		return 64;
		
		case  TIMER_PRESCALER_256:
		return 256;
		
		case  TIMER_PRESCALER_1024:
		return 1024;
	}
	
	return 1;
}
