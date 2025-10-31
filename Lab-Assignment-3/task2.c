#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>

struct msg {
    long int type;
    char txt[50];
};

int main() {
    pid_t otp_pid, otp;
    int msgid;
    struct msg message;
    char workspace[50];
    const int MSGSZ = sizeof(message.txt);  // Explicit constant for message size

    msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    printf("Please enter the workspace name:\n");
    scanf("%49s", workspace);  // limit input size to 49 chars + '\0'

    if (strcmp(workspace, "cse321") != 0) {
        printf("Invalid workspace name\n");
        exit(0);
    }

    // Log in process sends workspace name to otp generator (type 1)
    message.type = 1;
    strncpy(message.txt, workspace, sizeof(message.txt) - 1);
    message.txt[sizeof(message.txt)-1] = '\0';

    if (msgsnd(msgid, &message, MSGSZ, 0) == -1) {
        perror("msgsnd failed");
        exit(1);
    }
    printf("Workspace name sent to otp generator from log in: %s\n\n", message.txt);

    otp_pid = fork();

    if (otp_pid == -1) {
        perror("fork failed");
        exit(1);
    }
    else if (otp_pid == 0) { // OTP generator process
        // Read workspace name from log in (type 1)
        if (msgrcv(msgid, &message, MSGSZ, 1, 0) == -1) {
            perror("msgrcv failed");
            exit(1);
        }
        printf("OTP generator received workspace name from log in: %s\n\n", message.txt);

        // Generate OTP as process id string
        otp = getpid();
        snprintf(message.txt, sizeof(message.txt), "%d", otp);

        // Send OTP to log in (type 2)
        message.type = 2;
        if (msgsnd(msgid, &message, MSGSZ, 0) == -1) {
            perror("msgsnd to log in");
            exit(1);
        }
        printf("OTP sent to log in from OTP generator: %s\n", message.txt);

        // Send OTP to mail (type 3)
        message.type = 3;
        if (msgsnd(msgid, &message, MSGSZ, 0) == -1) {
            perror("msgsnd to mail");
            exit(1);
        }
        printf("OTP sent to mail from OTP generator: %s\n", message.txt);

        // Fork mail process
        pid_t mail_pid = fork();
        if (mail_pid == -1) {
            perror("fork mail failed");
            exit(1);
        }
        else if (mail_pid == 0) {
            // Mail process reads from OTP generator (type 3)
            if (msgrcv(msgid, &message, MSGSZ, 3, 0) == -1) {
                perror("msgrcv mail failed");
                exit(1);
            }
            printf("Mail received OTP from OTP generator: %s\n", message.txt);

            // Send OTP to log in (type 4)
            message.type = 4;
            if (msgsnd(msgid, &message, MSGSZ, 0) == -1) {
                perror("msgsnd mail to log in failed");
                exit(1);
            }
            printf("OTP sent to log in from mail: %s\n", message.txt);
            _exit(0);
        }
        else {
            // OTP generator waits for mail
            wait(NULL);
            exit(0);
        }
    }
    else {
        // Parent -> log in process waits for otp generator and mail to finish
        wait(NULL);

        // Receive OTP from otp generator (type 2)
        if (msgrcv(msgid, &message, MSGSZ, 2, 0) == -1) {
            perror("msgrcv log in from otp gen failed");
            exit(1);
        }
        printf("Log in received OTP from OTP generator: %s\n", message.txt);
        char otp_gen_msg[6];
        strncpy(otp_gen_msg, message.txt, sizeof(otp_gen_msg));

        // Receive OTP from mail (type 4)
        if (msgrcv(msgid, &message, MSGSZ, 4, 0) == -1) {
            perror("msgrcv log in from mail failed");
            exit(1);
        }
        printf("Log in received OTP from mail: %s\n", message.txt);
        char mail_msg[6];
        strncpy(mail_msg, message.txt, sizeof(mail_msg));

        // Compare OTPs
        if (strcmp(otp_gen_msg, mail_msg) == 0) {
            printf("OTP Verified\n");
        } else {
            printf("OTP Incorrect\n");
        }
        msgctl(msgid, IPC_RMID, NULL);
    }
    return 0;
}