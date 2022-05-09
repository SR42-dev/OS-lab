#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char* argv[])
{
	int fd = creat(argv[1], RWRWRW);

	if(fd == -1) printf("file creation error.\n");
	for(int i = 0; i < 10; i++) write(fd, "escn", 4);
	close(fd);
	
	if(truncate(argv[1], 50) < 0) printf("read error.\n");
	exit(0);
	
	return 0;	
}
