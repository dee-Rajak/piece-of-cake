/*
    Author  : Dhireen Kumar Rajak
    Year    : 2021
*/

/*
9.  Input temperature in oC and display the temperature in oF.
*/

/*
    NOTE : Ahh, this is reallly simple program, just like q1, and q2
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>     //this is linux-specific
#include <sys/wait.h>   //not neccessary untill you use wait()

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

        float a, b;
        printf("Input temperature in Celsius : ");
        scanf("%f", &a);
        //conversion celsius -> fahrenheit
        b = (a * 9/5) + 32;

        //Writing in file and checking write-time-error
        if (write(file[1], &b, sizeof(float)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }

        //close the writing end
        close(file[1]);
    } else {
        //keep the writing end close
        close(file[1]);
        
        float result;

        //Reading the file and checking read-time-error
        if(read(file[0], &result, sizeof(float)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        } 

        printf("Temperature in Fahrenheit : %.2f\n", result);

        //close the reading end
        close(file[0]);
    }

    return 0;
}