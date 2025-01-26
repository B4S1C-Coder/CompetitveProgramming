#include <stdlib.h>
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