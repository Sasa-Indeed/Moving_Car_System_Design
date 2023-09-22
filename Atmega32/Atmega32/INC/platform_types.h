/*
 * Platform_types.h
 *
 * Created: 25/08/2023 19:30:08
 *  Author: Ahmed
 */ 


#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

//Types
typedef unsigned char			boolean;
typedef signed char				sint8_t;
typedef unsigned char			uint8_t;
typedef signed short			sint16_t;
typedef unsigned short			uint16;
typedef signed long				sint32_t;
typedef unsigned long			uint32_t;
typedef signed long long		sint64_t;
typedef unsigned long long		uint64_t;
typedef float					float32_t;
typedef double 					float64_t;

//Volatiles
typedef volatile sint8_t		vint8_t;
typedef volatile uint8_t		vuint8_t;
typedef volatile sint16_t		vint16_t;
typedef volatile uint16		vuint16_t;
typedef volatile sint32_t		vint32_t;
typedef volatile uint32_t		vuint32_t;
typedef volatile sint64_t		vint64_t;
typedef volatile uint64_t		vuint64_t;
typedef volatile float32_t		vfloat32_t;
typedef volatile float64_t		vfloat64_t;




#endif /* PLATFORM_TYPES_H_ */