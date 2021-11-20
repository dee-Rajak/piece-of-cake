/*
    Author  : Dhireen Kumar Rajak
    Year    : 2021
*/

/*
5.  Enter/Input 10 numbers and display the numbers in ascending order.
*/

/*
    Note : Really nothing much to do here, if you have done the previous programs,
            then all you do here is sort an array
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>     //this is linux-specific
#include <sys/wait.h>   //not neccessary untill you use wait()
#define SIZE 10

void insertionSort(int arr[], int n);

int main(int argc, char const *argv[])
{
    int file[2];
    //file[0] - read
    //file[1] - write

    /*
     *  Note : pipe is like a shared-memory,
     *  In multi-process programming, you share this memory among multiple processes.
     *  And this is what we are doing here !
     */
    //check error while making pipe
    if (pipe(file) == -1){
        printf("Error occured with pipe operation.\n");
        return 1;
    }

    //making child process using fork, and keeping the process-id in variable "id"
    int id = fork();
    //check error while forking
    if (id == -1){
        printf("Error ocurred with fork.\n");
        return 2;
    }

    if (id == 0){
        //keep the reading end close
        close(file[0]);

        int aArr[SIZE];

        printf("You have to enter %d numbers.\n", SIZE);
        for(int i = 0; i < SIZE; i++){
            printf("Input a number -> ");
            scanf("%d", &aArr[i]);
        }

        //Writing in file and checking write-time-error
        if (write(file[1], &aArr, sizeof(aArr)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }

        //close the writing end
        close(file[1]);
    } else {
        //keep the writing end close
        close(file[1]);

        int bArr[SIZE];

        //Reading the file and checking read-time-error
        if(read(file[0], &bArr, sizeof(bArr)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        }

        //sort it in ascending order
        insertionSort(bArr, SIZE);

        //print array
        for(int i = 0; i < SIZE; i++){
            printf("%d\t", bArr[i]);
        }
        printf("\n");

        //close the reading end
        close(file[0]);
    }
    return 0;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}