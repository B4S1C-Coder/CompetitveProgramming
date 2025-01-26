#include <stdio.h>
#include <string.h>
#include "string_functions_own_implemenations.c"

void ques1() {
    FILE* storyFile = fopen("assets/Story.txt", "r");

    if (storyFile == NULL) {
        printf("Couldn't open file.\n");
        return;
    }
    
    char currentChar;
    while (1) {
        currentChar = fgetc(storyFile);
        if (currentChar == EOF) {
            break;
        }
        printf("%c", currentChar);
    }
    fclose(storyFile);
}

void ques2() {
    FILE* storyFile = fopen("assets/Story.txt", "r");

    if (storyFile == NULL) {
        printf("Couldn't open file.\n");
        return;
    }

    char currentLine[256];
    while (fgets(currentLine, 256, storyFile) != NULL) {
        // Replace the last \n character with \0 strcspn will calculate the
        // number of charaters before the first occurrence of the speicfied character
        currentLine[strcspn(currentLine, "\n")] = '\0';
        printf("%s\n", currentLine);
    }
}

void ques3() {
    static char dest[10];
    static char src[6] = "abcdef";

    strcpy_ownImplementation(dest, src);

    printf("dest: %s\n", dest);
}

// ques4 is theoretical, just use:
// r+ : read and write, file must exist
// w+ : write and read, file will be created if it doesn't exist

void ques5() {
    FILE* storyFile = fopen("assets/Story.txt", "r");

    if (storyFile == NULL) {
        printf("Couldn't open file.\n");
        return;
    }

    // Determine the file size
    fseek(storyFile, 0, SEEK_END);
    int fileSize = ftell(storyFile);
    fseek(storyFile, 0, SEEK_SET);

    printf("File size in bytes: %d\n", fileSize);

    int i = 0, j = 0;
    char currentChar;
    while (i <= 10) {
        fseek(storyFile, i + j, SEEK_SET);

        currentChar = fgetc(storyFile);
        if (currentChar == EOF) {
            break;
        }

        printf("CHAR IS -> %c\n", currentChar);

        printf("%d\n", ftell(storyFile));
        i++;
        j = 2*SEEK_CUR + 1;
        printf("SEEK_CUR = %d\n", SEEK_CUR);
        printf("j = %d\n", j);
    }

    fclose(storyFile);
}

void ques6() {
    FILE* storyFile = fopen("assets/Story.txt", "r");

    if (storyFile == NULL) {
        printf("Couldn't open file.\n");
        return;
    }

    // Determine the number of characters
    fseek(storyFile, 0, SEEK_END);
    int fileLength = ftell(storyFile);
    fseek(storyFile, 0, SEEK_SET);

    printf("Number of characters in file: %d\n", fileLength);

    int wordCount = 0;
    int lineCount = 0;
    int sentenceCount = 0;
    char currentWord[25];

    while (fscanf(storyFile, "%s", currentWord) == 1) {
        fscanf(storyFile, "%s", currentWord);
        wordCount++;

        if (strcspn(currentWord, "\n") != strlen(currentWord)) {
            lineCount++;
        }

        if ((strcspn(currentWord, ".") != strlen(currentWord))||
            (strcspn(currentWord, "!") != strlen(currentWord))||
            (strcspn(currentWord, "?") != strlen(currentWord))) {
            sentenceCount++;
        }
    }

    printf("Words: %d\n", wordCount);
    printf("Lines: %d\n", lineCount);
    printf("Sentences: %d\n", sentenceCount);
}

int main() {
    ques6();
    return 0;
}
