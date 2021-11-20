#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int arr[] = {11, 24, 36, 43, 56, 76, 75, 28, 29, 51, 23, 22, 6};
    int arrSize = sizeof(arr)/sizeof(int);
    int start, end;

    int fd[2];
    if (pipe(fd)==-1){
        printf("Piping operation failed.\n");
        return 1;
    }

    int id = fork();

    if (id == -1){
        printf("Forking operation failed.\n");
        return 2;
    }

    if (id == 0){
        start = 0;
        end = arrSize/2;
    } else {
        start = arrSize/2;
        end = arrSize;
    }

    int sum = 0;
    //making the processes sum the array elements
    for(int i = start; i < end; i++){
        sum += arr[i];
    }
    printf("Current partial sum is : %d\n", sum);
    if (id == 0){
        close(fd[0]);
        if (write(fd[1], &sum, sizeof(sum)) == -1){
            printf("Error with write operation.\n");
            return 3;
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        int sumFromChild;
        if (read(fd[0], &sumFromChild, sizeof(sumFromChild)) == -1){
            printf("Error with read operation.\n");
            return 4;
        }
        close(fd[0]);

        printf("Total sum is : %d\n", sum+sumFromChild);
        wait(NULL);
    }

    return 0;
}