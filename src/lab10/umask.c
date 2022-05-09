#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char* argv[])
{
	umask(0);
	umask(S_IRGRP | S_IWGRP);
	
	if (creat(argv[1], RWRWRW) < 0) printf("file creation error.\n");
	exit(0);
	
	return 0;	
}
