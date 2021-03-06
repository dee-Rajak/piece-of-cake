/*
    Author  : Dhireen Kumar Rajak
    Year    : 2021
*/

/*
8.  Input numbers 1 – 9 in any order and display the corresponding cardinality
    e.g. 2 (Input), Second (output)
*/

/*
    NOTE : This program is not that tough, game of char-array
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>     //this is linux-specific
#include <sys/wait.h>   //not neccessary untill you use wait()
#define SIZE 15

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

        char numArr[SIZE];
        printf("You need to enter numbers (1-9) in any order (e.g., 453465).\n");
        printf("Enter the number : ");
        scanf("%s", numArr);
        
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

        char numArr[SIZE];

        //Reading the file and checking read-time-error
        if(read(file[0], &numArr, sizeof(numArr)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        }

        //process cardinality
        for (int i = 0; i < strlen(numArr); i++)
        {
            switch (numArr[i])
            {
            case '1':
                printf("First\n");
                break;
            case '2':
                printf("Second\n");
                break;
            case '3':
                printf("Third\n");
                break;
            case '4':
                printf("Fourth\n");
                break;
            case '5':
                printf("Fifth\n");
                break;
            case '6':
                printf("Sixth\n");
                break;
            case '7':
                printf("Seventh\n");
                break;
            case '8':
                printf("Eighth\n");
                break;
            case '9':
                printf("Nineth\n");
                break;
            }   
        }
        
        //close the reading end
        close(file[0]);
    }

    return 0;
}