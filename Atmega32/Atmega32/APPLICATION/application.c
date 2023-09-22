/*
 * application.c
 *
 * Created: 26/08/2023 16:07:02
 *  Author: Ahmed
 */ 

//--------------------------------
//			Includes
//--------------------------------
#include "application.h"

//--------------------------------
//		Global Variables
//--------------------------------
uint32_t g_buttonPresses = 0;
uint8_t g_buttonData = 0;

//--------------------------------
//		Helper Functions
//--------------------------------
void emergency_stop(void);

//--------------------------------
//	 APIs Implementations
//--------------------------------
application_status_t application_car_moving_system_init(void){
	timer_config_t config;
	
	config.timerNumber = TIMER_NUMBER_0;
	
	config.mode = TIMER_MODE_NORMAL;
	
	config.clkSource = TIMER_CLK_SOURCE_INTERNAL;
	
	config.prescaler = TIMER_PRESCALER_8;
	
	config.interruptEnable = TIMER_INTERRUPT_DISABLE;
	
	MCAL_timer_init(&config);

	ECUAL_motor_init();
	
	ECUAL_motor_move_forward();
	
	ECUAL_led_init(LED_PORTC, PIN_0);
	ECUAL_led_init(LED_PORTC, PIN_1);
	ECUAL_led_init(LED_PORTC, PIN_2);
	ECUAL_led_init(LED_PORTC, PIN_3);
	
	ECUAL_button_init(BUTTON_PORTD, PIN_0);
	ECUAL_button_init(BUTTON_PORTD, PIN_2);
	
	ECUAL_button_enable_EXTI(EXTI0, emergency_stop, TRIGGER_CASE_RISING_EDGE);
	
	return APPLICATION_OK;
}


void application_car_moving_system(void){
	
	while(1){
		
		ECUAL_button_read(BUTTON_PORTD, PIN_0, &g_buttonData);
		
		if (g_buttonPresses == 0 && g_buttonData){
			ECUAL_led_off(LED_PORTC, PIN_2, HIGH);
			MCAL_timer_delay_ms(1000);
			g_buttonPresses++;
		}
		
		if (g_buttonPresses || g_buttonData){
			if (g_buttonData == 0 && g_buttonPresses == 0){continue;}
			//Step 3
			ECUAL_motor_move_all(50);
			ECUAL_led_on(LED_PORTC, PIN_0, HIGH);
			MCAL_timer_delay_ms(3000);
			ECUAL_led_off(LED_PORTC, PIN_0, HIGH);
			
			if (g_buttonData == 0 && g_buttonPresses == 0){continue;}
			//Step 4
			//Stop
			ECUAL_motor_stop();
			ECUAL_led_on(LED_PORTC, PIN_2, HIGH);
			MCAL_timer_delay_ms(500);
			ECUAL_led_off(LED_PORTC, PIN_2, HIGH);
			
			if (g_buttonData == 0 && g_buttonPresses == 0){continue;}
			//Rotating
			ECUAL_led_on(LED_PORTC, PIN_3, HIGH);
			ECUAL_motor_move_right(80);
			MCAL_timer_delay_ms(300);
			ECUAL_led_off(LED_PORTC, PIN_3, HIGH);
			
			if (g_buttonData == 0 && g_buttonPresses == 0){continue;}
			//Stop
			ECUAL_led_on(LED_PORTC, PIN_2, HIGH);
			ECUAL_motor_stop();
			MCAL_timer_delay_ms(500);
			ECUAL_led_off(LED_PORTC, PIN_2, HIGH);
			
			if (g_buttonData == 0 && g_buttonPresses == 0){continue;}
			//Step 5
			ECUAL_motor_move_all(30);
			ECUAL_led_on(LED_PORTC, PIN_1, HIGH);
			MCAL_timer_delay_ms(2000);
			ECUAL_led_off(LED_PORTC, PIN_1, HIGH);
			
			if (g_buttonData == 0 && g_buttonPresses == 0){continue;}
			//Step 6
			//Stop
			ECUAL_motor_stop();
			ECUAL_led_on(LED_PORTC, PIN_2, HIGH);
			MCAL_timer_delay_ms(500);
			ECUAL_led_off(LED_PORTC, PIN_2, HIGH);
			
			if (g_buttonData == 0 && g_buttonPresses == 0){continue;}
			//Rotating
			ECUAL_led_on(LED_PORTC, PIN_3, HIGH);
			ECUAL_motor_move_right(80);
			MCAL_timer_delay_ms(300);
			ECUAL_led_off(LED_PORTC, PIN_3, HIGH);
			
			if (g_buttonData == 0 && g_buttonPresses == 0){continue;}
			//Stop
			ECUAL_led_on(LED_PORTC, PIN_2, HIGH);
			ECUAL_motor_stop();
			MCAL_timer_delay_ms(500);
			ECUAL_led_off(LED_PORTC, PIN_2, HIGH);
		}
		
		if (g_buttonData == 0 && g_buttonPresses == 0){
			ECUAL_led_on(LED_PORTC, PIN_2, HIGH);
			ECUAL_motor_stop();
		}

	}
}

void emergency_stop(void){
	ECUAL_motor_stop();
	g_buttonData = 0;
	g_buttonPresses = 0;
}


