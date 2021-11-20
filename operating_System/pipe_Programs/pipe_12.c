/*
    Author  : Dhireen Kumar Rajak
    Year    : 2021
*/

/*
12.   Input a set of 10 numbers and display mean and standard deviation for this set of input.
*/

/*
    NOTE : I had to look for formula on internet, math is not my piece of cake
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     //this is linux-specific
#include <math.h>       //add "-lm" on gcc cmd while compiling
#define SIZE 10

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
    if(pipe(file)==-1){
        printf("Error occured with pipe operation.\n");
        return 1;
    }

    //making child process using fork, and keeping the process-id in variable "id"
    int id = fork();
    //check error while forking
    if(id == -1){
        printf("Error occured with fork.\n");
        return 2;
    }

    if(id == 0){
        //keep the reading end close
        close(file[0]);

        float aArr[SIZE], sum = 0, mean, deviation, sumSq = 0, variance, stdDeviation;

        printf("You need to input set of 10 numbers!\n");
        for(int i=0; i<SIZE; i++){
            printf("Enter a number : ");
            scanf("%f", &aArr[i]);
            sum += aArr[i];
        }

        mean = sum/SIZE;

        // printf("#mean : %f", mean);                      //for cross-refrence
        for(int i=0; i<SIZE; i++){
            deviation = aArr[i] - mean;
            sumSq += deviation*deviation;
        }

        variance = sumSq/SIZE;

        stdDeviation = sqrtf(variance);

        //Writing in file and checking write-time-error
        if(write(file[1], &mean, sizeof(mean)) == -1){
            printf("Error while writing MEAN.\n");
            return 3;
        }
        //Writing in file and checking write-time-error
        if(write(file[1], &stdDeviation, sizeof(stdDeviation)) == -1){
            printf("Error while writing STD-DEVIATION.\n");
            return 4;
        }

        //close the writing end
        close(file[1]);
    } else {
        //keep the writing end close
        close(file[1]);
        
        float mean, stdDeviation;

        //Reading in file and checking read-time-error
        if(read(file[0], &mean, sizeof(mean)) == -1){
            printf("Error while reading MEAN.\n");
            return 5;
        }
        //Reading in file and checking read-time-error
        if(read(file[0], &stdDeviation, sizeof(stdDeviation)) == -1){
            printf("Error while reading STD-DEVIATION.\n");
            return 5;
        }

        printf("Mean is : %.2f\n", mean);
        printf("Std-Deviation is : %.2f\n", stdDeviation);

        //close the reading end
        close(file[0]);
    }

    return 0;
}