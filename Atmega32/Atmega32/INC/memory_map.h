/*
 * Memory_map.h
 *
 * Created: 25/08/2023 19:20:14
 *  Author: Ahmed
 */ 


#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

#include "platform_types.h"

//------------------------------------------------------------------------------------------
//									DIO registers
//------------------------------------------------------------------------------------------

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*-
#define DDR_OFFSET					-1
#define PIN_OFFSET					-2




//=========================================================================
//Base Addresses
//-----------------------------

#define PORTA_BASE						(uint8_t)(0x3B)
#define PORTB_BASE						(uint8_t)(0x38)
#define PORTC_BASE						(uint8_t)(0x35)
#define PORTD_BASE						(uint8_t)(0x32)


//=========================================================================
//Peripheral Registers
//-----------------------------


//PORT
#define PORTA						((volatile uint8_t * const)(PORTA_BASE))
#define PORTB						((volatile uint8_t * const)(PORTB_BASE))
#define PORTC						((volatile uint8_t * const)(PORTC_BASE))
#define PORTD						((volatile uint8_t * const)(PORTD_BASE))

//DDR
#define DDRA						((volatile uint8_t * const)(PORTA_BASE + DDR_OFFSET))
#define DDRB						((volatile uint8_t * const)(PORTB_BASE + DDR_OFFSET))
#define DDRC						((volatile uint8_t * const)(PORTC_BASE + DDR_OFFSET))
#define DDRD						((volatile uint8_t * const)(PORTD_BASE + DDR_OFFSET))

//PIN
#define PINA						((volatile uint8_t * const)(PORTA_BASE + PIN_OFFSET))
#define PINB						((volatile uint8_t * const)(PORTB_BASE + PIN_OFFSET))
#define PINC						((volatile uint8_t * const)(PORTC_BASE + PIN_OFFSET))
#define PIND						((volatile uint8_t * const)(PORTD_BASE + PIN_OFFSET))


//------------------------------------------------------------------------------------------
//									EXTI registers
//------------------------------------------------------------------------------------------

#define MCUCR						*((volatile uint8_t *)(0x55))
#define MCUCSR						*((volatile uint8_t *)(0x54))
#define GICR						*((volatile uint8_t *)(0x5B))
#define GIFR						*((volatile uint8_t *)(0x5A))


//------------------------------------------------------------------------------------------
//									Timer registers
//------------------------------------------------------------------------------------------
#define TIMSK						*((volatile uint8_t *)(0x59))
#define TIFR						*((volatile uint8_t *)(0x58))

//Timer0 
#define OCR0						*((volatile uint8_t *)(0x5C))
#define TCCR0						*((volatile uint8_t *)(0x53))
#define TCNT0						*((volatile uint8_t *)(0x52))

//Timer1
#define TCCR1A						*((volatile uint8_t *)(0x4F))
#define TCCR1B						*((volatile uint8_t *)(0x4E))
#define TCNT1H						*((volatile uint8_t *)(0x4D))
#define TCNT1L						*((volatile uint8_t *)(0x4C))
#define OCR1AH						*((volatile uint8_t *)(0x4B))
#define OCR1AL						*((volatile uint8_t *)(0x4A))
#define OCR1BH						*((volatile uint8_t *)(0x49))
#define OCR1BL						*((volatile uint8_t *)(0x48))
#define ICR1H						*((volatile uint8_t *)(0x47))
#define ICR1L						*((volatile uint8_t *)(0x46))


//Timer2
#define TCCR2						*((volatile uint8_t *)(0x45))
#define TCNT2						*((volatile uint8_t *)(0x44))
#define OCR2						*((volatile uint8_t *)(0x43))





#endif /* MEMORY_MAP_H_ */