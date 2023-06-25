/**********************************************************/
/* Author  : Mustafa Mohammed Abdou                       */
/* Date    : 24 Jun , 2023                                */
/* Version : V01                                          */
/* Hint    : implementation of application layer APIs     */
/**********************************************************/

/** INCLUDE LIBRARIES **/
#include "../SERVICE/common_macros.h"
#include "../SERVICE/standard_types.h"

/** INTERFACE FILES OF LOWER LAYERS **/
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/SYSTICK/SYSTICK_interface.h"

#include "../HAL/BTN/button_interface.h"
#include "../HAL/BTN/button_config.h"

#include "../HAL/LED/LED_interface.h"
#include "../HAL/LED/LED_config.h"

/** INCLUDE LAYER FILES **/
#include "APP.h"


/** VARIABLE TO HOLD BUTTON STATUS , COUNTER FOR PRESSING TIMES **/
static uint8_t u8_gl_button1_status  , u8_gl_button1_counter  ;


/** LEDs INITIALIZATION FUNCTION **/
enu_app_error_status_t LEDs_init(void)
{
	enu_led_error_status_t enu_ledstatus      = LED_SUCCEED    ;    /** LOCAL VARIABLE TO RETURN LEDs FUNCTION ERROR STATUS **/
	enu_app_error_status_t enu_ledinit_status = APP_SUCCEED    ;    /** LOCAL VARIABLE TO RETURN THE FUNCTION STATUS        **/
	
	
	enu_ledstatus = LED_init(REDLED_PORT , REDLED_PIN);           /** LED 1  INITIALIZATION **/
	
	if ( enu_ledstatus == LED_SUCCEED )  /** LED1 INIT SUCCEEDED  **/
	{
		enu_ledstatus = LED_init(GREENLED_PORT , GREENLED_PIN);       /** LED 2  INITIALIZATION **/
		
		if ( enu_ledstatus == LED_SUCCEED )  /** LED2 INIT SUCCEEDED  **/
		{
			enu_ledstatus = LED_init(BLUELED_PORT , BLUELED_PIN);   /** LED 3 INITIALIZATION **/
			
			if ( enu_ledstatus == LED_SUCCEED )  /** LED3 INIT SUCCEEDED  **/
			{
				/** do nothing **/
			}
			
			else   /** LED3 INIT FAILED **/
			{
				enu_ledinit_status = APP_FAILURE ; /** RETURN APP FAILURE **/
			}
			
		}
		
		else   /** LED2 INIT FAILED **/
		{
			enu_ledinit_status = APP_FAILURE ; /** RETURN APP FAILURE **/
		}
	}
	
	else   /** LED1 INIT FAILED **/
	{
		enu_ledinit_status = APP_FAILURE ; /** RETURN APP FAILURE **/
	}
	
	return enu_ledinit_status ;  /** RETURN THE FINAL STATUS **/
	
}




/** BUTTONS INITIALIZATION FUNCTION **/
enu_app_error_status_t BTNs_init(void)
{
	enu_button_error_status_t enu_btnstatus   = BUTTON_SUCCEED ;    /** LOCAL VARIABLE TO RETURN LEDs FUNCTION ERROR STATUS **/
	enu_app_error_status_t enu_btninit_status = APP_SUCCEED    ;    /** LOCAL VARIABLE TO RETURN THE FUNCTION STATUS        **/
	
	/** BUTTON INITIALIZATION **/
	enu_btnstatus = BTN_init(BUTTON1_PORT , BUTTON1_PIN);
	
	if ( enu_btnstatus == BUTTON_SUCCEED) /** BUTTON INITIALIZATION SUCCEEDED **/
	{
		/** DO NOTHING **/
	}
	
	else  /** BUTTON INITIALIZATION FAILED **/
	{
		enu_btninit_status = APP_FAILURE ; /** RETURN FAILURE **/
	}
	
	return enu_btninit_status ; /** RETURN THE FINAL STATUS **/
}






