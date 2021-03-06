/*
    Author  : Dhireen Kumar Rajak
    Year    : 2021
*/

/*
1.  Enter two numbers from one end of the pipe and get the sum from the other end.
*/

/*
    NOTE : If you know how pipe and fork really works, there is nothing much to do here,
            Program is quite easy.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>     //linux-specific
#include <sys/wait.h>   //not neccessary unless you use wait()

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

        int a, b, sum;
        printf("Input first number : ");
        scanf("%d", &a);
        printf("Input second number : ");
        scanf("%d", &b);
        //calculating sum
        sum = a + b;
        
        //Writing in file and checking write-time-error
        if (write(file[1], &sum, sizeof(int)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }
        
        //close the writing end
        close(file[1]);
    } else {
        //keep the writing end close
        close(file[1]);
        
        int result;

        //Reading the file and checking read-time-error
        if(read(file[0], &result, sizeof(int)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        } 

        //print the sum
        printf("Got this result from child process : %d\n", result);

        //close the reading end
        close(file[0]);
    }

    return 0;
}