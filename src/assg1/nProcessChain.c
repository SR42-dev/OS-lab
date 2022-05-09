#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int n = 7; // number of child processes
	
	for(int i = 0; i < n; i++) 
	{
		if(fork() == 0)
		{	
			printf("PID value of child %d = %d, parent PID value = %d\n", (i + 1), getpid(), getppid()); // child code 
			exit(0);
		}
		
		else
		{
			sleep(1);
	    		printf("PID value of parent = %d \n", getpid()); // parent code
		}
	}
			
    	return 0;
}




