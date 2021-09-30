/*
9.  Input temperature in oC and display the temperature in oF.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int file[2];
    //file[0] - read
    //file[1] - write
    if (pipe(file) == -1){
        printf("Error occured with pipe opening.\n");
        return 1;
    }
    int id = fork();

    //check error while forking
    if (id == -1){
        printf("Error ocurred with fork.\n");
        return 2;
    }

    if (id == 0){
        close(file[0]);
        float a, b;
        printf("Input temperature in Celsius : ");
        scanf("%f", &a);
        //conversion celsius -> fahrenheit
        b = (a * 9/5) + 32;
        if (write(file[1], &b, sizeof(float)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }
        close(file[1]);
    } else {
        close(file[1]);
        float result;

        if(read(file[0], &result, sizeof(float)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        } 
        close(file[0]);
        printf("Temperature in Fahrenheit : %.2f\n", result);
    }

    return 0;
}