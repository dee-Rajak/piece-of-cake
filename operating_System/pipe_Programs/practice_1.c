#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

    int id = fork();
    if (id != 0)
        fork();
    printf("Hello World !\n");

    // int id = fork();
    // printf("Hello World from ID : %d\n", id);

    // if (id == 0) {
        // printf("Hello from the Child process, with ID : %d\n", id);
    // } else {
        // printf("Hello from the Main process, with ID : %d\n", id);
    // }
    
    // int id = fork();
    // if (id != 0) {
        // fork();
    // }
    // printf("Hello my friened.\n");
    return 0;
}
