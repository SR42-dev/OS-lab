#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{

	int fd;
	int i,err=0;
	char buf[10]="";
	
	fd = creat("text.txt",S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH); //add file path
	
	if(fd == -1) printf("unable to create a file/n");
	
	for(i = 0; i < 10; i++) write(fd,"0123456789",10);
	close(fd);
	
	fd = open("text.txt",O_RDWR,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
	
	err = lseek(fd,5,SEEK_SET);
	
	if(err == -1) printf("unable to seek\n");
	err=read(fd,buf,5);
	
	if(err == -1) printf("unable to read the file\n");
	printf("read : %s\n",buf);
	err = lseek(fd,-4,SEEK_END);
	
	if(err == -1) printf("unable to seek.\n");
	memset(buf,0,strlen(buf));
	err=read(fd,buf,3);
	
	if(err == -1) printf("unable to read the file\n");
	printf("read : %s\n",buf);
	close(fd);
	
	return 0;

}
