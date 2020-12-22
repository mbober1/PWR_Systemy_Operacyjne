#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 24

int samplesPerThread = 100;
int circle;
int results[NUM_THREADS];

void* child_fun(void *id);

int main() {
    pthread_t threads[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; ++i) pthread_create(&threads[i], NULL, child_fun, (void *)i);
    for(int i = 0; i < NUM_THREADS; ++i) pthread_join(threads[i], NULL);
    for(int i = 0; i < NUM_THREADS; ++i) circle+= results[i];

    printf("Samples: %d, Circle: %d, PI: %f\n", samplesPerThread*NUM_THREADS, circle, (circle*4.00/(samplesPerThread*NUM_THREADS)));
    pthread_exit(NULL);
}

void* child_fun(void *id) {
    for(int i = 0; i < samplesPerThread; ++i) {
        double x = drand48();
        double y = drand48();
        if (x*x + y*y <= 1) results[(int)id]++;
    }
    pthread_exit(NULL);
}