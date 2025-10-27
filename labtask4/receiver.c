// Program 3
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

    if (msgrcv(msgid, &message, sizeof(message.num), 6, IPC_NOWAIT) == -1) {
        printf("Program 3 read complete. No data found of type 6.\n");
    } else {
        printf("Program 3 read complete. Number is %d.\n", message.num);
    }

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
