/*
 * menu.c
 *
 * Created: 02.10.2017 14:17:48
 *  Author: hubi
 */ 

#include "menu.h"

void menu_mainMenu(){
	//PRINT THE MENU
	oled_reset();
	printf("         MAIN MENU          \n");
	const int menuLength = 3;
	char* options[3] = {"ONE   ", "TWO   ", "THREE   "};
	static int pointer = 0;
	static enum DIRECTION last = NEUTRAL;
	
	for(int i = 0; i < menuLength; ++i){
		if(i== pointer){
			oled_set_printmode(INVERSE);
			printf("    ");
			
			printf(options[i]);
			oled_set_printmode(NORMAL);
		}
		else{
			printf("    ");
			printf(options[i]);
		}
		printf("\n");
	}
	
	enum DIRECTION direction = getJoystickDirection();
	
	switch (direction){
		case UP:
			if( last == NEUTRAL){
				if( pointer> 0){
					--pointer;
				}
				else pointer = menuLength-1;
			}
			break;
		case DOWN:
			if( last == NEUTRAL){
				if ( pointer < menuLength-1){
					++ pointer;
				}
				else{
					pointer =0;
				}
			}
			break;
		case LEFT:
			break;
		case RIGHT:
			break;
		case NEUTRAL:
			break;
	}
	last = direction;
}