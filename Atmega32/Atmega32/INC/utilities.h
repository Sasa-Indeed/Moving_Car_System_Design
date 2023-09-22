/*
 * Utilities.h
 *
 * Created: 31/08/2023 00:13:17
 *  Author: Ahmed
 */ 


#ifndef UTILITIES_H_
#define UTILITIES_H_

#define CLEAR_BIT(reg,bit)		(reg &= ~(1<<bit))
#define SET_BIT(reg,bit)		(reg |= (1<<bit))
#define TOGGLE_BIT(reg,bit)		(reg ^= (1<<bit))
#define READ_BIT(reg,bit)		((reg>>bit)&1)

#endif /* UTILITIES_H_ */