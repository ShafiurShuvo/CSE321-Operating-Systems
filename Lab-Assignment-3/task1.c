#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

struct shared {
    char sel[100];
    int b;
};

int main() {
    int shmid;
    struct shared *shm_ptr;
    int fd[2];  // Declare pipe as int array, sizem = 2

    // Create shared memory
    shmid = shmget(IPC_PRIVATE, sizeof(struct shared), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory
    shm_ptr = (struct shared *)shmat(shmid, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Create pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    printf("Provide Your Input From Given Options:\n");
    printf("1. Type a to Add Money\n");
    printf("2. Type w to Withdraw Money\n");
    printf("3. Type c to Check Balance\n");

    char choice;
    scanf(" %c", &choice);

    // Initialize shared data
    snprintf(shm_ptr->sel, sizeof(shm_ptr->sel), "%c", choice);
    shm_ptr->b = 1000;

    printf("Your selection: %c\n\n", choice);

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } 
    else if (pid == 0) { // Child process
        char sel = shm_ptr->sel[0];
        int balance = shm_ptr->b;

        if (sel == 'a') {
            printf("Enter amount to be added:\n");
            int amt;
            scanf("%d", &amt);
            if (amt > 0) {
                balance += amt;
                shm_ptr->b = balance;
                printf("Balance added successfully\n");
                printf("Updated balance after addition:\n%d\n", balance);
            } else {
                printf("Adding failed, Invalid amount\n");
            }
        }
        else if (sel == 'w') {
            printf("Enter amount to be withdrawn:\n");
            int amt;
            scanf("%d", &amt);
            if (amt > 0 && amt <= balance) {
                balance -= amt;
                shm_ptr->b = balance;
                printf("Balance withdrawn successfully\n");
                printf("Updated balance after withdrawal:\n%d\n", balance);
            } else {
                printf("Withdrawal failed, Invalid amount\n");
            }
        }
        else if (sel == 'c') {
            printf("Your current balance is:\n%d\n", balance);
        }
        else {
            printf("Invalid selection\n");
        }

        // Write message to pipe
        const char *thankyou = "Thank you for using";
        write(fd[1], thankyou, strlen(thankyou) + 1);
        close(fd[1]);

        exit(0);  // Child process ends
    }
    else { // Parent process
        wait(NULL);
        close(fd[1]); // Close unused write end
        char buffer[100] = {0};
        read(fd[0], buffer, sizeof(buffer)); 
        printf("%s\n", buffer);
        close(fd[0]);

        // Cleanup shared memory
        shmdt(shm_ptr);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
