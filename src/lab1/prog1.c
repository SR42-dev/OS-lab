#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t p1;
	int y = 0;
	
	p1 = fork();
	printf("PID value = %d\n", p1);
	
	if (p1 > 0)
	{
		y -= 1;
		printf("PID value of parent = %d, y = %d\n", getpid(), y);
	}	
	
	else if (p1 == 0)
	{
		y += 1;
		printf("PID value of child = %d, parent PID value = %d, y = %d\n", getpid(), getppid(), y);
	}
	
	else printf("ERROR\n");
	
	return 0;
}
