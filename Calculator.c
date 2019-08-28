/*
 * Calculator.c
 *
 *  Created on: Aug 28, 2019
 *      Author: mahmo
 */
#include "STD_Types.h"
#include "MCAL/DIO.h"
#include "HAL/Keypad.h"
#include "HAL/LCD.h"
#include "util/delay.h"


#define	PLUS_SIGN 	0b00101011
#define EQUAL_SIGN	0b00111101
#define MINUS_SIGN	0b00101101
#define MULT_SIGN	0b00101010
#define DIV_SIGN	0b00101111
#define SUB_SIGN	0b10110000


static u8 Num1 , Num2 ,Result;


static void  Display_Number(u8);
static void  Wait_Clean();
static void  LOC_vidAddition();
static void  LOC_vidMult();
static void  LOC_vidDivition();
static void  LOC_vidSub();

extern void  CALC_vidInit()
{
		LCD_vidInit();
		KEYPAD_vidInit();
		LCD_u8WriteString("Fun");
		LCD_vidWriteChar(' ');
		LCD_u8WriteString("Starts");
		_delay_ms(3000);
		LCD_vidClearScreen();
		LCD_ClearData(1);//Clear data first line
		_delay_ms(1000);
}
extern void  CALC_vidManage()
{
	u8 op;
	LCD_u8WriteString("Enter");
	LCD_vidWriteChar(' ');
	LCD_u8WriteString("Operation");
	LCD_vidWriteChar(0b00111010); //to write :
	/* Reallocate Cursor*/
	LCD_vidSetCursor(2,5);
	_delay_ms(3000);
	do{
		op=KEYPAD_u8GetPressedKey();
	}
	while(op==Key_NONE);
	switch(op){
		case Key_STAR :
			LCD_vidWriteChar(MULT_SIGN);
			LOC_vidMult();
			break;
		case Key_No0 :
			LCD_vidWriteChar(PLUS_SIGN);
			LOC_vidAddition();
			break;
		case Key_HASH :
			LCD_vidWriteChar(SUB_SIGN);
			LOC_vidSub();
			break;
		case Key_D :
			LCD_vidWriteChar(DIV_SIGN);
			LOC_vidDivition();
			break;
		default:
			LCD_u8WriteString("Wrong");
			Wait_Clean();

	}

}

static void  LOC_vidAddition()
{
	Wait_Clean();
	/*Take number1 from Keypad */
	//while(KEYPAD_u8GetPressedKey()==0);
	LCD_u8WriteString("Enter");
	LCD_vidWriteChar(' ');
	LCD_u8WriteString("Numbers");
	LCD_vidWriteChar(0b00111010); //to write :
		/* Reallocate Cursor*/
	LCD_vidSetCursor(2,5);
	_delay_ms(2000);
	do
	{
		Num1=KEYPAD_u8GetPressedKey();
	}while(Num1==Key_NONE);

	Display_Number(Num1);
	LCD_vidWriteChar(PLUS_SIGN);
	_delay_ms(2000);
	/*Take number2 from Keypad */
	//while(KEYPAD_u8GetPressedKey()==0);
	do
	{
		Num2=KEYPAD_u8GetPressedKey();
	}while(Num2==Key_NONE);
	Display_Number(Num2);
	_delay_ms(1000);
	Result=Num1+Num2;
	LCD_vidWriteChar(EQUAL_SIGN);
	Display_Number(Result);
}

static void  LOC_vidSub()
{

	Wait_Clean();
	/*Take number1 from Keypad */
	//while(KEYPAD_u8GetPressedKey()==0);
	LCD_u8WriteString("Enter");
	LCD_vidWriteChar(' ');
	LCD_u8WriteString("Numbers");
	LCD_vidWriteChar(0b00111010); //to write :
	/* Reallocate Cursor*/
	LCD_vidSetCursor(2,5);
	_delay_ms(2000);
	do
	{
		Num1=KEYPAD_u8GetPressedKey();
	}while(Num1==Key_NONE);
	Display_Number(Num1);
	LCD_vidWriteChar(MINUS_SIGN);
	_delay_ms(2000);
	/*Take number2 from Keypad */
	//while(KEYPAD_u8GetPressedKey()==0);
	do
	{
		Num2=KEYPAD_u8GetPressedKey();
	}while(Num2==Key_NONE);
	Display_Number(Num2);
	_delay_ms(1000);
	Result=Num1-Num2;
	LCD_vidWriteChar(EQUAL_SIGN);
	Display_Number(Result);

}

static void  LOC_vidMult()
{
	Wait_Clean();
	/*Take number1 from Keypad */
	//while(KEYPAD_u8GetPressedKey()==0);
	LCD_u8WriteString("Enter");
	LCD_vidWriteChar(' ');
	LCD_u8WriteString("Numbers");
	LCD_vidWriteChar(0b00111010); //to write :
	/* Reallocate Cursor*/
	LCD_vidSetCursor(2,5);
	_delay_ms(2000);
	do
	{
		Num1=KEYPAD_u8GetPressedKey();
	}while(Num1==Key_NONE);
	Display_Number(Num1);
	LCD_vidWriteChar(MULT_SIGN);
	_delay_ms(2000);
	/*Take number2 from Keypad */
	//while(KEYPAD_u8GetPressedKey()==0);
	do
	{
		Num2=KEYPAD_u8GetPressedKey();
	}while(Num2==Key_NONE);
	Display_Number(Num2);
	_delay_ms(1000);
	Result=Num1*Num2;
	LCD_vidWriteChar(EQUAL_SIGN);
	Display_Number(Result);
}
static void  LOC_vidDivition()
{
	Wait_Clean();
	/*Take number1 from Keypad */
	//while(KEYPAD_u8GetPressedKey()==0);
	LCD_u8WriteString("Enter");
	LCD_vidWriteChar(' ');
	LCD_u8WriteString("Numbers");
	LCD_vidWriteChar(0b00111010); //to write :
	/* Reallocate Cursor*/
	LCD_vidSetCursor(2,5);
	_delay_ms(2000);
	do
	{
		Num1=KEYPAD_u8GetPressedKey();
	}while(Num1==Key_NONE);
	Display_Number(Num1);
	LCD_vidWriteChar(DIV_SIGN);
	_delay_ms(2000);
	/*Take number2 from Keypad */
	//while(KEYPAD_u8GetPressedKey()==0);
	do
	{
		Num2=KEYPAD_u8GetPressedKey();
	}while(Num2==Key_NONE);
	Display_Number(Num2);
	_delay_ms(1000);
	Result=Num1/Num2;
	LCD_vidWriteChar(EQUAL_SIGN);
	Display_Number(Result);
}
static void Wait_Clean()
{
	_delay_ms(2000);
	//LCD_vidClearScreen();
	LCD_ClearData(1);
	LCD_ClearData(2);
	LCD_vidClearScreen();

}
static void  Display_Number(u8 Number)
{
	if(Number>=100){
		LCD_vidWriteChar((Number/10/10)+'0');
		LCD_vidWriteChar((Number/10%10)+'0');
		LCD_vidWriteChar((Number%10)+'0');
	}
	else if(Number>=10){
		LCD_vidWriteChar((Number/10)+'0');
		LCD_vidWriteChar((Number%10)+'0');

	}
	else{
		LCD_vidWriteChar(Number+'0');
	}
}

