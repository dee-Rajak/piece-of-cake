#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define SIZE 3

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
        int aArr[SIZE];
        for(int i = 0; i < SIZE; i++){
            printf("Input a number : ");
            scanf("%d", &aArr[i]);
        }

        if (write(file[1], &aArr, sizeof(aArr)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }
        close(file[1]);
    } else {
        close(file[1]);
        int bArr[SIZE];

        if(read(file[0], &bArr, sizeof(bArr)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        } 
        close(file[0]);
        for(int i = 0; i < SIZE; i++){
            printf("Got this from child process : %d\n", bArr[i]);
        }
        printf("\n");
    }

    return 0;
}