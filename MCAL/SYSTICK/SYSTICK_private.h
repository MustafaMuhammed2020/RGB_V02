/**************************************************/
/* Author  : Mustafa Mohammed Abdou               */
/* Date    : 24 Jun , 2023                        */
/* Version : V01                                  */
/* Hint    : private file of SYSTICK              */
/**************************************************/

#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

/** SYSTICK REGISTERS DEFINITION **/

#define SYSTIC_base  0xE000E000


#define STCTRL       (*((volatile uint32_t *)(0xE000E010)))
#define STRELOAD     (*((volatile uint32_t *)(0xE000E014)))
#define STCURRENT    (*((volatile uint32_t *)(0xE000E018)))

#endif

