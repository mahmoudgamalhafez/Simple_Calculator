/*
 * App.c
 *
 *  Created on: Aug 23, 2019
 *      Author: elProf
 */
#include "STD_Types.h"
#include "macros.h"
#include "MCAL/DIO.h"
#include "HAL/LCD.h"
#include "util/delay.h"
#include "HAL/Keypad.h"
#include "Calculator.h"




/*	Calculator  */
int main()
{
	CALC_vidInit();

	while(1)
	{
		CALC_vidManage();
		_delay_ms(4000);
	//	LCD_vidClearScreen();
		LCD_ClearData(1);
		LCD_ClearData(2);
		LCD_vidClearScreen();
	}
}







