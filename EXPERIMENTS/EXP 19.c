#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t mutex;

// Thread function
void *increment(void *arg)
{
    pthread_mutex_lock(&mutex);

    // Critical Section
    counter++;
    printf("Counter = %d\n", counter);

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    // Wait for threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}

OUTPUT

Counter = 1
Counter = 2
