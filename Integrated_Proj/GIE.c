/**************************************/
/* Description : gie program File      */
/* Author      : Aboelno              */
/* Version     : 0.1V                 */
/* Date        : 13:45:20  03 Dec 2022*/
/* History     : 0.1V Initial Creation*/
/**************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "GIE.h"
#include "GIE_PRIV.h"
void GIE_voidEnable(void)
{
	SET_BIT(SREG,7);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,7);
}
