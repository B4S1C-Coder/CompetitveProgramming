// ========== [ LAB ASSIGNMENT - 1 ] ==========
// +--------------------------+
// |  Name: SAKSHAM MITTAL    |
// |  Roll Number: 102319061  |
// +--------------------------+
// ============================================
// IMPORTANT
// --------------------------------------------
// Each function of the form:     void ass1qN_someName() { ... }
// is to be treated as an isolated container for Assignment - 1, Question - N.
// --------------------------------------------
// COMPILATION
// --------------------------------------------
// This code has been developed and tested with the following gcc version:
// gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
// --------------------------------------------
// The platform on which the code has been developed and tested:
// Linux 5.15.153.1-microsoft-standard-WSL2 #1 SMP Fri Mar 29 23:14:13 UTC 2024 x86_64 x86_64 x86_64 GNU/Linux

#include <stdio.h>
#include <math.h>

#define CONVERSION_FACTOR 1.609

void ass1q1_toKilometers() {
    printf("Ques - 1, Convert Miles to Kilometres\n");

    double driverFunction(double miles) { return miles * CONVERSION_FACTOR; }

    double miles;
    printf("Enter miles to convert> ");
    scanf("%lf", &miles);

    printf("%lf Kilometres\n", driverFunction(miles));
}

void ass1q2_countTokens() {

    printf("Ques - 2, Count Postive, Negative, Zeroes\n");

    void driverFunction(int* inputArr, int inputArrLen) {
        int positive = 0, negative = 0, zero = 0;

        for (int i = 0; i < inputArrLen; i++) {
            if (inputArr[i] > 0) {
                positive++;
            } else if (inputArr[i] < 0) {
                negative++;
            } else {
                zero++;
            }
        }

        printf("Number of Positive: %d\nNumber of Negative: %d\nNumber of Zeroes: %d\n", positive, negative, zero);
    }

    int inputSize;

    printf("Enter number of elements> ");
    scanf("%d", &inputSize);

    int dataArray[inputSize];

    for (int i = 0; i < inputSize; i++) {
        printf("Enter element (%d of %d)> ", i + 1, inputSize);
        scanf("%d", &dataArray[i]);
    }

    driverFunction(dataArray, inputSize);
} 

void ass1q3_computeTax() {

    printf("Ques - 3, Compute Tax\n");

    double driverFunction(double salary) {
	    double computedTax = -1.0;
	
	    if ((0.00 <= salary) && (salary <= 14999.99)) {
		    computedTax = 0.00 + (0.15 * salary);
	    } else if ((15000.00 <= salary) && (salary<= 29999.99)) {
		    computedTax = 2250.00 + (0.18 * (salary - 2250.00));
	    } else if ((30000.00 <= salary) && (salary <= 49999.99)) {
		    computedTax = 5400.00 + (0.22 * (salary - 5400.00));
	    } else if ((50000.00 <= salary) && (salary <= 79999.99)) {
		    computedTax = 11000.00 + (0.27 * (salary - 11000.00));
	    } else if ((80000.00 <= salary) && (salary <= 150000.00)) {
		    computedTax = 21600.00 + (0.33 * (salary - 21600.00));
	    }
	
	    return computedTax;
    }

    double salary;

    printf("Enter salary> ");
    scanf("%lf", &salary);

    printf("Computed Tax: %lf\n", driverFunction(salary));
}

void ass1q4_interactiveProgram() {

    printf("Ques - 4, Menue driven program\n");

	double areaCircle(double radius) { return (M_PI * radius * radius); }
	double perimeterCircle(double radius) { return (2.0 * M_PI * radius); }
	double areaRectangle(double a, double b) { return (a * b); }
	double perimeterRectangle(double a, double b) { return (2 * (a + b)); }
	
	short running = 1;
	
	while (running > 0) {
		printf("Choices are:\n1) Area of Circle\n2) Perimeter of Circle\n"
		"3) Area of Rectangle\n4) Perimeter of Circle\n5) Area of Square\n"
		"6) Perimeter of Square\n7) To quit\n");
		printf("Choice (1 to 7)> ");
		
		int choice;
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				printf("AREA OF CIRCLE\nEnter Radius> ");
				double radius;
				scanf("%lf", &radius);
				printf("Area: %lf square units", areaCircle(radius));
				break;
			case 2:
				printf("PERIMETER OF CIRCLE\nEnter Radius> ");
				double radius1;
				scanf("%lf", &radius1);
				printf("Area: %lf units", perimeterCircle(radius1));
				break;
			case 3:
				printf("AREA OF RECTANGLE\nEnter Length> ");
				double length, breadth;
				scanf("%lf", &length);
				printf("Enter Breadth> ");
				scanf("%lf", &breadth);
				printf("Area: %lf square units", areaRectangle(length, breadth));
				break;
			case 4:
				printf("PERIMETER OF RECTANGLE\nEnter Length> ");
				double length1, breadth1;
				scanf("%lf", &length1);
				printf("Enter Breadth> ");
				scanf("%lf", &breadth1);
				printf("Area: %lf units", perimeterRectangle(length1, breadth1));
				break;
			case 5:
				printf("AREA OF SQUARE\nEnter Side> ");
				double side;
				scanf("%lf", &side);
				printf("Area: %lf square units", areaRectangle(side, side));
				break;
			case 6:
				printf("PERIMETER OF SQUARE\nEnter Side> ");
				double side1;
				scanf("%lf", &side1);
				printf("Area: %lf units", perimeterRectangle(side1, side1));
				break;
			case 7:
				printf("Bye!\n");
				running = -69;
				break;
			default:
				printf("Invalid Choice\n");
		}
	}	
}

