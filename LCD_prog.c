/*
  * LCD_prog.c
 *
 *  Created on: Aug 22, 2018
 *      Author: Abdulnaser
 */

#include"std_types.h"
#include"util.h"
#include<util/delay.h>
#include"DIO_interface.h"
#include"LCD_interface.h"
#include"LCD_private.h"
#include"LCD_config.h"

/* this function is to make the LCD initialized only*/

void LCD_VidInit (void)
{
	/*Delay 30 MS to ensure the initialization of the LCD driver*/
	_delay_ms(30);
	/*Function set command*/
	LCD_SendCmd(LCD_FUNCSET_8BIT);
	_delay_ms(1);
	/* Display ON OFF control*/
	LCD_SendCmd(LCD_DISPON_CURSBLINK);
	_delay_ms(1);
	/* Return Home  */
	LCD_SendCmd(LCD_HOME);
	_delay_ms(15);
	LCD_SendCmd(LCD_CLR);
	_delay_ms(15);
	/* Entry Mode Set  */
	LCD_SendCmd(LCD_ENTRYMODE);
	_delay_ms(2);
}



void LCD_SendCmd (u8 u8CmdCpy)
{
	/* Reset RS pin */
	    DIO_SetPinValue(CONTROL_PORT, RS_PIN, DIO_u8LOW);
		/* Reset R/W pin*/
		DIO_SetPinValue(CONTROL_PORT, RW_PIN , DIO_u8LOW);
		/* Set E to HIGH  */
		DIO_SetPinValue(CONTROL_PORT, E_PIN, DIO_u8HIGH);
		/*Load command on data bus*/
		DIO_SetPortValue(DATA_PORT, u8CmdCpy);
		DIO_SetPinValue(CONTROL_PORT, E_PIN, DIO_u8LOW);
		_delay_ms(5);
		DIO_SetPinValue(CONTROL_PORT, E_PIN, DIO_u8HIGH);
		/* Delay for 10ms to let the LCD execute command */
		_delay_ms(10);
}


void LCD_VidWriteData (u8 u8DataCpy)
{
	/*RS is high*/
	DIO_SetPinValue(CONTROL_PORT, RS_PIN, DIO_u8HIGH);
	/*RW is low*/
	DIO_SetPinValue(CONTROL_PORT, RW_PIN , DIO_u8LOW);
	/* Set E to HIGH  */
	DIO_SetPinValue(CONTROL_PORT, E_PIN, DIO_u8HIGH);
	/*Load command on data bus*/
	DIO_SetPortValue(DATA_PORT, u8DataCpy);
	DIO_SetPinValue(CONTROL_PORT, E_PIN, DIO_u8LOW);
	_delay_ms(5);
	DIO_SetPinValue(CONTROL_PORT, E_PIN, DIO_u8HIGH);
	/* Delay for 10ms to let the LCD execute command */
	_delay_ms(10);

}


void LCD_VidGoToXY (u8 u8Row,u8 u8Col)
{
	if ((u8Row<=2)&&(u8Col<=16))
	{
		switch (u8Row)
		{
		  case 1:LCD_SendCmd(LCD_u8LINE1+u8Col);break;
		  case 2:LCD_SendCmd(LCD_u8LINE2+u8Col);break;
		}
	}
}


void LCD_VidWriteString(u8 * pu8StringCpy)
{
	u8 iteration=0;
	while(pu8StringCpy[iteration]!='\0')

	{
		LCD_VidWriteData(pu8StringCpy[iteration]);

		iteration++;

		_delay_ms(500);
	}

}


void LCD_vidCustomChar (u8 Y,u8 X)
{
    u8 iteration1,iteration2;

    /*DDRAM-->CGRAM*/
    LCD_SendCmd(64);
	for(iteration1=0 ; iteration1<64 ; iteration1++)
	{
		LCD_VidWriteData(ExtraChar[iteration1]);
	}
	/*CGRAM-->DDRAM*/
	LCD_SendCmd(128);
	 LCD_VidGoToXY(Y,X);
	/*First eight character which saved at CGRAM*/
	for (iteration2=0; iteration2<=7 ; iteration2++)
	{
		/* Write bytes of DDRAM */
		LCD_VidWriteData(iteration2);

		_delay_ms(5);
	}
}











