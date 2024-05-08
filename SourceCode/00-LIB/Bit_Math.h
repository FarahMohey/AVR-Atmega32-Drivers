/*
 ============================================================================
 Name        : BIT_MATH.h
 Author      : Farah Mohey
 Description : Header file for BITMATH
 Created	 : 29-Nov-23		1:16:47 PM
 ============================================================================
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*Set BIT in REG*/
#define SET_BIT(REG,BIT)	(REG |= (1<<BIT))

/*Clear BIT in REG*/
#define CLR_BIT(REG,BIT)	(REG &= ~(1<<BIT))

/*Toggle BIT in REG*/
#define TGL_BIT(REG,BIT)	(REG ^= (1<<BIT))

/*Get BIT in REG*/
#define GET_BIT(REG,BIT)	(REG & (1<<BIT))

/*

// Set high nibble in REG
#define SET_HIGH_NIB(REG)
// Clear high nibble in REG
#define CLR_HIGH_NIB(REG)
// Get high nibble in REG
#define GET_HIGH_NIB(REG)
// Toggle high nibble in REG
#define TGL_HIGH_NIB(REG)
// Set low nibble in REG
#define SET_LOW_NIB(REG)
// Clear low nibble in REG
#define CLR_LOW_NIB(REG)
// Get low nibble in REG
#define GET_LOW_NIB(REG)
// Toggle low nibble in REG
#define TGL_LOW_NIB(REG)
*/

/*Assign VALUE to REG */
#define ASSIGN_REG(REG,VALUE)	(REG = VALUE)
/*
// Assign VALUE to high nibble REG
#define ASSIGN_HIGH_NIB(REG,VALUE)
// Assign VALUE to low nibble REG
#define ASSIGN_LOW_NIB(REG,VALUE)
// Right shift by NO in REG
#define RSHFT_REG(REG, NO)
// Left shift by NO in REG
#define LSHFT_REG(REG, NO)
// Circular right shift by NO in REG
#define CRSHFT_REG(REG, NO)
// Circular left shift by NO in REG
#define CLSHFT_REG(REG,NO)

*/

#endif /* BIT_MATH_H_ */