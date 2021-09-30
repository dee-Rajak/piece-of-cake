/*
1.  Enter two numbers from one end of the pipe and get the sum from the other end.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//Well, we have learned enough to WAP to SUM two num via multi-process

int main(int argc, char const *argv[])
{
    int file[2];
    //file[0] - read
    //file[1] - write
    if (pipe(file) == -1){
        printf("Error occured with pipe opening.\n");
        return 1;
    }
    int id = fork();

    //check error while forking
    if (id == -1){
        printf("Error ocurred with fork.\n");
        return 2;
    }

    if (id == 0){
        close(file[0]);
        int a, b, sum;
        printf("Input first number : ");
        scanf("%d", &a);
        printf("Input second number : ");
        scanf("%d", &b);
        //calculating sum
        sum = a + b;
        if (write(file[1], &sum, sizeof(int)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }
        close(file[1]);
    } else {
        close(file[1]);
        int result;

        if(read(file[0], &result, sizeof(int)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        } 
        close(file[0]);
        printf("Got this result from child process : %d\n", result);
    }

    return 0;
}