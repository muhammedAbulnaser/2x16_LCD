/*
 * LCD_private.h
 *
 *  Created on: Aug 22, 2018
 *  Author: Abdulnaser
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define LCD_u8LINE1		0x80
#define LCD_u8LINE2		0xc0

const u8  ExtraChar[]=
{
		0x00, 0x00, 0x17, 0x15, 0x1F, 0x00, 0x00, 0x00, //Char0
		0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x0C, 0x18, //Char1
		0x04, 0x0A, 0x00, 0x15, 0x1F, 0x00, 0x00, 0x00, //Char2
		0x06, 0x0E, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, //Char3
		0x00, 0x00, 0x0E, 0x0A, 0x0E, 0x02, 0x04, 0x08, //Char4
		0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x0C, 0x18, //Char5
		0x00, 0x00, 0x04, 0x0A, 0x1B, 0x0A, 0x04, 0x00, //Char6
		0x00, 0x00, 0x07, 0x04, 0x1F, 0x00, 0x00, 0x00, //Char7
};


#endif /* LCD_PRIVATE_H_ */
