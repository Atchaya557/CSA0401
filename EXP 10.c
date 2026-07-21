#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long msg_type;
    char msg_text[100];
};

int main()
{
    // Generate a unique key
    key_t key = ftok("msgqfile", 65);

    // Create a message queue
    int msgid = msgget(key, IPC_CREAT | 0666);

    if (msgid == -1)
    {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    struct message msg;

    // Message type
    msg.msg_type = 1;

    // Producer: Send message
    strcpy(msg.msg_text, "Hello, message queue!");

    if (msgsnd(msgid, (void *)&msg, sizeof(msg.msg_text), IPC_NOWAIT) == -1)
    {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Producer: Data sent to message queue: %s\n", msg.msg_text);

    // Consumer: Receive message
    if (msgrcv(msgid, (void *)&msg, sizeof(msg.msg_text), 1, 0) == -1)
    {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    printf("Consumer: Data received from message queue: %s\n", msg.msg_text);

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}

OUTPUT

Producer: Data sent to message queue: Hello, message queue!
Consumer: Data received from message queue: Hello, message queue!
