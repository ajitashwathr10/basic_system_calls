#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid1, pid2;

    printf("P1: PID = %d, PPID = %d\n", getpid(), getppid());

    pid1 = fork();  // Create P2
    if (pid1 == 0) {
        printf("P2: PID = %d, PPID = %d\n", getpid(), getppid());

        pid2 = fork();  // Create P3
        if (pid2 == 0) {
            printf("P3: PID = %d, PPID = %d\n", getpid(), getppid());
        }
    }

    return 0;
}

