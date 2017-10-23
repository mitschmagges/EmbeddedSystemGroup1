/*
 * can.h
 *
 * Created: 09.10.2017 14:08:20
 *  Author: martelm
 */ 

#include "..\main.h"
#include "..\MCP\mcp.h"


#ifndef CAN_H_
#define CAN_H_

#define CAN_REGISTER_ADDRESS_MODESELECT 0xF0
#define CAN_MODE_LOOPBACK 0x40
#define CAN_MODE_OPERATIONAL 0x00
#define CAN_MASK_MODE 0xE0
#define MAX_MESSAGE_LENGTH 8

struct can_message {
	unsigned int id;
	char length;
	char data[MAX_MESSAGE_LENGTH];
};

void can_init();
void can_setMode(char mode);
struct can_message can_create_massage(int id, char length, char data[]);
void can_send_message(struct can_message* msg);
struct can_message can_recieve_message(enum RECIEVE_BUFFER tcb);
void can_print_message(struct can_message* msg);
void can_assignMessage(struct can_message* copy_onto, const struct can_message* copy_from); // Copies from right to left

#endif /* CAN_H_ */