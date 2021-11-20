/*
    Author  : Dhireen Kumar Rajak
    Year    : 2021
*/

/*
2.  Input two numbers, through the child process and find their product and quotient
    in the parent process. If there is any error during the processing, display the error.
*/
 
/*
    NOTE : Quite similar to previous program, just changed the arithmetic operators
*/

/*
    PS : I dont know yet that pipe works on FIFO concept
        thus, you will find two different file-descriptors
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>     //linux-specific
#include <sys/wait.h>   //not neccessary unless you use wait()

int main(int argc, char const *argv[])
{
    int file1[2], file2[2];
    //file[0] - read
    //file[1] - write

    /*
     *  Note : pipe is like a shared-memory,
     *  In multi-process programming, you share this memory among multiple processes.
     *  And this is what we are doing here !
     */
    //check error while making pipe
    if ((pipe(file1) == -1) || (pipe(file2) == -1)){
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
        //this is child process
        close(file1[0]);
        close(file2[0]);

        int a, b;
        printf("Input first number : ");
        scanf("%d", &a);
        printf("Input second number : ");
        scanf("%d", &b);

        //Writing in file and checking write-time-error
        if (write(file1[1], &a, sizeof(int)) == -1){
            printf("Error ocurred while Writing file1.\n");
            return 4;
        }
        //Writing in file and checking write-time-error
        if (write(file2[1], &b, sizeof(int)) == -1){
            printf("Error ocurred while Writing file2.\n");
            return 5;
        }

        //close the writing end
        close(file1[1]);
        close(file2[1]);
    } else {
        //this is Main process
        close(file1[1]);
        close(file2[1]);
        int x, y;

        //Reading in file and checking read-time-error
        if(read(file1[0], &x, sizeof(int)) == -1){
            printf("Error ocurred while Reading file1.\n");
            return 6;
        } 
        //Reading in file and checking read-time-error
        if(read(file2[0], &y, sizeof(int)) == -1){
            printf("Error ocurred while Reading file2.\n");
            return 7;
        } 


        int product = x*y;
        printf("Product of two number is : %d\n", product);

        if (y != 0){
            float quotient = (float)x/y;
            printf("Quotient of two number is : %.2f\n", quotient);
        }
        else
            printf("Division error, divisor is 0\n");
        
        //close the reading end of files
        close(file1[0]);
        close(file2[0]);
    }

    return 0;
}