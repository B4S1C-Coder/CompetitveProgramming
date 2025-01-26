#include <stdio.h>
#include <stdlib.h>

void ques1() {
    int beautifulNumber = 69;
    float beautifulFloat = 42.69;
    char beautifulChar = 'X';

    printf("int -> value: %d, address: %p\n", beautifulNumber, &beautifulNumber);
    printf("float -> value: %f, address: %p\n", beautifulFloat, &beautifulFloat);
    printf("char -> value: %c, address: %p\n", beautifulChar, &beautifulChar);
}

void ques2() {
    int num = 69;
    printf("address printed via:\np: %p\nu: %u\nx: %x\n", &num, &num, &num);
}

void ques3() {
    int num = 69;
    float flt = 42.69;
    char chr = "X";

    int *numptr = &num;
    float *floatptr = &flt;
    char *charptr = &chr;

    printf("size ptr int = %ld, float = %ld, char = %ld\n", sizeof(numptr), sizeof(floatptr), sizeof(charptr));
}

void ques4() {
    int myArr[4] = {69, 42, 86};

    for (int i = 0; i < 4; i++) {
        printf("[ ADDRESS - %d ] %u\n", i, &myArr[i]);
    }
}

void swapInt(int *x, int *y) {
    *x = *x + *y;
    *x = *x - *y;
    *y = *x - *y;
}

void ques5() {
    int a = 69, b = 42;
    printf("Before, a = %d, b = %d\n", a, b);
    swapInt(&a, &b);
    printf("After, a = %d, b = %d\n", a, b);
}

float* scaleEachElement(int *arr, int numElements, float factor) {
    float *scaledArray = (float*)malloc(numElements*sizeof(float));

    for (int i = 0; i < numElements; i++) {
        scaledArray[i] = (float)arr[i] * factor;
    }

    return scaledArray;
}

void ques6() {
    int n;
    float scaleFactor;
    printf("Enter num of elements: ");
    scanf("%d", &n);

    printf("Enter scale factor (decimal): ");
    scanf("%f", &scaleFactor);

    int myArr[n];

    printf("Enter elements in space separated format: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &myArr[i]);
    }

    float* scaledMyArray = scaleEachElement(myArr, n, scaleFactor);

    printf("Scaled Array: ");
    for (int j = 0; j < n; j++) {
        printf("%f ", scaledMyArray[j]);
    }

    printf("\n");
}

void ques7() {
    int n = 10;
    float* mallocArray = (float*)malloc(n * sizeof(float));
    float* callocArray = (float*)calloc(n, sizeof(float));

    callocArray[0] = 69.96; callocArray[1] = 25.98;

    int i;
    printf("Malloc Array: ");
    for (i = 0; i < n; i++) {
        printf("%f ", mallocArray[i]);
    }
    
    printf("\nCalloc Array: ");
    for (i = 0; i < n; i++) {
        printf("%f ", callocArray[i]);
    }

    n = 2*n;
    callocArray = (float*)realloc(callocArray, n*sizeof(float));
    printf("\nAllocated more memory to callocArray.");

    printf("\nNew calloc array: ");
    for (i = 0; i < n; i++) {
        printf("%f ", callocArray[i]);
    }

    printf("\nFreeing memory ...");
    free(mallocArray);
    free(callocArray);
}

void ques8() {
    // ques7 and ques8 solutions have been merged into a single function i.e. ques7()
    ques7();
}

void strcpy_ownImplementation(char* destination, const char* source) {
    size_t i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    // Add a terminating character to end the string
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

    while ((string1[index] != '\0') && (string2[index] != '\0')) {
        difference = (int)string1[index] - (int)string2[index];
        index++;
    }

    return difference;
}

void ques9() {
    char dest[] = "Hello";
    char src[] = "melirjongwgn";
    strcpy_ownImplementation(dest, src);

    printf("%s\n", dest);
}

void ques10() {
    const char word[] = "UNIVERSITY";
    int wordLen = sizeof(word) / sizeof(char);

    int i, charsToPrint = 2;
    for (i = 0; i < wordLen; i++) {
        if (i == wordLen - 1) {
            break;
        }

        if (i < charsToPrint) {
            printf("%c", word[i]);
        }

        if (i == charsToPrint) {
            printf("\n");
            charsToPrint += 2;
            i = -1;
        }
    }

    charsToPrint = wordLen - 3;
    printf("\n");
    for (i = 0; i < wordLen; i++) {
        if (i < charsToPrint) {
            printf("%c", word[i]);
        }

        if (i == charsToPrint) {
            printf("\n");
            charsToPrint -= 2;
            i = -1;
        }
    }
}

void ques11() {
    char dest[15] = "Hello, ";
    char src[] = "world!";

    int cmpResult = strcmp_ownImplementation(dest, src);

    if (cmpResult != 0) {
        printf("Strings are not equal.\n");
    }

    strcat_ownImplementation(dest, src);

    char s1[] = "My";
    char s2[] = "My";

    int cmpResult2 = strcmp_ownImplementation(s1, s2);

    if (cmpResult2 != 0) {
        printf("Strings s1 and s2 are not equal.\n");
    } else {
        printf("Strings s1 and s2 are equal.\n");
    }

    printf("%s\n", dest);
}

// void ques12() {
//     char string[] = "Hello, world!";
//     // const long long vowelASCIIConst = (int)'a'*(int)'e'*(int)'i'*(int)'o'*(int)'u'*(int)'A'*(int)'E'*(int)'I'*(int)'O'*(int)'U';
//     const long long int vowelASCIIConst = 279726282108178425;
//     printf('%llld\n', vowelASCIIConst);

//     int index = 0, vowelCount = 0;

//     while (string[index] != '\0') {
//         if (vowelASCIIConst % (int)string[index] == 0) {
//             vowelCount++;
//         }
//     }

//     printf("%s has %d vowels", string, vowelCount);
// }

int main() {
    ques11();
    return 0;
}