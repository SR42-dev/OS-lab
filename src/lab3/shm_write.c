#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
	void *shared_memory;
	char buff[100] = "";
	int shmid = 0;
	
	shmid = shmget((key_t)2345, 1024, 0666|IPC_CREAT);
	printf("shared memory key : %d\n", shmid);
	
	shared_memory = shmat(shmid, NULL, 0);
	printf("process attached at : %p\n", shared_memory);
	
	printf("input data to be entered to shared memory : ");
	read(0, buff, 100);
	
	strcpy(shared_memory, buff);
	sleep(10);
	
	return 0;
}

