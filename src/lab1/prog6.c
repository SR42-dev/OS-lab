#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t p1, p2;
	int y = 0; 
	
	p1 = fork();
	
	if(p1 > 0)
	{
		
		wait(NULL);
		y -= 1;
		printf("Parent process, PID = %d, y = %d\n", getpid(), y);
	}
	
	else if(p1 == 0)
	{	
		p2 = fork();
		
		if (p2 > 0)
		{
			wait(NULL);
			printf("Child process, PID = %d, parent PID = %d, y = %d\n", getpid(), getppid(), y);
		}
		
		else if (p2 == 0)
		{
			y += 5;
			printf("Grandchild process, PID = %d, grandchild parent PID = %d, y = %d\n", getpid(), getppid(), y);
		}	
		
		else printf("FORK FAILED\n");
		
		y += 1;
		printf("Child process, PID = %d, parent PID = %d, y = %d\n", getpid(), getppid(), y);
		
	}
	
	else printf("FORK FAILED\n");
	
	return 0;
}
