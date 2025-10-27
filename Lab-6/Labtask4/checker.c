// Program 2
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg {
    long type;
    int num;
};

int main() {
    key_t key;
    int msgid;
    struct msg message;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    if (msgrcv(msgid, &message, sizeof(message.num), 5, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }

    printf("Program 2 read complete, ");
    if (message.num % 2 == 0) {
        printf("Number is even. ");
        message.type = 6;
        msgsnd(msgid, &message, sizeof(message.num), 0);
        printf("Write complete\n");
    } else {
        printf("Number is odd. No write\n");
    }

    return 0;
}
