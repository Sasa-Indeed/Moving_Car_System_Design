/*
 * Atmega32.c
 *
 * Created: 25/08/2023 18:56:39
 * Author : Ahmed
 */ 

#include "APPLICATION/application.h"


void pwm_test(uint32_t value);

void motortest(void);

void timer_i(void);

int main(void){
	
	application_car_moving_system_init();

	application_car_moving_system();
		
}

void pwm_test(uint32_t value){
	pwm_config_t config;
	
	config.pwmNumber = PWM_NUMBER_1;
		
	config.clkSource = TIMER_CLK_SOURCE_INTERNAL;
	
	config.prescaler = TIMER_PRESCALER_8;
	
	MCAL_pwm_init(&config);
	
	//config.pwmNumber = PWM_NUMBER_2;
	//MCAL_pwm_init(&config);
	
	MCAL_pwm_set_duty_cycle(PWM_NUMBER_1, value);
	//MCAL_pwm_set_duty_cycle(PWM_NUMBER_2, value);
}


void timer_i(void){
	timer_config_t config;
	
	config.timerNumber = TIMER_NUMBER_0;
	
	config.mode = TIMER_MODE_NORMAL;
	
	config.clkSource = TIMER_CLK_SOURCE_INTERNAL;
	
	config.prescaler = TIMER_PRESCALER_8;
	
	config.interruptEnable = TIMER_INTERRUPT_DISABLE;
	
	MCAL_timer_init(&config);
}


