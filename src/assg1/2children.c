#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t child_a;
	pid_t child_b;

	child_a = fork();

	if (child_a == 0) printf("PID value of child A = %d, parent PID value = %d \n", getpid(), getppid()); // child A code
	
	else 
	{
	    child_b = fork();

	    if (child_b == 0) printf("PID value of child B = %d, parent PID value = %d\n", getpid(), getppid()); // child B code
	    else 
	    {
	    	sleep(5);
	    	printf("PID value of parent = %d \n", getpid()); // parent code
	    }
	}
	
    	return 0;
}


