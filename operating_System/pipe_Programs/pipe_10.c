/*
    Author  : Dhireen Kumar Rajak
    Year    : 2021
*/

/*
10.  Enter a word and display the word in reverse order.
*/

/*
    NOTE : Really nothing new here, just game of array. (You are just reversing it.)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>     //linux specific
#include <sys/wait.h>   //not necessary as I said before
#define SIZE 20

void reverse_string(char arr[]);

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
        
        char aArr[SIZE];

        printf("Enter a word : ");
        scanf("%[^\n]", aArr);

        //Writing in file and checking write-time-error
        if (write(file[1], &aArr, sizeof(aArr)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }

        //close the writing end
        close(file[1]);
    } else {
        //keep the writing end close
        close(file[1]);

        char bArr[SIZE];

        //Reading the file and checking read-time-error
        if(read(file[0], &bArr, sizeof(bArr)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        } 

        //reverse and print the string
        reverse_string(bArr);

        //close the reading end
        close(file[0]);
    }

    return 0;
}

void reverse_string(char arr[]){
    int len = strlen(arr);
    for(int i=0; i < len; i++, len--){
        char flag = arr[i];
        arr[i] = arr[len-1];
        arr[len -1] = flag;
    }
    printf("Reversed string is : ");
    puts(arr);
}