/** FUNCTION TO SET ALL LEDs OFF **/
enu_app_error_status_t LEDs_off(void)
{
	enu_led_error_status_t enu_led_state    = LED_SUCCEED ;  /** LOCAL VARIABLE TO RETURN LED FUNCTION STATUS **/ 
	enu_app_error_status_t enu_ledoff_state = APP_SUCCEED ;  /** LOCAL VARIABLE TO RETURN THE FUNCTION STATUS **/
	
	
	enu_led_state = LED_off(REDLED_PORT , REDLED_PIN);
	
	if( enu_led_state == LED_SUCCEED )
	{
		enu_led_state = LED_off(GREENLED_PORT , GREENLED_PIN);
		
		if ( enu_led_state == LED_SUCCEED )
		{
			enu_led_state = LED_off(BLUELED_PORT , BLUELED_PIN);
			
			if ( enu_led_state == LED_SUCCEED )
			{
				/** do nothing **/
			}
			
			else  /** LED 3 FAILED **/
			{
				enu_ledoff_state = APP_FAILURE ;/** RETURN APP FAILURE **/
			}
		}
		
		else  /** LED 2 FAILED **/
		{
			enu_ledoff_state = APP_FAILURE ;/** RETURN APP FAILURE **/
		}
	}
	
	else /** LED 1 FAILED **/
	{
		enu_ledoff_state = APP_FAILURE ;/** RETURN APP FAILURE **/
	}
	
	
	return enu_ledoff_state ; /** RETURN THE FINAL STATUS **/
}




/** INITIALIZATION FUNCTION **/
enu_app_error_status_t APP_init(void)
{ 
	enu_app_error_status_t enu_l_appinit_status = APP_SUCCEED    ;    /** LOCAL VARIABLE TO RETURN THE FUNCTION ERROR STATUS  **/
	
	/** INITIALIZE THE GLOBAL VARIABLES TO ZERO **/
	u8_gl_button1_status = 0  ;  
	u8_gl_button1_counter = 0 ;
	
	enu_l_appinit_status = LEDs_init();  /** INITIALIZE LEDS **/
	
	if ( enu_l_appinit_status == APP_SUCCEED )
	{
		enu_l_appinit_status = BTNs_init(); /** INITIALIZE BUTTONS **/
		
		if ( enu_l_appinit_status == APP_SUCCEED ) /** BUTTONS INITIALIZED SUCCESSFULLY **/
		{
		
			enu_l_appinit_status = LEDs_off();  /** INITIALIZE LEDS TO BE OFF **/
			
			if ( enu_l_appinit_status == APP_SUCCEED )
			{
				/** DO NOTHING **/
			}
			
			else /** LEDs_off FAILED **/
			{
				enu_l_appinit_status = APP_FAILURE ; /** RETURN FAILURE **/
			}
		}
		
		else  /** BTNs_init FAILED **/
		{
			enu_l_appinit_status = APP_FAILURE ; /** RETURN FAILURE **/
		}
	}
	
	else  /** LEDs_init FAILED **/
	{
		enu_l_appinit_status = APP_FAILURE ; /** RETURN FAILURE **/
	}
	
	return enu_l_appinit_status ; /** RETURN THE FINAL STATUS **/
}

/** MAIN LOGIC **/
void APP_start(void)
{
	
	BTN_ispressed(BUTTON1_PORT , BUTTON1_PIN , &u8_gl_button1_status);  /** GET THE STATUS OF THE BUTTON **/

	if (u8_gl_button1_status == BUTTON_PRESSED)    /** IF BUTTON IS PRESSED **/
	{
		BTN_ispressed(BUTTON1_PORT , BUTTON1_PIN , &u8_gl_button1_status); /** GET THE STATUS OF THE BUTTON AGAIN **/
		
		if (u8_gl_button1_status == BUTTON_PRESSED)   /** IF STATE IS STILL 1 **/
		{
			u8_gl_button1_counter++ ;      /** UPDATE BUTTON 1 COUNTER **/
			
			/** DISPLAY THE PATTERN ACCORDING TO THE NUMBER OF PRESS TIMES (COUNTER) */
			if (u8_gl_button1_counter == PATTERN_1)
			{
				LED_pattern1();
			}
			
			else if(u8_gl_button1_counter == PATTERN_2)
			{
				LED_pattern2();
			}
			
			else if(u8_gl_button1_counter == PATTERN_3)
			{
				LED_pattern3();
			}
			
			else if(u8_gl_button1_counter == PATTERN_4)
			{
				LED_pattern4();
			}
			
			else if(u8_gl_button1_counter == PATTERN_5)
			{
				LED_pattern5();
				
				u8_gl_button1_counter = 0 ; /** REINITIALIZE THE COUNTER TO START FROM PATTERN 1 AGAIN */
			}
			
			
			while(u8_gl_button1_status)
			{
				BTN_ispressed(BUTTON1_PORT , BUTTON1_PIN , &u8_gl_button1_status);
			}
			
		}
		
	}
	 
}

