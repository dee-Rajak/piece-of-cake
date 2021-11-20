/*
    Author  : Dhireen Kumar Rajak
    Year    : 2021
*/

/*
4.  Input 8 numbers and display/output the result by 2X2 matrix manipulation.
*/

/*
    NOTE : This program shows the real beauty of shared-memory and buffer concept.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>     //this is linux-specific
#include <sys/wait.h>   //not neccessary untill you use wait()
#define SIZE 8

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
        //keep the reaading end close
        close(file[0]);

        int numArr[SIZE];
        printf("You need to enter 8 numbers to create two-matrix of size 2x2.\n");
        for (int i = 0; i < SIZE; i++)
        {
            printf("Enter number %d : ", i+1);
            scanf("%d", &numArr[i]);
        }
        
        //Writing in file and checking write-time-error
        if (write(file[1], &numArr, sizeof(numArr)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }

        //close the writing end
        close(file[1]);
    } else {
        //keep the writing end close
        close(file[1]);

        int numArr[2][2];

        //Reading in file and checking read-time-error
        if(read(file[0], &numArr, sizeof(numArr)) == -1){       //getting first 4 chunk of data from pipe
            printf("Error ocurred while Reading.\n");
            return 5;
        }

        printf("----Matrix 1----\n");
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                printf("%5d", numArr[i][j]);
            }
            printf("\n");
        }

        //Reading in file and checking read-time-error
        if(read(file[0], &numArr, sizeof(numArr)) == -1){       //getting remaining 4 chunk of data from pipe
            printf("Error ocurred while Reading.\n");
            return 6;
        }

        printf("----Matrix 2----\n");
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                printf("%5d", numArr[i][j]);
            }
            printf("\n");
        }
        
        //close the reading end
        close(file[0]);
    }

    return 0;
}