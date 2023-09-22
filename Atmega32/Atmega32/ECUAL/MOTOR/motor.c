/*
 * motor.c
 *
 * Created: 18/09/2023 21:50:04
 *  Author: Ahmed
 */ 
#include "motor.h"

void ECUAL_motor_init(void){
	
	pwm_config_t config;
	
	config.pwmNumber = PWM_NUMBER_1;
	
	config.clkSource = TIMER_CLK_SOURCE_INTERNAL;
	
	config.prescaler = TIMER_PRESCALER_8;
	
	MCAL_pwm_init(&config);
	
	
	//Motor Pins Initialization
	pin_config_t pinconfig;
		
		
	pinconfig.dioDirection = OUTPUT_MODE;
	pinconfig.portOptionEnable = PORT_OPTION_ENABLE;
		

	MCAL_dio_init(MOTOR_PORT, &pinconfig);
	
	pinconfig.portOptionEnable = PORT_OPTION_DISABLE;
	
	
	//PWM1
	pinconfig.pinNumber = MOTOR_S1M_PIN;
	MCAL_dio_init(MOTOR_R_L_PORT, &pinconfig);
	
	
	//PWM2
	pinconfig.pinNumber = MOTOR_S2M_PIN;
	MCAL_dio_init(MOTOR_R_L_PORT, &pinconfig);
	
	//Set on idle
	MCAL_dio_write_pin(MOTOR_R_L_PORT, MOTOR_S1M_PIN, HIGH);
	MCAL_dio_write_pin(MOTOR_R_L_PORT, MOTOR_S2M_PIN, HIGH);
}

void ECUAL_motor_move_forward(void){
	//Motor1
	MCAL_dio_write_pin(MOTOR_PORT, PIN_0, HIGH);
	MCAL_dio_write_pin(MOTOR_PORT, PIN_1, LOW);
	
	//Motor2
	MCAL_dio_write_pin(MOTOR_PORT, PIN_2, HIGH);
	MCAL_dio_write_pin(MOTOR_PORT, PIN_3, LOW);
	
	//Motor3
	MCAL_dio_write_pin(MOTOR_PORT, PIN_4, HIGH);
	MCAL_dio_write_pin(MOTOR_PORT, PIN_5, LOW);
	
	//Motor4
	MCAL_dio_write_pin(MOTOR_PORT, PIN_6, HIGH);
	MCAL_dio_write_pin(MOTOR_PORT, PIN_7, LOW);
}

void ECUAL_motor_move_backward(void){
	//Motor1
	MCAL_dio_write_pin(MOTOR_PORT, PIN_0, LOW);
	MCAL_dio_write_pin(MOTOR_PORT, PIN_1, HIGH);
	
	//Motor2
	MCAL_dio_write_pin(MOTOR_PORT, PIN_2, LOW);
	MCAL_dio_write_pin(MOTOR_PORT, PIN_3, HIGH);
	
	//Motor3
	MCAL_dio_write_pin(MOTOR_PORT, PIN_4, LOW);
	MCAL_dio_write_pin(MOTOR_PORT, PIN_5, HIGH);
	
	//Motor4
	MCAL_dio_write_pin(MOTOR_PORT, PIN_6, LOW);
	MCAL_dio_write_pin(MOTOR_PORT, PIN_7, HIGH);
}

void ECUAL_motor_stop(void){
	MCAL_dio_write_pin(MOTOR_R_L_PORT, MOTOR_S1M_PIN, HIGH);
	MCAL_dio_write_pin(MOTOR_R_L_PORT, MOTOR_S2M_PIN, HIGH);
}

void ECUAL_motor_move_all(uint8_t speed){
	MCAL_dio_write_pin(MOTOR_R_L_PORT, MOTOR_S1M_PIN, LOW);
	MCAL_dio_write_pin(MOTOR_R_L_PORT, MOTOR_S2M_PIN, LOW);
	MCAL_pwm_set_duty_cycle(PWM_NUMBER_1, speed);
}


void ECUAL_motor_move_right(uint8_t speed){
	//For 74153 IC 
	MCAL_dio_write_pin(MOTOR_R_L_PORT, MOTOR_S1M_PIN, LOW);
	MCAL_dio_write_pin(MOTOR_R_L_PORT, MOTOR_S2M_PIN, HIGH);
	
	
	MCAL_pwm_set_duty_cycle(PWM_NUMBER_1, speed);
}

void ECUAL_motor_move_left(uint8_t speed){
	//For 74153 IC
	MCAL_dio_write_pin(MOTOR_R_L_PORT, MOTOR_S1M_PIN, HIGH);
	MCAL_dio_write_pin(MOTOR_R_L_PORT, MOTOR_S2M_PIN, LOW);
	
	
	MCAL_pwm_set_duty_cycle(PWM_NUMBER_1, speed);
}
