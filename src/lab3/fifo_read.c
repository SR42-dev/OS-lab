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
	
	mkfifo(myfifo, 0666); // creates file at path myfifo with permission code 0666 ()
	
	fd1 = open(myfifo, O_RDONLY);
	read(fd1, buff, BUFFER_SIZE);
	
	printf("Information read : %s\n", buff);
	close(fd1);
	
	return 0;
}
	
