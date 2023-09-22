/*
 * external_interrupt.c
 *
 * Created: 31/08/2023 13:29:58
 *  Author: Ahmed
 */ 

#include "external_interrupt.h"

void (* GP_IRQ_callback[3])(void);

EXTI_status	MCAL_EXTI_init(exti_config_t* config){
	pin_config_t pinConfig;
	
	INTERRUPT_ENABLE;
	
	pinConfig.dioDirection == INPUT_MODE;
	pinConfig.portOptionEnable == PORT_OPTION_DISABLE;
	
	switch (config->extiNumber){
		
		case EXTI0:{
			MCUCR |= (config->triggerCase << 2);
			
			pinConfig.pinNumber = PIN_2;
			
			MCAL_dio_init('d', &pinConfig);
			
			GP_IRQ_callback[0] = config->P_IRQ_callback;
			
			if (config->extiEnable == EXTI_ENABLE){
				SET_BIT(GICR,6);
				} else if (config->extiEnable == EXTI_DISABLE){
				CLEAR_BIT(GICR,6);
			}
			
			break;
		}
		
		case EXTI1:{
			MCUCR |= (config->triggerCase);
			
			pinConfig.pinNumber = PIN_3;
			
			MCAL_dio_init('d',&pinConfig);
			
			GP_IRQ_callback[1] = config->P_IRQ_callback;
			
			if (config->extiEnable == EXTI_ENABLE){
				SET_BIT(GICR,7);
				} else if (config->extiEnable == EXTI_DISABLE){
				CLEAR_BIT(GICR,7);
			}
			
			break;
		}
		
		case EXTI2:{
			MCUCSR |= (config->triggerCase << 6);

			pinConfig.pinNumber = PIN_2;
			
			MCAL_dio_init('b',&pinConfig);

			GP_IRQ_callback[2] = config->P_IRQ_callback;
			
			if (config->extiEnable == EXTI_ENABLE){
				SET_BIT(GICR,6);
				} else if (config->extiEnable == EXTI_DISABLE){
				CLEAR_BIT(GICR,6);
			}
			
			break;
		}
		
		default:
		return EXTI_INIT_ERROR;
		
	}
	
	
	return EXTI_OK;
}


ISR(EXT_INT_0){
	GP_IRQ_callback[0]();
}

ISR(EXT_INT_1){
	GP_IRQ_callback[1]();
}

ISR(EXT_INT_2){
	GP_IRQ_callback[2]();
}