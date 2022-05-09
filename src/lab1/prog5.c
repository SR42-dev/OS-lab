#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t p1; 
	
	p1 = fork();
	
	if(p1 > 0)
	{
		
		sleep(20);
		printf("Parent process, PID = %d\n", getpid());
	}
	
	else if(p1 == 0)
	{	
		printf("Child process, PID = %d, parent PID = %d\n", getpid(), getppid());
		exit(0); // zombifies child
	}
	
	else printf("FORK FAILED\n");
	
	return 0;
}
