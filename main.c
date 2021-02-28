/*

 * main.c
 *
 *  Created on: Aug 27, 2018
 *  Author: Abdulnaser
 */
#include"LCD_interface.h"
#include"DIO_interface.h"
#include<util/delay.h>

int main(void)
{

	 DIO_SetPortDirection(DIO_u8PORTD, DIO_u8OUTPUT);
         DIO_SetPortDirection(DIO_u8PORTC, DIO_u8OUTPUT);
	 LCD_VidInit();




    	 LCD_VidWriteString("mo");
    	 _delay_ms(1000);
    	 LCD_SendCmd(LCD_CLR);
         LCD_VidGoToXY(1,8);
    	 LCD_VidWriteString("mo");
    	 _delay_ms(1000);
    	 LCD_SendCmd(LCD_CLR);
    	 LCD_VidGoToXY(2,1);
    	 LCD_VidWriteString("mo");





}
