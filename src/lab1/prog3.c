#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t p1; 
	int y = 0;
	
	p1 = fork();
	
	if(p1 > 0)
	{
		wait(NULL); // if wait is removed, parent executes first (usually, parent waits until child completes execution)
		y -= 1;
		printf("Parent process, PID = %d, y = %d\n", getpid(), y);
	}
	
	else if(p1 == 0)
	{
		y += 1;
		printf("Child process, PID = %d, parent PID = %d, y = %d\n", getpid(), getppid(), y);
	}
	
	else printf("FORK FAILED\n");
	
	return 0;
}
