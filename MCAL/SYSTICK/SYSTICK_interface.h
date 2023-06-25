/**************************************************/
/* Author  : Mustafa Mohammed Abdou               */
/* Date    : 24 Jun , 2023                        */
/* Version : V01                                  */
/* Hint    : Interface file of SYSTICK            */
/**************************************************/

#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

/** TYPEDEFINITION FOR SYSTICK RETURN ERROR STATUS **/
typedef enum { SYSTICK_FAILURE = 0 , SYSTICK_SUCCEED } en_systic_error_status_t ;

/** MACROS TO CONFIGURE SYSTIC INTERRUPT **/
#define SYSTICK_ENABLE_INT      0
#define SYSTICK_DISABLE_INT     1

/** MACROS TO CONFIGURE THE SYSTIC CLOCK SOURCE **/
#define SYSTIC_INTERNAL_CLK     0
#define SYSTIC_DIVIDE_FCPU      1


/**********************************************************************
@brief      : function to set systick configuration    
@parameters : delay period in milliseconds     
@return     : en_systic_error_status_t
***********************************************************************/
en_systic_error_status_t SYSTIC_init(void);


/**********************************************************************
@brief      : function to enable systick to start counting down   
@parameters : delay period in milliseconds     
@return     : void
***********************************************************************/
void SYSTIC_start_delay_ms(uint32_t u32_a_delay_ms);


#endif

