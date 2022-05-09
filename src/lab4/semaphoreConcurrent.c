// demo of semaphores with concurrence
// removal of all semaphore functions & locks results in concurrent execution
// 

#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

sem_t mutex;

void* mythread_1(void* arg)
{
	char s[] = "ROYALCHALLENGERS";
	int l = strlen(s);
	
	for(int i = 0; i < l; i++)
	{
		sem_wait(&mutex); // wait
		
		putchar(s[i]);
		fflush(stdout);
		sleep(1);
		
		sem_post(&mutex); // signal
	}
}

void* mythread_2(void* arg)
{
	char s[] = "RAJASTHANROYALS";
	int l = strlen(s);
	
	for(int i = 0; i < l; i++)
	{
		sem_wait(&mutex);
		
		putchar(s[i]);
		fflush(stdout);
		sleep(1);
		
		sem_post(&mutex);
	}
}

void* mythread_3(void* arg)
{
	char s[] = "MUMBAIINDIANS";
	int l = strlen(s);
	
	for(int i = 0; i < l; i++)
	{
		sem_wait(&mutex);
		
		putchar(s[i]);
		fflush(stdout);
		sleep(1);
		
		sem_post(&mutex);
	}
}

int main()
{
	pthread_t t1, t2, t3;
	sem_init(&mutex, 0, 1);
	
	pthread_create(&t1, NULL, &mythread_1, NULL);
	pthread_create(&t2, NULL, &mythread_2, NULL);
	pthread_create(&t3, NULL, &mythread_3, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	
	printf("\n");
	
	sem_destroy(&mutex);

	return 0;
}
