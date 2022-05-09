/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

int main () 
{
	  DIR *d;
	  struct dirent *dir;
	  struct stat stats;
	  long dt;

	  char dirname[256];
	  printf("Input directory: "); 
	  fflush(stdout);
	  scanf("%s", dirname);
	  d = opendir(dirname);

	  int size;
	  printf("Input size: ");
	  scanf("%d", &size);

	  if(!d) 
	  {
		    printf("error\n");
		    exit(0);
	  }

	  while ((dir = readdir(d))) 
	  {
	    if (stat(dir->d_name, &stats) == 0) 
	    {
		      dt = stats.st_size; 
		      printf("%ld\n",dt);

		      if (dt > size) printf("File: %s\n", dir->d_name);
	    }
	    else printf("Couldn't read file properties of file: %s\n ", dir->d_name);
	  }
	  closedir(d);

	  return 0;
}
*/


// alternate method
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *command = (char*)malloc(256 * sizeof(char));
	char *path = (char*)malloc(256 * sizeof(char));
	int size;
	
	printf("Input directory path : ");
	scanf("%s", path);
	
	printf("Input the desired file size : ");
	scanf("%d", &size);
	
	sprintf(command, "find %s -size +%dk", path, size);
	system(command);
	
	return 0;
}


