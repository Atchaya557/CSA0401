#include <stdio.h>
#include <pthread.h>

void *display(void *arg)
{
    printf("Thread is created successfully\n");
    return NULL;
}

int main()
{
    pthread_t thread;

    pthread_create(&thread, NULL, display, NULL);

    pthread_join(thread, NULL);

    return 0;
}

#include <stdio.h>
#include <pthread.h>

void *display(void *arg)
{
    printf("Thread is executing\n");
    return NULL;
}

int main()
{
    pthread_t thread;

    pthread_create(&thread, NULL, display, NULL);

    pthread_join(thread, NULL);

    printf("Thread execution completed\n");

    return 0;
}

#include <stdio.h>
#include <pthread.h>

int main()
{
    pthread_t thread1, thread2;

    thread1 = pthread_self();
    thread2 = pthread_self();

    if (pthread_equal(thread1, thread2))
    {
        printf("Both threads are equal\n");
    }
    else
    {
        printf("Threads are not equal\n");
    }

    return 0;
}

#include <stdio.h>
#include <pthread.h>

void *display(void *arg)
{
    printf("Thread is running\n");

    pthread_exit(NULL);

    printf("This statement will not execute\n");
}

int main()
{
    pthread_t thread;

    pthread_create(&thread, NULL, display, NULL);

    pthread_join(thread, NULL);

    printf("Thread exited successfully\n");

    return 0;
}
