#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void tree(char *basepath, const int root)
{
	int i;
	char path[128];
	
	struct dirent * dp;
	DIR *dir = opendir(basepath);
	
	if(!dir) return;
	
	while((dp = readdir(dir)) != NULL) if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) 
	{
		for(i = 0; i < root; i++)
		{
			if (i == 0 || i % 2 == 0) printf("%c", '|');
			else printf(" ");
		}
		
		printf("%c%c%s\n", '|', '_', dp->d_name);
		strcpy(path, basepath);
		strcat(path, "/");
		strcat(path, dp->d_name);
		tree(path, root + 2);
	}
	
	closedir(dir);
}

int main(int argc, char *argv[])
{
	tree(argv[1], 0);
	return 0;
}
