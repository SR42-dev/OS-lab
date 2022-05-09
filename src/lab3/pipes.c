#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main() 
{
	char write_msg[BUFFER_SIZE] = "pipe demo";
	char read_msg[BUFFER_SIZE] = "";
	int fd[2];
	pid_t pid;
	
	if (pipe(fd) == -1)
	{
		printf("pipe failure\n");
		return 1;
	}
	
	pid = fork();
	
	if (pid > 0) // parent process
	{
		close(fd[READ_END]);
		write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
		close(fd[WRITE_END]);
		wait(NULL);
	}
	
	else if (pid == 0) // child process
	{
		close(fd[WRITE_END]);
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		printf("child process reads : %s\n", read_msg);
		close(fd[READ_END]);
	}
	
	else 
	{
		printf("fork failure\n");
		return 1;
	}
	
	return 0;
}
	
