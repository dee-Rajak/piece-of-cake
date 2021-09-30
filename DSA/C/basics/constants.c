/*
    Constants in C are,
        1. #define
        2. const
*/

/*
    simple #define
        #define PI 3.146734
        #define NAME Dhireen_Kumar_Rajak
        #define NAME "Dhireen Kumar Rajak"
    adv #define (first expansion, then evaluation)
        #define add(x, y) x+y
        #define greater(x, y) if(x>y) \
                                printf("%d is greater than %d\n", x, y); \
                              else \
                                printf("%d is greater than %d\n", y, x);
                                
*/
#include <stdio.h>
#define greater(x, y) if(x>y) \
                        printf("%d is greater than %d\n", x, y); \
                        else \
                        printf("%d is greater than %d\n", y, x);

int main(){
    greater(5, 6);
    return 0;
}