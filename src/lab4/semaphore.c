// program to demo semaphores

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* thread_function(void* arg)
{
	sem_wait(&mutex);
	printf("entry section ... \n");
	
	sleep(4);
	printf("exit section ... \n");
	sem_post(&mutex);
}

int main()
{
	pthread_t t1, t2;
	
	sem_init(&mutex, 0, 1);
	pthread_create(&t1, NULL, &thread_function, NULL);
	sleep(2);
	
	pthread_create(&t2, NULL, &thread_function, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	sem_destroy(&mutex);
		
	return 0;
}
