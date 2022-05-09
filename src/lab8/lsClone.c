#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	struct dirent *dp;
	
	DIR *dir = opendir(argv[1]);
	
	if(!dir)
	{
		printf("unable to open directory\n");
		return 1;
	}
	
	while((dp = readdir(dir)) != NULL) printf("%s\n", dp->d_name);
	
	closedir(dir);

	return 0;
}
