// Bidirectional communication using two pipes between parent and child process
// One pipe for parent-to-child communication and another for child-to-parent communication

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main() {
    int fd[2], fd1[2];
    pid_t a;
    char buff[200];

    if (pipe(fd) == -1) {
        perror("pipe_1");
        exit(1);
    }
    if (pipe(fd1) == -1) {
        perror("pipe_2");
        exit(1);
    }

    a = fork();
    if (a < 0) {
        perror("fork");
        exit(1);
    }
    else if (a == 0) { // child
        close(fd[0]);   // can't read from pipe_1, only write
        close(fd1[1]);  // can't write to pipe_2, only read

        printf("This is child, Give input for parent in pipe_1: ");
        fgets(buff, sizeof(buff), stdin);

        printf("Child sending data to parent...\n");
        write(fd[1], buff, strlen(buff) + 1);

        printf("This is child, I'm waiting to receive reply from parent...\n");
        read(fd1[0], buff, sizeof(buff));

        printf("This is child, I received reply from parent: %s\n", buff);

        close(fd[1]);
        close(fd1[0]);
    }
    else { // parent
        close(fd[1]);   // can't write to pipe_1, only read
        close(fd1[0]);  // can't read from pipe_2, only write

        // Wait for child's message first
        read(fd[0], buff, sizeof(buff));
        printf("This is parent, I received message from child: %s\n", buff);

        printf("This is parent, give reply to child in pipe_2: ");
        fgets(buff, sizeof(buff), stdin);

        printf("This is parent, I'm sending reply to child...\n");
        write(fd1[1], buff, strlen(buff) + 1);

        close(fd[0]);
        close(fd1[1]);
    }

    return 0;
}
