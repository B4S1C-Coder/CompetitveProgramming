#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = ftok("progfile", 65); // Generate unique key
    int msgid = msgget(key, 0666 | IPC_CREAT); // Create message queue

    pid_t pid = fork();

    if (pid == 0) {
        // Child process (Receiver)
        struct msg_buffer message;
        msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
        printf("Child received: %s\n", message.msg_text);
    } else {
        // Parent process (Sender)
        struct msg_buffer message;
        message.msg_type = 1;
        strcpy(message.msg_text, "Hello from parent!");
        msgsnd(msgid, &message, sizeof(message.msg_text), 0);
        wait(NULL); // Wait for child

        // Cleanup
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}

