#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define N 100

char count = 0;

char consumer_sleep = 0;
char producer_sleep = 0;

char *buffer;

void *producer() {
	while(1){
		while(!producer_sleep) {
			if(count == N) {
				producer_sleep = 1;
				break;
			}
			char item = 1;
			buffer[count] = item;
			if(count == 0 || count == 99) printf("Count: %d; Producer state: %d; Consumer state: %d\n", count,!consumer_sleep,!producer_sleep);
			count++;
			if (count == 1) consumer_sleep = 0;
		}
	}
}

void *consumer() {
	while(1){
		while(!consumer_sleep) {
			if(count == 0) {
				consumer_sleep = 1;
				break;
			} 
			char item = buffer[count];
			buffer[count] = 0;
			count--;
			if (count == N-1) producer_sleep = 0;
		}
	}
}

void main() {
	buffer = malloc(N * sizeof(char));
	pthread_t producer_thread;
	pthread_t consumer_thread;
	pthread_create(&producer_thread, NULL, producer, NULL);
	pthread_create(&consumer_thread, NULL, consumer, NULL);
	pthread_join(producer_thread, NULL);
	pthread_join(consumer_thread, NULL);
}
