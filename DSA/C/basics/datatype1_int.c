#include <stdio.h>
#include <limits.h>

int main(){
    //signed integer (%d)
    int var1 = INT_MIN;
    int var2 = INT_MAX;
    //unsigned integer (%u)
    unsigned int var3 = 0;
    unsigned int var4 = UINT_MAX;
    //short signed integer (%d)
    short int var5 = SHRT_MIN;
    short int var6 = SHRT_MAX;
    //short unsigned integer (%u)
    short unsigned int var7 = 0;
    short unsigned int var8 = USHRT_MAX;
    //long signed integer (%ld)
    long int var9 = LONG_MIN;
    long int var10 = LONG_MAX;
    //long unsigned integer (%lu)
    long unsigned int var11 = 0;
    long unsigned int var12 = ULONG_MAX;
    //long long signed integer (%lld)
    long long int var13 = LLONG_MIN;
    long long int var14 = LLONG_MAX;
    //long long unsigned integer (%llu)
    long long unsigned int var15 = 0;
    long long unsigned int var16 = ULLONG_MAX;

    //print the ranges
    printf("Range of SIGNED INTEGER : %d to %d\n", var1, var2);
    printf("Range of UNSIGNED INTEGER : %u to %u\n", var3, var4);
    printf("Range of SHORT SIGNED INTEGER : %d to %d\n", var5, var6);
    printf("Range of SHORT UNSIGNED INTEGER : %u to %u\n", var7, var8);
    printf("Range of LONG SIGNED INTEGER : %ld to %ld\n", var9, var10);
    printf("Range of LONG UNSIGNED INTEGER : %lu to %lu\n", var11, var12);
    printf("Range of LONG LONG SIGNED INTEGER : %lld to %lld\n", var13, var14);
    printf("Range of LONG LONG UNSIGNED INTEGER : %llu to %llu\n", var15, var16);

    //What if we exceed the range
    printf("We are exceeding the range of SIGNED INTEGER (max : 2147483647)\n");
    printf("SIGNED INTEGER (2147483648) : %d\n", 2147483648);
    printf("SIGNED INTEGER (2147483649) : %d\n", 2147483649);
    printf("SIGNED INTEGER (2147483650) : %d\n", 2147483650);
    printf("We are exceeding the range of UNSIGNED INTEGER (max : 4294967295)\n");
    printf("UNSIGNED INTEGER (4294967296) : %u\n", 4294967296);
    printf("UNSIGNED INTEGER (4294967297) : %u\n", 4294967297);
    printf("UNSIGNED INTEGER (4294967298) : %u\n", 4294967298);

    //using sigeof()
    printf("%d", sizeof(int));
    printf("%d", sizeof(char));
    printf("%d", sizeof(float));
    printf("%d", sizeof(double));
    printf("%d", sizeof(long int));
    printf("%d", sizeof(long double));
    printf("%d", sizeof(short int));
    printf("%d", sizeof(unsigned int));

    /*
        Hex : %x    (0x<num>)
        Oct : %o    (0<num>)
        Dec : %d    (<num>)
    */
}