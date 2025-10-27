// Program 1
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

    key = ftok("progfile", 65); // common key
    msgid = msgget(key, 0666 | IPC_CREAT);

    printf("User Input: ");
    scanf("%d", &message.num);

    message.type = 5;
    msgsnd(msgid, &message, sizeof(message.num), 0);
    printf("Program 1 read complete and write complete\n");

    return 0;
}
