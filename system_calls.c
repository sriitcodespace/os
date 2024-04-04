#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Fork to create a child process
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process executing...\n");

        // Example: execl to replace the child process image
        execl("/bin/ls", "ls", "-l", (char *)NULL);

        // This part will be executed only if execl fails
        perror("execl");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        printf("Parent process waiting for the child...\n");

        // Wait for the child to complete
        wait(NULL);

        // Example: sleep to introduce a delay
        printf("Parent process sleeping for 3 seconds...\n");
        sleep(3);

        printf("Parent process exiting...\n");
    }

    return 0;
}