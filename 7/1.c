#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	50

void* child_fun(void *id);

int main() {
   pthread_t threads[NUM_THREADS];

   for(int i = 0; i < NUM_THREADS; ++i) pthread_create(&threads[i], NULL, child_fun, (void *)i);

   pthread_exit(NULL);
}

void* child_fun(void *id) {
   printf("Hello SCR. Written by thread %d \n", id);
   pthread_exit(NULL);
}