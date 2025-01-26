#include <stdio.h>
// ++i will increment the value of i, and then return the incremented value.
// i++ will increment the value of i, but return the original value that i held before being incremented.
int main() {

    int a = 1, d = 1;
    int b, c;

    b = ++a; // 2 and a is also 2
    c = d++; // 1 and d is 2

    printf("b = %d, c = %d\n", b, c);

    // Either pre or post can be used in a loop
    int j = 0;
    for (int i = 0; i < 10; ++i) {
        printf("j = %d, i = %d\n", j, i);
        j++;
    }
    return 0;
}