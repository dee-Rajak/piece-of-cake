#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
int main(int argc, char const *argv[])
{
    char arr[SIZE];
    printf("Enter a string : ");
    scanf("%[^\n]", arr);
    // gets(arr);
    
    printf("You entered : %s\n", arr);
    printf("String length is : %d\n", strlen(arr));
    reverse_string(arr);
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