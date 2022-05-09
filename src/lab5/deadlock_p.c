#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

pthread_t tid1, tid2;
pthread_mutex_t mutex1, mutex2;

void* process1(void* param)
{
	pthread_mutex_lock(&mutex1);
	sleep(5);
	pthread_mutex_lock(&mutex2);
	
	printf("job 1 is executing\n");
	sleep(5);
	printf("job 1 is finished\n");
	
	pthread_mutex_unlock(&mutex2);
	sleep(5);
	pthread_mutex_unlock(&mutex1);
	pthread_exit(0);
}

void* process2(void* param)
{
	pthread_mutex_lock(&mutex1);
	sleep(5);
	pthread_mutex_lock(&mutex2);
	
	printf("job 2 is executing\n");
	sleep(5);
	printf("job 2 is finished\n");
	
	pthread_mutex_unlock(&mutex2);
	sleep(5);
	pthread_mutex_unlock(&mutex1);
	pthread_exit(0);
}

int main()
{
	int error;
	
	if(pthread_mutex_init(&mutex1, NULL)) 
	{
		printf("mutex 1 failed to create \n");
		return 1;
	}
	
	if(pthread_mutex_init(&mutex2, NULL)) 
	{
		printf("mutex 2 failed to create \n");
		return 1;
	}
	
	error = pthread_create(&tid1, NULL, &process1, NULL);
	if (error != 0) printf("process 1 can't be created : [%s]\n", strerror(error));
	
	error = pthread_create(&tid2, NULL, &process2, NULL);
	if (error != 0) printf("process 2 can't be created : [%s]\n", strerror(error));
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	
	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);

	return 0;
}