void ass1q5_fibonacciSeries() {

    printf("Ques - 5, Fibonaaci Series\n");

    int n;

    printf("Number of terms to print> ");
    scanf("%d", &n);

    int fibonacciDriver(int n){
	
	    if (n <= 1) {
		    return 1;
	    }
	
	    return fibonacciDriver(n - 2) + fibonacciDriver(n - 1);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacciDriver(i));
    }

    printf("\nEND\n");
}

void ass1q6_tableXtotableY() {
    printf("Ques - 6, Table X to Table Y\n");
    
    int x, y, temp;

    printf("Enter X> ");
    scanf("%d", &x);
    
    printf("Enter Y> ");
    scanf("%d", &y);

    // Swap x and y if y > x, in order for below loop to work
    if (y < x) {
        temp = x;
        x = y;
        y = temp;
    }
    
    for (int i = x; i <= y; i++) {
        printf("Table of %d:\n", i);

        for (int j = 1; j < 11; j++) {
            printf("%d X %d = %d\n", i, j, i*j);
        }
        printf("\n");
    }

}

void ass1q7_factorial() {

    printf("Ques - 7, Factorial (iterative)\n");

    int n;

    printf("Enter n> ");
    scanf("%d", &n);

    int factorial = 1;

    for (int i = 1; i <= n; i++) {
        factorial = factorial*i;
    }

    printf("%d! = %d\n", n, factorial);
}

void ass1q8_swapNums() {
    int x = 69, y = 42;
    printf("Ques - 8, Swap Numbers\n");
    printf("Before Swap: X = %d, Y = %d\n", x, y);

    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    swap(&x, &y);

    printf("After Swap: X = %d, Y = %d\n", x, y);
}

void ass1q9_firstInteger() {

    printf("Ques 9, First Integer\n");

    double n_min, n_max;

    printf("Enter n_min> ");
    scanf("%lf", &n_min);

    printf("Enter n_max> ");
    scanf("%lf", &n_max);

    if (n_min > n_max) {
        printf("n_min > n_max, these values will now be swapped\n");
        double temp = n_min;
        n_min = n_max;
        n_max = temp;
    }

    int firstInt = (int)n_min;

    if (n_min == n_max) {
        // Check if n_min (or n_max both equal) are actually integers
        if ((double)firstInt - n_min != 0.0) {
            printf("No integer in this range.\n");
        } else {
            printf("%d\n", firstInt);
        }
    } else {
        
        double diffL = (double)firstInt - n_min;
        double diffR = (double)firstInt - n_max;

        if ((diffL < 0.0)) {
            if (diffR <= -1.0) {
                firstInt++;
            } else {
                printf("No integer in this range.\n");
                return;
            }
        }
        
        if ((diffL > 0) && (diffR > 0)) {
            printf("No integer in this range.\n");
            return;
        }

        printf("%d\n", firstInt);
    }
}

void ass1q10_pattern() {

    printf("Ques - 10, Pattern\n");

    int n, i, j;
    printf("Enter n> ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Negative number! This would be converted to positive.\n");
        n = -n;
    }

    for (i = 0; i < n + 1; i++) {
        for (j = 0; j < i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    for (i = n + 1; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

int main() {
	printf("========= [ SAKSHAM MITTAL - 102319061 ] =========\n");
	ass1q1_toKilometers();
    ass1q2_countTokens();
    ass1q3_computeTax();
    ass1q4_interactiveProgram();
	ass1q5_fibonacciSeries();
    ass1q6_tableXtotableY();
    ass1q7_factorial();
    ass1q8_swapNums();
    ass1q9_firstInteger();
    ass1q10_pattern();
	return 0;
}
