#include <stdio.h>

int main() {
    int integerType;
    double doubleType;
    char charType;

    printf("Size of int: %lu bytes\n", sizeof(integerType));
    printf("Size of double: %lu bytes\n", sizeof(doubleType));
    printf("Size of char: %lu bytes\n", sizeof(charType));

    int x = 1;
    printf("%d",x+sizeof(int));


    return 0;
}
