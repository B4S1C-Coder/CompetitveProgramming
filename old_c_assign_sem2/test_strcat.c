#include <stdio.h>
#include <string.h>

// Destination must already have enough memory to accomodate source string
int main() {
    char dest[] = "Hello, ";
    char src[] = "world!";

    strcat(dest, src);

    printf("%s\n", dest);
    return 0;
}

// OUTPUT of the above code:
// Hello, world!
// *** stack smashing detected ***: terminated
// Aborted (core dumped)