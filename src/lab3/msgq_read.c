#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define BUFFER_SIZE 100

typedef struct msg_buffer
{
	long msg_type;
	char msg_text[BUFFER_SIZE];
}msg;

int main() 
{
	key_t key;
	msg msg;
	int msgid;
	
	key = ftok("progfile", 65); // generates and returns a unique key
	msgid = msgget(key, 0666 | IPC_CREAT); // creates a message queue and returns it's identifier
	msgrcv(msgid, &msg, sizeof(msg), 1, 0); // receives previously gotten message into the structure created earlier
	
	printf("message received : %s\n", msg.msg_text);
	msgctl(msgid, IPC_RMID, NULL);
	
	return 0;
}
	
