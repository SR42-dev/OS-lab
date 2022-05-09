#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define MAX 10
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
	
	printf("Input message : ");
	read(0, msg.msg_text, BUFFER_SIZE);
	printf("Sent message : %s\n", msg.msg_text);
	
	key = ftok("progfile", 65);
	
	msgid = msgget(key, 0666|IPC_CREAT);
	msg.msg_type = 1;
	
	msgsnd(msgid, &msg, sizeof(msg), 0);
	sleep(5);
	
	return 0;
}
	
