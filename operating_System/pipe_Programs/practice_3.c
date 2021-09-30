#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]){

    int id = fork();
    if (id == 0){
        // sleep(2);
        // printf("\n");
        printf("I am Child with Id : %d\t\t", id);
    } else {
        printf("I am Main with Id : %d\t", id);
    }

    printf("Current Process Id : %d\tParent Id : %d\n",
           getpid(), getppid());

    int res = wait(NULL);
    if (res == -1){
        printf("No child Process to wait for.\n");
    } else {
        printf("%d finished execution.\n", res);
    }
    return 0;
}