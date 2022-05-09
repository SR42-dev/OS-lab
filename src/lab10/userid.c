#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char* argv[])
{
	int rv = 0;
	
	rv = setuid(2000); // only superuser can execute this command
	
	if(rv < 0) printf("setting error \n");
	
	rv = setgid(2000); // only superuser can execute this command
	if(rv < 0) printf("setting error\n");
	
	printf("real UID = %d, effective UID = %d\n", getuid(), geteuid());
	exit(0);
	
	return 0;	
}
