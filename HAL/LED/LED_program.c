/**************************************************/
/* Author  : Mustafa Mohammed Abdou               */
/* Date    : 4 April , 2023                       */
/* Version : V01                                  */
/* Hint    : program file of led                  */
/**************************************************/

/** INCLUDE LIBRARIES **/
#include "../../SERVICE/common_macros.h"
#include "../../SERVICE/standard_types.h"

/** INCLUDE INTERFACE FILES OF LOWER LAYERS **/
#include "../../MCAL/GPIO/GPIO_interface.h"

/** INCLUDE DRIVER FILES **/
#include "LED_interface.h"
#include "LED_config.h"



/***************************************************/
/** FUNCTION TO INITIALIZE A PIN                  **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : enu_led_error_status_t              **/
/***************************************************/
enu_led_error_status_t LED_init(uint8_t u8_a_ledport , uint8_t u8_a_ledpin)
{
	enu_GPIO_error_status_t enu_l_ledpin_status  = GPIO_SUCCEED ;   /** LOCAL VARIABLE TO STORE THE RETURN ERROR STATUS OF LED GPIO PIN **/
	
	enu_led_error_status_t enu_l_ledinit_status = LED_SUCCEED ;  /** LOCAL VARIABLE TO RETURN THE FUNCTION ERROR STATUS **/ 
	
	enu_l_ledpin_status = GPIO_setpindir(u8_a_ledport , u8_a_ledpin , GPIO_PIN_OUTPUT);  /** SET THE LED PIN AS OUTPUT **/
	
	GPIO_enableportclk(u8_a_ledport );              /** ENABLE CLK TO PORT **/
	
	GPIO_enabledigital(u8_a_ledport , u8_a_ledpin); /** ENABLE DIGITALFUNCTIONALITY **/
	
	if ( enu_l_ledpin_status == GPIO_SUCCEED )
	{
		/** DO NOTHING **/
	}
	
	else
	{
		enu_l_ledinit_status = LED_FAILURE ; /** RETUTN FAILURE **/
	}
	
	return enu_l_ledinit_status ;
}




/***************************************************/
/** FUNCTION TO SET A LED AS ON                   **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : enu_led_error_status_t              =**/
/***************************************************/
enu_led_error_status_t LED_on(uint8_t u8_a_ledport , uint8_t u8_a_ledpin)
{
	enu_GPIO_error_status_t enu_l_ledpin_status  = GPIO_SUCCEED ;    /** LOCAL VARIABLE TO STORE THE RETURN ERROR STATUS OF LED GPIO PIN **/
	
	enu_led_error_status_t enu_l_ledon_status   = LED_SUCCEED ;    /** LOCAL VARIABLE TO RETURN THE FUNCTION ERROR STATUS **/
	
	enu_l_ledpin_status = GPIO_setpinvalue(u8_a_ledport , u8_a_ledpin , GPIO_PIN_HIGH); /** SET THE OUTPUT PIN AS HIGH **/
	
	if ( enu_l_ledpin_status == GPIO_SUCCEED )
	{
		/** DO NOTHING **/
	}
	
	else
	{
		enu_l_ledon_status  = LED_FAILURE ;  /** RETURN FAILURE **/
	}
	
	return enu_l_ledon_status ;  /** RETURN THE FUNCTION FINAL STATUS **/
}



/***************************************************/
/** FUNCTION TO SET A LED AS OFF                  **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : enu_led_error_status_t              **/
/***************************************************/
enu_led_error_status_t LED_off(uint8_t u8_a_ledport , uint8_t u8_a_ledpin)
{
	enu_GPIO_error_status_t enu_l_ledpin_status  = GPIO_SUCCEED ;    /** LOCAL VARIABLE TO STORE THE RETURN ERROR STATUS OF LED GPIO PIN **/
	
	enu_led_error_status_t enu_l_ledoff_status   = LED_SUCCEED ;    /** LOCAL VARIABLE TO RETURN THE FUNCTION ERROR STATUS **/
	
	enu_l_ledpin_status = GPIO_setpinvalue(u8_a_ledport , u8_a_ledpin , GPIO_PIN_LOW); /** SET THE OUTPUT PIN AS LOW **/
	
	if ( enu_l_ledpin_status == GPIO_SUCCEED )
	{
		/** DO NOTHING **/
	}
	
	else
	{
		enu_l_ledoff_status = LED_FAILURE ; /** RETURN FAILURE **/
	}
	
	return enu_l_ledoff_status ;  /** RETURN THE FUNCTION FINAL STATUS **/
}


/** PATTERNS TO BE DISPLAYED */
void LED_pattern1(void)
{
	/** LED1 ON **/
	LED_on(REDLED_PORT , REDLED_PIN);
	LED_off(GREENLED_PORT , GREENLED_PIN);
	LED_off(BLUELED_PORT , BLUELED_PIN);
}

void LED_pattern2(void)
{
	/** LED2 ARE ON **/
	LED_off(REDLED_PORT , REDLED_PIN);
	LED_on(GREENLED_PORT , GREENLED_PIN);
	LED_off(BLUELED_PORT , BLUELED_PIN);

}

void LED_pattern3(void)
{
	/** LED3 ARE ON **/
	LED_off(REDLED_PORT , REDLED_PIN);
	LED_off(GREENLED_PORT , GREENLED_PIN);
	LED_on(BLUELED_PORT , BLUELED_PIN);
}

void LED_pattern4(void)
{
	/**
	GPIO_setpinsvalue(GPIO_PORTF , 0x0E , 0x0E);
	
	 LED 1 , LED 2 , LED 3 AND LED 4 ARE ON  **/
	
	LED_on(REDLED_PORT , REDLED_PIN);
	LED_on(GREENLED_PORT , GREENLED_PIN);
	LED_on(BLUELED_PORT , BLUELED_PIN);
	
}

void LED_pattern5(void)
{
	/** LED 4 IS OFF **/
	LED_off(REDLED_PORT , REDLED_PIN);
	LED_off(GREENLED_PORT , GREENLED_PIN);
	LED_off(BLUELED_PORT , BLUELED_PIN);
}

