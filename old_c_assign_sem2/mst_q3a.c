/*
Author: Saksham Mittal
Version: 1.0.0

Swasth Raho, Sukhi Raho!
Hopefully, this solution will help you understand how to solve Q3 a) of MST 2024 EVEN SEM UES103.
If you wish to share/modify/redistribute this software, do give proper accreditation.

This code has been tested with the following compilers:
1) gcc version 11.4.0 (Ubuntu 11.4.0-1ubuntu1~22.04)

It is possible that some compilers might raise errors as they may expect constant values at compile
time. In such a case it is recommended to compile the program with a different compiler.

NOTE: Since this question was from MST, there were some boundations that I couldn't use dynamic
memory allocation through pointers. This is why the above problem exists (depends on compiler NOT the code).

There are ofcourse more efficient ways of doing this but for the current purpose I had to stay within the
said boundations.

To verify the integrity of the file you can calculate the sha512 checksum of this file, which is the same
as the file name (assuming that from wherever you got this file from, they haven't tampered with it).
*/

#include <stdio.h>

int main() {
    // Input the 2-D Array
    int numRows, numCols, i = 0, j = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &numRows);

    printf("Enter the number of cols: ");
    scanf("%d", &numCols);

    int myArr[numRows + 1][numCols];

    for (i = 0; i < numRows; i++) {
        printf("row> ");
        for (int j = 0; j < numCols; j++) {
            scanf("%d", &myArr[i][j]);
        }
    }

    for (j = 0; j < numCols; j++) {
        myArr[numRows][j] = 0;
    }
    
    int rowInsertIndex, colInsertIndex;
    printf("Enter row number to insert to (row nos start from 1): ");
    scanf("%d", &rowInsertIndex);
    rowInsertIndex--; // Get the actual row index

    printf("Enter col number to insert to (col nos start from 1): ");
    scanf("%d", &colInsertIndex);
    colInsertIndex--; // Get the actual col index

    // Check if rowInsertIndex and colInsertIndex are actually valid indices
    if ((rowInsertIndex < 0) || (rowInsertIndex >= numRows)) {
        printf("Invalid row index. Aborting ...");
        return 1;
    }

    if ((colInsertIndex < 0) || (colInsertIndex >= numRows)) {
       printf("Invalid col index. Aborting ...");
       return 1;
    }

    int elementToInsert;
    printf("Enter element to insert: ");
    scanf("%d", &elementToInsert);

    int currentRowIndex = numRows - 1, currentColIndex = numCols - 1;

    while (currentRowIndex >= rowInsertIndex) {
        // Edge case, handling the right most elements
        if (currentColIndex == numCols - 1) {
            myArr[currentRowIndex + 1][0] = myArr[currentRowIndex][currentColIndex];

            if ((currentRowIndex == rowInsertIndex) && (currentColIndex == colInsertIndex)) {
                myArr[currentRowIndex][currentColIndex] = elementToInsert;
                break;
            }

            currentColIndex--;
            continue;
        }
        // Standard Case
        myArr[currentRowIndex][currentColIndex + 1] = myArr[currentRowIndex][currentColIndex];

        if ((currentRowIndex == rowInsertIndex) && (currentColIndex == colInsertIndex)) {
            myArr[currentRowIndex][currentColIndex] = elementToInsert;
            break;
        }

        if (currentColIndex == 0) {
            currentColIndex = 2;
            currentRowIndex--;
            continue;
        }

        currentColIndex--;
    }

    // Print the matrix
    for (i = 0; i < numRows + 1; i++) {
        for (j = 0; j < numCols; j++) {
            printf("%d    ", myArr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
