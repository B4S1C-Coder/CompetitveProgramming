#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void driverFunction() {
    FILE* myFile = fopen("marks500.txt", "r");

    int marks[500];
    int currentChar;
    int currentMarksIndex = 0;
    char marksStr[2];

    while (1) {
        currentChar = fgetc(myFile);

        if (currentChar == EOF) {
            break;
        }

        // encountered a tab
        if (currentChar == 9) {
            marksStr[0] = (char)fgetc(myFile);
            int nextChar = fgetc(myFile);

            if (nextChar == 0) {
                marks[currentMarksIndex] = atoi(marksStr);
                strcpy(marksStr, "");
                currentMarksIndex++;
                continue;
            } else {
                marksStr[1] = (char)nextChar;
                marks[currentMarksIndex] = atoi(marksStr);
                strcpy(marksStr, "");
                currentMarksIndex++;
                continue;
            }
        }
    }

    fclose(myFile);

    int max = 0;
    int min = 99999;

    int sum = 0;
    int passingMarks = 33;

    int topperIndex;
    int lastStIndex;

    printf("Failing students:\n");
    printf("ROLL | MARKS\n------------\n");
    for (int i = 0; i < 500; i++) {
        if (marks[i] > max) {
            max = marks[i];
            topperIndex = i;
        }
        if (marks[i] < min) {
            min = marks[i];
            lastStIndex = i;
        }

        if (marks[i] < passingMarks) {
            printf("%d | %d\n", 1000 + i + 1, marks[i]);
        }

        sum += marks[i];
    }

    printf("CLASS TOPPER --> Roll Number:  %d, Marks: %d\n", 1000 + topperIndex + 1, max);
    printf("CLASS FLUNKR --> Roll Number:  %d, Marks: %d\n", 1000 + lastStIndex + 1, min);

    double average = (double)sum / 500.0;
    printf("CLASS AVERAGE --> %lf\n", average);

    double standardDeviationSummation = 0;

    for (int j = 0; j < 500; j++) {
        standardDeviationSummation += pow((double)marks[j] - average, 2); 
    }

    double standardDeviation = pow(standardDeviationSummation / 500.0, 0.5);
    printf("STANDARD DEVIATION --> %lf\n", standardDeviation);

    FILE* outputFile = fopen("MarksStats.txt", "a");
    fprintf(outputFile, "%lf\n", average);
    fprintf(outputFile, "%lf\n", standardDeviation);
    fclose(outputFile);
}

int main() {
    driverFunction();
    return 0;
}