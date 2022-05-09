#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int main() 
{
	int fd1;
	char buff[BUFFER_SIZE] = "hello world";
	
	char myfifo[BUFFER_SIZE] = "/temp/myfifo";
	
	printf("Input message : ");
	read(0, buff, BUFFER_SIZE);
	
	mkfifo(myfifo, 0666); // creates file at path myfifo with permission code 0666 ()
	
	fd1 = open(myfifo, O_WRONLY);
	write(fd1, buff, strlen(buff) + 1);
	close(fd1);
	
	sleep(20);
	
	return 0;
}
	
