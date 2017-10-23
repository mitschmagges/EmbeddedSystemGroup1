/*
 * TDT4200Group1.c
 *
 * Created: 02.10.2017 13:17:16
 *  Author: hubi
 */ 

#define FOSC 4915200 // clock speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#include "main.h"
#include "MCP/mcp.h"
#include "./CAN/can_buffer.h"
void XMEM_Init() {
	MCUCR |= (1<<SRE);
	SFIOR |= (1<<XMM2);
}

void init() {
	usart_init( MYUBRR );
	XMEM_Init();
	calibrateJoystick();
	DDRB &= ~0b0011;
	oled_init();
	oled_reset();
	fdevopen(oled_putchar, usart_getchar);
	oled_reset();
	buttons_init();
	can_init();
}

int main(void) {
	init();
	
	while(1) {
//		dummyPrint();
		//mcp_write(0x10, "HELLO\n",7);
		//printf_char("before: ");
		//printf_char(temp);
		//printf_char("\n");
		//temp[0] = 'F';
		//printf_char("between: ");
		//printf_char( temp);
		//printf_char(("\n"));
		//mcp_read(0x10, temp,7);
		//printf_char("after: ");
		//printf_char( temp);
		//printf_char(("\n"));
		//
		//mcp_requestToSend(TXB2);
		//char status = mcp_readStatus();
		//printf_char("status: ");
		//printf_int(status);
		//printf_char(("\n"));
		//mcp_reset();
		//status = mcp_readStatus();
		//printf_char("status: ");
		//printf_int(status);
		//printf_char(("\n"));
		//struct can_message msg;
		//msg.id = 3;
		//msg.length = 1;
		//msg.data[0] = (uint8_t)'A' + ++i%26;
		//
		//
		//can_send_message(&msg);
		//printf_char(msg.data);
		//mcp_read(0x00, msg.data, msg.length);
		
		//send a can massage:
		
		
		
		printf_char("Beginning of main loop\n");
		
		
		
		
		char stri[5] = {1,2,3,4,5};
		
		struct can_message msg = can_create_massage(42, 5, stri);

		can_send_message(&msg);
		struct can_message myName;		
		//printf_char("HELLO\n");

		char status = mcp_readStatus();
		//struct can_message recv = can_recieve_message(TXB0);
		
		
	
		//can_print_message(&recv);


	}
}