#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t p1;
	
	p1 = fork();
	
	if (p1 > 0) 
	{
		printf("PID value of parent = %d\n", getpid());
		sleep(5);
	}
	
	else if (p1 == 0) 
	{
		printf("PID value of child = %d, parent PID value = %d\n", getpid(), getppid());
		system("ls -l");
	}
	
	else printf("FORK ERROR\n");
	
	return 0;
}
