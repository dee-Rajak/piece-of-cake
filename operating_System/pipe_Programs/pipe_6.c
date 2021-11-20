/*
    Author  : Dhireen Kumar Rajak
    Year    : 2021
*/

/*
6.  Enter any hexadecimal number and display the equivalent decimal and binary numbers.
*/

/*
    Note : I have to think a bit to code this, game of format specifier, arrays, and data-types
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
        //keep the reaading end close
        close(file[0]);

        long unsigned int hexNum;
        printf("Enter any hexadecimal number : ");
        scanf("%x", &hexNum);

        //Writing in file and checking write-time-error
        if (write(file[1], &hexNum, sizeof(hexNum)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }

        //close the writing end
        close(file[1]);
    } else {
        //keep the writing end close
        close(file[1]);

        long unsigned int decNum;
        int biNum[50];

        //Reading in file and checking read-time-error
        if(read(file[0], &decNum, sizeof(decNum)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        }

        //conversion is only needed for binary, because using "%d" specifire desimal conversion can be done
        printf("In Decimal : %ld\n", decNum);
        printf("In Binary : ");

        //binary conversion using Array
        long unsigned int temp = decNum;
        int count;
        for (count = 0; temp > 0; count++)
        {
            biNum[count] = temp%2;
            temp = temp/2;
        }
        for (count = count - 1; count>=0; count--)
        {
            printf("%d",biNum[count]);
        }
        printf("\n");
        
        //close the reading end
        close(file[0]);
    }

    return 0;
}