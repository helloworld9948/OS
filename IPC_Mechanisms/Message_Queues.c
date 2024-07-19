#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

struct msg_buffer {
    long msg_type;
    char msg[100];
} message;

int main() {
    key_t key = ftok("progfile", 65);
    int msg_id = msgget(key, 0666 | IPC_CREAT);
    message.msg_type = 1;
    printf("Write Message: ");
    fgets(message.msg, 100, stdin);
    msgsnd(msg_id, &message, sizeof(message), 0);
    printf("Sent message: %s\n", message.msg);

    msgrcv(msg_id, &message, sizeof(message), 1, 0);
    printf("Received message: %s\n", message.msg);
    msgctl(msg_id, IPC_RMID, NULL);
    return 0;
}
