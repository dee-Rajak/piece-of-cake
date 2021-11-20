#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

int main(int argc, char const *argv[])
{
    char charArr[SIZE];
    int charArr_len;
    while(1){
        printf("You need to enter any word upto 10-alphabeths.\n");
        printf("Enter the word : ");
        scanf("%s", charArr);

        charArr_len = strlen(charArr);
        if(charArr_len>10){
            printf("Character limit exceeded !! TRY AGAIN.\n");
            continue;
        } else {
            break;
        }
    }

    char newCharArr[charArr_len];
    int countArr[charArr_len];
    int flag = 0;

    for (int i = 0; i < strlen(charArr); i++)
    {
        int check = 1;
        for (int j = 0; j < strlen(newCharArr); j++)
        {
            if(charArr[i]==newCharArr[j]){
                countArr[j]++;
                check = 0;
                break;
            }
        }
        if(check){
            newCharArr[flag] = charArr[i];
            countArr[flag] = 1;
            flag++;
        }
    }
    
    for (int i = 0; i < strlen(charArr); i++)
    {
        printf("%c", charArr[i]);
    }
    printf("\n");
    for (int i = 0; i < strlen(newCharArr); i++)
    {
        printf("%c\t%d\n", newCharArr[i], countArr[i]);
    }
    printf("\n");
      
    return 0;

}