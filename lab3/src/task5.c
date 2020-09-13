#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    /* fork и exec в порожденном процессе */
    if (fork() == 0) {
        printf("In child process:\n");
        execv("sequential_min_max", argv);
        printf("I will never be called\n");
    }
    wait (0);
    printf("Execution continues in parent process\n");
	return 0;
}