/*
 * Buttons.c
 *
 * Created: 02.10.2017 15:14:39
 *  Author: martelm
 */
 
#include "buttons.h"


void buttons_init() {
	PORTB = 0x01<<2;
	DDRB = 0x00;
}

boolean buttons_isJoystickButtonPressed() {
	short i = PINB;
	return !(0x1 & (i>>2));
}

boolean buttons_isLeftButtonPressed() {
	short i = PINB;
	return (0x1 & i);
}

boolean buttons_isRightButtonPressed() {
	short i = PINB;
	return (0x1 & (i>>1));
}