/*
 * Interrupt.h
 *
 * Created: 30/08/2023 18:13:01
 *  Author: Ahmed
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

//For Enabling Interrupts
#define INTERRUPT_ENABLE	__asm__ __volatile__ ("sei" ::: "memory")

//For Disabling Interrupts
#define INTERRUPT_DISABLE	__asm__ __volatile__ ("cli" ::: "memory")

//External Interrupt Request 0
#define EXT_INT_0	__vector_1

//External Interrupt Request 1
#define EXT_INT_1	__vector_2
	
//External Interrupt Request 2	
#define EXT_INT_2	__vector_3

//Timer/Counter0 Compare Match Interrupt Request 
#define TMR0_COMP	__vector_10

//Timer/Counter0 Overflow Interrupt Request
#define TMR0_OVF	__vector_11

//Timer/Counter2 Compare Match Interrupt Request
#define TMR2_COMP	__vector_4

//Timer/Counter0 Overflow Interrupt Request
#define TMR2_OVF	__vector_5

//Macro Defines ISR
#define ISR(INT_VECT)void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)


#endif /* INTERRUPT_H_ */