#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

int main(int argc, char const *argv[])
{
    char arr[SIZE];
    while(1) {
        printf("Enter your Ethernet address of 12 Hexadecimal characters : ");
        scanf(" %[^\n]", arr);
        // int len = sizeof(arr)/sizeof(char);
        if(strlen(arr)==12){
            printf("Address successfully inserted, conversion on-progress.\n");
            break;
        } else {
            printf("Seems like your address is wrong, Try again.\n");
            continue;
        }
    }
    printf("Conversion ready :\n");
    for (int i = 0; i < 12; i++) {
        switch (arr[i])
        {
        case '0':
            printf("0000");
            break;
        case '1':
            printf("0001");
            break;
        case '2':
            printf("0010");
            break;
        case '3':
            printf("0011");
            break;
        case '4':
            printf("0100");
            break;
        case '5':
            printf("0101");
            break;
        case '6':
            printf("0110");
            break;
        case '7':
            printf("0111");
            break;
        case '8':
            printf("1000");
            break;
        case '9':
            printf("1001");
            break;
        case 'a':
        case 'A':
            printf("1010");
            break;
        case 'b':
        case 'B':
            printf("1011");
            break;
        case 'c':
        case 'C':
            printf("1100");
            break;
        case 'd':
        case 'D':
            printf("1101");
            break;
        case 'e':
        case 'E':
            printf("1110");
            break;
        case 'f':
        case 'F':
            printf("1111");
            break;
        default:
            printf("Ethernet address seems to contain non-hexadecimal character.\n");
            break;
        }
        printf(" ");
    }
    printf("\n");
    printf("White-spaces are provided for readibility\n");
    printf("Visit Again! (^.^)");
    
    return 0;
}