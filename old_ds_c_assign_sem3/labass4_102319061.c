// ========== [ LAB ASSIGNMENT - 4 ] ==========
// +--------------------------+
// |  Name: SAKSHAM MITTAL    |
// |  Roll Number: 102319061  |
// +--------------------------+
// ============================================
// IMPORTANT
// --------------------------------------------
// Each function of the form:     void container_ass4_quesN() { ... }
// is to be treated as an isolated container for Assignment - 4, Question - N.
// --------------------------------------------
// COMPILATION
// --------------------------------------------
// This code has been developed and tested with the following gcc version:
// gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
// --------------------------------------------
// COMMAND USED FOR COMPILATION (Make sure you have created a directory named bin before compiling)
// --------------------------------------------
// gcc -Wall labass4_102319061.c -O3 -o ./bin/labass4 && ./bin/labass4
// --------------------------------------------
// The platform on which the code has been developed and tested:
// Linux 5.15.153.1-microsoft-standard-WSL2 #1 SMP Fri Mar 29 23:14:13 UTC 2024 x86_64 x86_64 x86_64 GNU/Linux

// Used for compilation: gcc -Wall labass4_102319061.c -O3 -o ./bin/labass4 && ./bin/labass4

#include <string.h> // Used only for comparison between the two implementations
#include <stdio.h> // Used for printing in main() only
#include <stdlib.h>

size_t strlen_ownImplementation(char* string) {
    size_t length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}

void strcpy_ownImplementation(char* destination, const char* source) {
    size_t i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

void strcat_ownImplementation(char* destination, const char* source) {
    size_t destinationIndex = 0, sourceIndex = 0;
    while (destination[destinationIndex] != '\0') {
        destinationIndex++;
    }

    while (source[sourceIndex] != '\0') {
        destination[destinationIndex] = source[sourceIndex];
        destinationIndex++;
        sourceIndex++;
    }

    destination[destinationIndex] = '\0';
}

int strcmp_ownImplementation(const char* string1, const char* string2) {
    int difference = 0, index = 0;

    while ((string1[index] != '\0') || (string2[index] != '\0')) {
        difference = (int)(unsigned char)string1[index] - (int)(unsigned char)string2[index];
        if (difference != 0) {
            if (difference > 0) {
                return 1;
            } else if (difference < 0) {
                return -1;
            }
        }
        index++;
    }

    return 0;
}

void container_ass4_ques1() {
    printf("Question - 1, Implement strlen()\n");
    printf("Target: Find length of \"Hello, world!\"\n");
    printf("----------------------------------------\n");
    printf("Own Implementation: %ld\n", strlen_ownImplementation("Hello, world!"));
    printf("Std Implementation: %ld\n", strlen("Hello, world!"));
}

void container_ass4_ques2() {
    printf("Question - 2, Implement strcpy()\n");
    printf("Target: Copy contents of Buffer 1 to Buffer 2\n");
    printf("------------------BEFORE----------------\n");

    char* buffer2_own = (char*)malloc(14 * sizeof(char));
    char* buffer2_std = (char*)malloc(14 * sizeof(char));

    const char buffer1[] = "Hello, world!";

    printf("Buffer 1: %s\n", buffer1);

    printf("Buffer 2 for Own Implementation: %s\n", buffer2_own);
    printf("Buffer 2 for Std Implementation: %s\n", buffer2_std);

    printf("------------------AFTER----------------\n");

    strcpy_ownImplementation(buffer2_own, buffer1);
    strcpy(buffer2_std, buffer1);

    printf("Buffer 2 for Own Implementation: %s\n", buffer2_own);
    printf("Buffer 2 for Std Implementation: %s\n", buffer2_std);
}

void container_ass4_ques3() {
    printf("Question - 3, Implement strcat()\n");
    printf("Target: Append contents of Buffer 2 to Buffer 1\n");
    printf("------------------BEFORE----------------\n");

    char* buffer1_own = (char*)malloc(29 * sizeof(char));
    char* buffer1_std = (char*)malloc(29 * sizeof(char));

    // Replace with strcpy if you want to use the std implementation
    strcpy_ownImplementation(buffer1_own, "Hello, ");
    strcpy_ownImplementation(buffer1_std, "Hello, ");

    const char buffer2[] = "subject. How are you?";

    printf("Buffer 1 for Own Implementation: %s\n", buffer1_own);
    printf("Buffer 1 for Std Implementation: %s\n", buffer1_std);

    printf("Buffer 2: %s\n", buffer2);

    printf("------------------AFTER----------------\n");

    strcat_ownImplementation(buffer1_own, buffer2);
    strcat(buffer1_std, buffer2);

    printf("Buffer 1 for Own Implementation: %s\n", buffer1_own);
    printf("Buffer 1 for Std Implementation: %s\n", buffer1_std);
}

void container_ass4_ques4() {
    printf("Question - 4, Implement strcmp()\n");
    printf("Target: Compare strings \"Horn please, OK!\" & \"Horn OK, please!\"\n");
    printf("----------------------------------------\n");

    printf("Own Implementation result: %d\n", strcmp_ownImplementation("Horn please, OK!", "Horn OK, please!"));
    printf("Std Implementation result: %d\n", strcmp("Horn please, OK!", "Horn OK, please!"));
}

void container_ass4_ques5_and_ques6() {
    printf("Question - 5 and 6, Limitation of 2d char array and"
        " demostrate an array of Pointers to Strings.\n");
    printf("----------------------------------------\n");
    // Now in every row, you must have the same number of characters as the longest string.
    // This wastes memory as we are essentially allocating extra space for strings that are
    // smaller.
    char two2DCharArray[][69] = {
        "Hello, world!",
        "Something to put here.",
        "Some very extremely long this because of which we are wasting memory"
    };

    // Array of pointers to strings
    char** arrayOfPointersToStrings = (char**)malloc(3 * sizeof(char*));
    size_t totalMemoryUsed = 3 * sizeof(char*);  // Memory for the pointer array itself

    for (int i = 0; i < 3; i++) {
        arrayOfPointersToStrings[i] = two2DCharArray[i];
        totalMemoryUsed += strlen(arrayOfPointersToStrings[i]) + 1;  // +1 for null terminator
    }

    printf("Size occupied by two2DCharArray: %zu bytes\n", sizeof(two2DCharArray));
    printf("Size of pointer array: %zu bytes\n", 3 * sizeof(char*));
    printf("Actual memory used by arrayOfPointersToStrings: %zu bytes\n", totalMemoryUsed);
}

int main() {
    printf("========= [ SAKSHAM MITTAL - 102319061 ] =========\n");
    container_ass4_ques5_and_ques6();
    return 0;
}

