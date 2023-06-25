/**************************************************/
/* Author  : Mustafa Mohammed Abdou               */
/* Date    : 24 Jun , 2023                        */
/* Version : V01                                  */
/* Hint    : implementation of SYSTICK APIs       */
/**************************************************/

/** INCLUDE LIBRARIES **/
#include "../../SERVICE/standard_types.h"
#include "../../SERVICE/common_macros.h"

/** INCLUDE DRIVER FILES **/
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"


/**********************************************************************
@brief      : function to set systick configuration    
@parameters : delay period in milliseconds     
@return     : en_systic_error_status_t
***********************************************************************/
en_systic_error_status_t SYSTIC_init(void)
{
	en_systic_error_status_t en_l_systicinitstatus = SYSTICK_SUCCEED ; /** local variable to hold the function status **/
	
	#if    SYSTIC_INT_STATUS == SYSTICK_ENABLE_INT
					set_bit(STCTRL , 1);
	
	#elif  SYSTIC_INT_STATUS == SYSTICK_DISABLE_INT 
					clear_bit(STCTRL , 1);
	#else
				en_l_systicinitstatus = SYSTICK_FAILURE ; /** return failure **/	
	#endif
	
	
	#if     SYSTIC_CLK_SOURCE   == SYSTIC_INTERNAL_CLK
						set_bit(STCTRL , 1);
	
	#elif   SYSTIC_CLK_SOURCE   == SYSTIC_DIVIDE_FCPU
						clear_bit(STCTRL , 1);
	#else 
					en_l_systicinitstatus = SYSTICK_FAILURE ; /** return failure **/	
	#endif
	
	return en_l_systicinitstatus ; /** return the final status **/	
	
}


/**********************************************************************
@brief      : function to enable systick to start counting down   
@parameters : delay period in milliseconds     
@return     : void
***********************************************************************/
void SYSTIC_start_delay_ms(uint32_t u32_a_delay_ms)
{
	
	STRELOAD = u32_a_delay_ms * 16000 ; /** evaluate the number of ticks needed for delay **/
	
	set_bit(STCTRL , 0); /** enable counter **/
	
	while( ((STCTRL >> 16) && 0x01) != 1 ); /** time counted **/
	
	/** stop systic **/
	STRELOAD   = 0 ;
  STCURRENT  = 0 ;
  clear_bit(STCTRL , 0); /** disable counter **/
	
}
