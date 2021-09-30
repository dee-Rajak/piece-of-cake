#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
    int id = fork();
    int n;

    if (id == 0) {
        n = 1;
    } else {
        wait(NULL);
        n = 6;
    }
    int i;
    for ( i = n; i < n + 5; i++) {
        printf("%d ", i);
        fflush(stdout);
    }
    if (id != 0)
        printf("\n");
    return 0;
}
