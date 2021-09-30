/*
8.  Input numbers 1 – 9 in any order and display the corresponding cardinality
    e.g. 2 (Input), Second (output)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int file[2], num, r_num, temp, count = 0;
    // char cardinals[9][15] = {
        // "First",
        // "Second",
        // "Third",
        // "Fourth",
        // "Fifth",
        // "Sixth",
        // "Seventh",
        // "Eighth",
        // "Nineth"
    // };

    //file[0] - read
    //file[1] - write
    if (pipe(file) == -1){
        printf("Error occured with pipe opening.\n");
        return 1;
    }
    int id = fork();

    wait(NULL);

    //check error while forking
    if (id == -1){
        printf("Error ocurred with fork.\n");
        return 2;
    }

    if(id == 0){
        close(file[0]);
        printf("Enter the Numbers (1-9) in any order : ");
        scanf("%d", &num);

        while(num != 0){
		    temp = num % 10;
		    num /= 10;
		    r_num = temp * 10 * count;
		    count++;
        }

        if((write((file[1]), r_num, sizeof(r_num))) == -1){
            printf("Error ocurred while writing.\n");
            return 3;
        }
        close(file[1]);
    } else {
        close(file[1]);
        read(file[0], r_num, sizeof(r_num));
        while(r_num != 0){
            num = r_num % 10;
            r_num /= 10;
            
            switch(num){
                case 1 :
                    printf("First\n");
                    break;
                case 2 :
                    printf("Second\n");
                    break;
                case 3 :
                    printf("Third\n");
                    break;
                case 4 :
                    printf("Fourth\n");
                    break;
                case 5 :
                    printf("Fifth\n");
                    break;
                case 6 :
                    printf("Sixth\n");
                    break;
                case 7 :
                    printf("Seventh\n");
                    break;
                case 8 :
                    printf("Eighth\n");
                    break;
                case 9 :
                    printf("Nineth\n");
                    break;
                default : printf("<--Invalid Input--->\n");
            }
        }
        close(file[0]);
    }
}
