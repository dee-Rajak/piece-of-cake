/*
    Author  : Dhireen Kumar Rajak
    Year    : 2021
*/

/*
11.  Enter a number, convert it into binary (8 bits), XOR it with 10101011 and display the number in decimal.
*/

/*
    NOTE : This one took quite of time to solve,
            lots of hit and trial.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>     //this is linux-specific
#include <math.h>       //add "-lm" on gcc cmd while compiling
#include <sys/wait.h>

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

        int num;
        printf("Enter a number : ");
        scanf("%d", &num);

        //XORing factor
        int xorNum[8] = {1, 0, 1, 0, 1, 0, 1, 1};

        //convert to binary array
        int biNum[20] = {0};          //incase number is greater than 255, only first 8 bits from LSB side are considered
        int newNum[8];
        int temp = num;
        int count;

        //forming array of binary of entered number
        for (count = 0; temp > 0; count++)
        {
            biNum[count] = temp%2;
            temp = temp/2;
        }

        //XORing
        int i = 0;
        int size = 7;

        if(count>7)
            size = count;

        while(i < 8){
            if(biNum[size] == xorNum[i]){
                newNum[i] = 0;
            } else {
                newNum[i] = 1;
            }
            i++;
            size--;
        }

        //Writing in file and checking write-time-error
        if (write(file[1], &newNum, sizeof(newNum)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }

        //close the writing end
        close(file[1]);
    } else {
        //keep the writing end close
        close(file[1]);

        int newNum[8];
        int num = 0;

        //Reading in file and checking read-time-error
        if(read(file[0], &newNum, sizeof(newNum)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        }
        
        //print new number in decimal
        for (int i = 0, j = 7; i < 8; i++, j--)
        {
            num += newNum[i]*pow(2, j);
        }
        printf("The number after XORing is : %d\n", num);

        //close the reading end
        close(file[0]);
    }

    return 0;
}