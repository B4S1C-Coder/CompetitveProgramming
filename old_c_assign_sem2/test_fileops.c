// EXAMPLE COMMAND TO COMPILE AND RUN, ASSUMING COMPILER IS gcc
// Ensure that you run the program from the same directory as the executable

// COMMAND:
// gcc -Wall -Wextra -g -o ./bin/test_fileops test_fileops.c && cd bin/ && ./test_fileops && cd ..

// The below code and command expects a directory structure as:
/*
PROJECT_ROOT (COMMAND to be executed at PROJECT_ROOT level, compiles and runs the code)
|
+--assets
|       +--Story.txt
|
+--bin (to only run the code, you must navigate here and then simply call the name of the executable)
|    +-----test_fileops.exe (or whatever extension based on your OS)
|
+--test_fileops.c
*/

#include <stdio.h>
#include <string.h>

// define the paths relative to the executable
#if defined(_WIN32) || defined(_WIN64) || defined(__NT__)
    #define ASSETS_FOLDER_PATH "..\\assets\\"
    #define PATH_DELIMETER "\\"
    #define CURRENT_PLATFORM 1
#elif defined(__linux__) || defined(__APPLE__)
    #define ASSETS_FOLDER_PATH "../assets/"
    #define PATH_DELIMETER "/"
    #define CURRENT_PLATFORM 2
#else
    #define ASSETS_FOLDER_PATH ""
    #define PATH_DELIMETER ""
    #define CURRENT_PLATFORM 0
#endif

int checkIfSafeToExecute() {
    int safeToExecute = 0; // 0: unsafe, 1: safe

    switch (CURRENT_PLATFORM)
    {
    case 1:
        printf("Current Platform: Windows\n");
        safeToExecute = 1;
        break;

    case 2:
        printf("Current Platform: Linux or MacOS\n");
        safeToExecute = 1;
        break;
    
    default:
        printf("Current Platform: Unkown Platform\n");
        printf("Please define ASSETS_FOLDER_PATH and PATH_DELIMETER"
        "manually in the source code and compile again.\n");
        break;
    }

    return safeToExecute;
}

void test_LECTURE_CODE_UNSAFE_readFile_charBychar() {
    char filePath[256] = ASSETS_FOLDER_PATH;
    strcat(filePath, "Story.txt");

    printf("Reading: %s ...\n", filePath);

    FILE* myFile = fopen(filePath, "r");

    if (!myFile) {
        printf("Unable to open file.\n");
    }

    int currentChar;

    while (1) {
        currentChar = fgetc(myFile);
        if (currentChar == EOF) {
            break;
        }
        printf("%c", (char)currentChar);
    }

    fclose(myFile);
}

int main() {
    if (checkIfSafeToExecute() != 1) {
        printf("Program is unsafe to execute. Terminating...\n");
        return 1;
    }

    test_LECTURE_CODE_UNSAFE_readFile_charBychar();

    return 0;
}