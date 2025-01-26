#include <stdio.h>
#include <string.h>

int main() {
    char myString[100];

    printf("Enter your string: ");
    fgets(myString, 100*sizeof(char), stdin);

        

    return 0;
}
