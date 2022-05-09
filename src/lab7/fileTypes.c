#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int i;
	struct stat buf;
	char* ptr;
	
	for(i = 1; i < argc; i++)
	{
		printf("directory/filename : %s\n", argv[i]);
		
		if(lstat(argv[i], &buf) < 0)
		{
			printf("lstat error\n");
			continue;
		}
		
		if (S_ISREG(buf.st_mode)) ptr = "regular file";
		else if (S_ISDIR(buf.st_mode)) ptr = "directory";
		else if (S_ISCHR(buf.st_mode)) ptr = "char file";
		else if (S_ISBLK(buf.st_mode)) ptr = "block file";
		else if (S_ISFIFO(buf.st_mode)) ptr = "fifo file";
		else if (S_ISLNK(buf.st_mode)) ptr = "symbolic link file";
		else if (S_ISSOCK(buf.st_mode)) ptr = "socket file";
		else ptr = "unknown file";
		
		printf("file type : %s\n", ptr);
		printf("file size : %ld\n", buf.st_size);
	}
	
	exit(0);
	return 0;
}
