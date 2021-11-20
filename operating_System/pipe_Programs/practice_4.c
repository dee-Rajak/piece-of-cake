#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    int id1 = fork();
    int id2 = fork();

    if (id1 == 0){
        if (id2 == 0){
            printf("I am process Y\n");
        } else {
            printf("I am process X\n");
        }
    } else {
        if (id2 == 0){
            printf("I am process Z\n");
        } else {
            printf("I am MAIN process\n");
        }
    }
    if (wait(NULL) != -1 || errno != ECHILD){
        printf("Waiting for child process to die.\n");
    };
    return 0;
}