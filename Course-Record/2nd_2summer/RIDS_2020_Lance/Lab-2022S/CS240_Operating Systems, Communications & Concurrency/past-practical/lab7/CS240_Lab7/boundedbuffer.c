#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

#define BUFFER_SIZE 10
#define TRUE 1

time_t buffer[BUFFER_SIZE];
int in,out;
pthread_mutex_t mutex; 
sem_t empty, full;

void init_buffer()
   {
   	in = 0; 
   	out = 0;
	pthread_mutex_init(&mutex,NULL); /* serialise buffer modifications */
	/* 2nd parameter indicates semaphore shared between threads not processes */
	sem_init(&empty,0,BUFFER_SIZE); /* buffer has max free space */
	sem_init(&full,0,0); /* No items in buffer */
   }


void insert_item(time_t timeinseconds)
   {
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
   		buffer[in] = timeinseconds;
   		in = (in + 1) % BUFFER_SIZE;
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
   }


time_t remove_item()
   {
        time_t item; /* item stores date as a number of seconds since Jan 1 1970. */
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
		item = buffer[out];
        	out = (out + 1) % BUFFER_SIZE;
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
        return item;
   }

void *consumer(void* id)
  {
	unsigned long my_id = (unsigned long) id;
	time_t timeinseconds;

	while (TRUE) {
		sleep(2);
		timeinseconds = remove_item(); /* Consume the date item */
		printf("Consumer %ld Removed %ld \n",my_id, timeinseconds);
	}
}

void *producer(void* id)
   {
	unsigned long my_id = (unsigned long) id;
	time_t timeinseconds;

	while (TRUE) {
		timeinseconds = time(NULL);  /* Produce a date item */
		insert_item(timeinseconds);
		printf("Producer %ld Inserted %ld \n",my_id, timeinseconds);
		sleep(1);
	}
}


int main(int argc, char **argv) {
	pthread_t thread1, thread2, thread3, thread4;
	unsigned long p1 = 1;
	unsigned long c1 = 1;
	unsigned long p2 = 2;
        unsigned long c2 = 2;
	init_buffer(); 

	/* Start 2 producer and 2 consumer threads and give them ids*/
	pthread_create(&thread1, NULL, consumer, (void *) p1);
	pthread_create(&thread2, NULL, producer, (void *) c1);
	pthread_create(&thread3, NULL, consumer, (void *) p2);
	pthread_create(&thread4, NULL, producer, (void *) c2);

	/* Execute pthread_join to prevent main thread from exiting and terminating
           program */
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	printf("All threads finished\n"); /* Will never happen as threads loop indefinitely */
	exit(0);
}
