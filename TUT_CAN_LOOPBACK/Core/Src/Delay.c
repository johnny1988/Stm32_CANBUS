/*******************************************************************************
* Title                 :   System Initialization
* Filename              :   Delay.c
* Author                :   JWB
* Origin Date           :   04/23/2012
* Version               :   1.0.0
* Compiler              :   Microchip C30 v3.30c
* Target                :   PIC24FJ64GB004
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Software Version    Initials   Description 
*  XX/XX/XX    XXXXXXXXXXX         JWB      Module Created.
*
*******************************************************************************/
/** \file XXX.c
 * \brief This module contains the 
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include <Delay.h>					// For portable types

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/
/**
 *Doxygen tag for documenting variables and constants
 */
#define   CONSTANT					5

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
uint32_t Gtime_us = 0;

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
/******************************************************************************
* Function : Pwm_Init()
*//** 
* \section Description Description:
*
*  This function is used to 
*
* \param  		None.
*
* \return 		None.
*
* \section Example Example:
* \code
*    Pwm_Init();
* \endcode
*
* \see Pwm_Enable
*
*  ----------------------
*  - HISTORY OF CHANGES -
*  ----------------------
*    Date    Software Version    Initials   Description 
*  XX/XX/XX    XXXXXXXXXXX         JWB      Function Created.
*
*******************************************************************************/

void delayInit ()
{
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/1000000);  /* 16Mhz */
}

void delay_us(uint32_t timer_us)
{
	Gtime_us = timer_us;
	while(Gtime_us);
}
void delay_ms(uint32_t timer_ms)
{
	while(timer_ms--)
		delay_us(timer_ms);
}

void SysTick_Handlr()
{
	if(Gtime_us)
		Gtime_us--;
}
/*************** END OF FUNCTIONS ***************************************************************************/
