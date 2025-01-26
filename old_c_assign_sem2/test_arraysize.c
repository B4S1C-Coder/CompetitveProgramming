#include <stdio.h>

int main() {
    const char word[11] = "UNIVERSITY";
    int wordLen = sizeof(word) / sizeof(char);

    printf("%d\n", wordLen);

    return 0;
}