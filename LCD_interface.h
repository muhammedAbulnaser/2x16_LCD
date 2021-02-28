/*
 * LCD_interface.h
 *
 *  Created on: Aug 22, 2018
 *  Author: Abdulnaser
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include "std_types.h"
/**********************************************************************
                       public definitions
 *********************************************************************/
/*Comment!: LCD control commands*/

#define LCD_CLR           		0x01          // replace all characters with ASCII 'space'                       */
#define LCD_HOME          		0x02          // return cursor to first position on first line                   */
#define LCD_ENTRYMODE     		0x06          // shift cursor from left to right on read/write
#define LCD_DISPOFF       		0x08          // turn display off
#define LCD_DISPON_CURSON 		0x0E          // display on, cursor off, don't blink character
#define LCD_FUNCRESET     		0x30          // reset the LCD
#define LCD_FUNCSET_8BIT  		0x38          // 8-bit data, 2-line display, 5 x 7 font
#define LCD_SETCURSOR     		0x80          // set cursor position
#define LCD_DISPON_CURSBLINK	0x0F          //display on , cursor blinking
#define LCD_DISPON_CURSOFF		0x0C          //display on ,cursor off
/*********************************************************************
                       public functions
 ********************************************************************/
void LCD_VidInit (void);
void LCD_SendCmd (u8 u8CmdCpy);
void LCD_VidWriteData (u8 u8DataCpy);
void LCD_VidGoToXY (u8 u8Row,u8 u8Col);
void LCD_VidWriteString(u8 * pu8stringCpy);
void LCD_vidCustomChar (u8 Y,u8 X);






#endif /* LCD_INTERFACE_H_ */
