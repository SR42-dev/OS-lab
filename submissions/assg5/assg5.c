#define _POSIX_SOURCE

#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int truncate(const char* path, off_t length);

int main(int argc, char* argv[])
{

    DIR* dir;
    struct dirent* entry;

    if ((dir = opendir(argv[1])) == NULL) perror("\nopendir() error");

    else
    {
        printf("\ndirectory  %s on : %s/%s/%s contained the following files:", argv[1], argv[2], argv[3], argv[4]);

        while ((entry = readdir(dir)) != NULL)
        {

            char* t = (char*)calloc(100, sizeof(char));
            struct stat b;

            if (!stat(entry->d_name, &b))
            {

                strftime(t, 100, "%d/%m/%Y %H:%M:%S", localtime(&b.st_mtime));
                int day = atoi(strtok(t, "/"));
                int month = atoi(strtok(NULL, "/"));
                int year = atoi(strtok(NULL, " "));
                int _day = atoi(argv[2]);
                int _month = atoi(argv[3]);
                int _year = atoi(argv[4]);

                if (_year <= year && _month <= month && _day <= day)
                {
                    printf("\nfileName : \"%s\" \n last modified at : %s", entry->d_name, t);
                    char path[100];
                    strcpy(path, argv[1]);
                    strcat(path, "/");
                    strcat(path, entry->d_name);
                    int length = b.st_size;
                    truncate(path, length / 2);
                }
            }

            else printf("error\n");

            closedir(dir);

        }

        printf("\n");

    }

    return 0;

}


