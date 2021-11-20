#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#define SIZE 10

int main(int argc, char const *argv[])
{
    int file[2];

    if(pipe(file)==-1){
        printf("Error occured with pipe operation.\n");
        return 1;
    }

    int id = fork();

    if(id == -1){
        printf("Error occured with fork.\n");
        return 2;
    }

    if(id == 0){
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
        // printf("#variance : %f", variance);              //for cross-refrence
        stdDeviation = sqrtf(variance);
        // printf("#stdDeviation : %f", stdDeviation);      //for cross-refrence

        if(write(file[1], &mean, sizeof(mean)) == -1){
            printf("Error while writing MEAN.\n");
            return 3;
        }
        if(write(file[1], &stdDeviation, sizeof(stdDeviation)) == -1){
            printf("Error while writing STD-DEVIATION.\n");
            return 4;
        }
        close(file[1]);

    } else {
        close(file[1]);
        float mean, stdDeviation;
        if(read(file[0], &mean, sizeof(mean)) == -1){
            printf("Error while reading MEAN.\n");
            return 5;
        }
        if(read(file[0], &stdDeviation, sizeof(stdDeviation)) == -1){
            printf("Error while reading STD-DEVIATION.\n");
            return 5;
        }
        close(file[0]);
        printf("Mean is : %.2f\n", mean);
        printf("Std-Deviation is : %.2f\n", stdDeviation);
    }

    return 0;
}