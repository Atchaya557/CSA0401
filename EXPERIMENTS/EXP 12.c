// Dining Philosophers Problem using POSIX Threads and Mutex
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define N 5
pthread_mutex_t fork_mutex[N];

void *philosopher(void *num)
{
    int id = *(int *)num;

    while (1)
    {
        printf("Philosopher %d is Thinking\n", id);
        sleep(1);

        printf("Philosopher %d is Hungry\n", id);

        pthread_mutex_lock(&fork_mutex[id]);
        printf("Philosopher %d picked up Left Fork %d\n", id, id);

        pthread_mutex_lock(&fork_mutex[(id + 1) % N]);
        printf("Philosopher %d picked up Right Fork %d\n", id, (id + 1) % N);

        printf("Philosopher %d is Eating\n", id);
        sleep(2);

        pthread_mutex_unlock(&fork_mutex[id]);
        pthread_mutex_unlock(&fork_mutex[(id + 1) % N]);

        printf("Philosopher %d put down both forks\n\n", id);

        break;  
    }

    return NULL;
}

int main()
{
    pthread_t thread[N];
    int id[N];

    for (int i = 0; i < N; i++)
        pthread_mutex_init(&fork_mutex[i], NULL);

    for (int i = 0; i < N; i++)
    {
        id[i] = i;
        pthread_create(&thread[i], NULL, philosopher, &id[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(thread[i], NULL);

    for (int i = 0; i < N; i++)
        pthread_mutex_destroy(&fork_mutex[i]);

    return 0;
}

OUTPUT :

Philosopher 0 is Thinking
Philosopher 1 is Thinking
Philosopher 2 is Thinking
Philosopher 3 is Thinking
Philosopher 4 is Thinking

Philosopher 0 is Hungry
Philosopher 0 picked up Left Fork 0
Philosopher 0 picked up Right Fork 1
Philosopher 0 is Eating

Philosopher 2 is Hungry
Philosopher 2 picked up Left Fork 2
Philosopher 2 picked up Right Fork 3
Philosopher 2 is Eating

Philosopher 0 put down both forks
Philosopher 2 put down both forks
...
