// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x = 20;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, child here (pid: %d), x is: %d\n", (int) getpid(), x);
        x++;
        printf("child x is now: %d\n", x);
    } else {
        printf("hello, parent here (pid: %d), x is: %d\n", (int) getpid(), x);
        x--;
        printf("parent x is now: %d\n", x);
    }
    return 0;
}
