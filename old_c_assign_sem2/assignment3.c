// g++ -o ./bin/assignment3 assignment3.c -lm && ./bin/assignment3
#include <stdio.h>
#include <math.h>

void ques1() {
	char c;
	printf("Enter a character: ");
	scanf("%c", &c);

	if ((65 <= (int)c) && ((int)c <= 90)) {
		printf("Capital Letter\n");
	} else if ((97 <= (int)c) && ((int)c <= 122)) {
		printf("Small Letter\n");
	} else if ((48 <= (int)c) && ((int)c <= 57)) {
		printf("Digit\n");
	} else {
		printf("Special Character\n");
	}
}

void ques2() {
	double a, b, c, max;

	printf("Enter a b c: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	if (a > b) {
		max = a;
		if (a < c) {
			max = c;
		}
	} else {
		max = b;
		if (b < c) {
			max = c;
		}
	}

	printf("Greatest (if-else): %lf\n", max);

	max = (a > b)?((a < c)?(c):(a)):((b < c)?(c):(b));

	printf("Greatest (ternary op): %lf\n", max);
}

void ques3() {
	int x;
	printf("Enter a number: ");
	scanf("%d", &x);

	if (x % 2 == 0) {
		printf("Even\n");
	} else {
		printf("Odd\n");
	}

	if (x > 0) {
		printf("Positive\n");
	} else {
		printf("Negative\n");
	}

	(x % 2 == 0)?(printf("Even\n")):(printf("Odd\n"));
	(x > 0)?(printf("Positive\n")):(printf("Negative\n"));
}

void ques4() {
	int n;

	printf("Enter a number: ");
	scanf("%d", &n);

	(n % 5 == 0)?((n % 8 == 0)?(printf("divisible by both 5 and 8")):
		(printf("divisible by 5 but not 8"))):((n % 8 == 0)?
		(printf("divisible by 8 but not 5")):(printf("not divisible by both 5 and 8")));
}

void ques5() {
	int daysLate;

	printf("Enter the number of days book returned late: ");
	scanf("%d", &daysLate);

	if (daysLate == 0)
		printf("No fine.\n");
	else if ((0 < daysLate) && (daysLate <= 5))
		printf("Fine: 50 Paise.\n");
	else if ((6 <= daysLate) && (daysLate <= 10))
		printf("Fine: 1 Rupee.\n");
	else if (daysLate > 10) {
		printf("Fine: 5 Rupees.\n");
		if (daysLate > 30)
			printf("Membership cancelled.\n");
	} else
		printf("Invalid number of days.\n");
}

void ques6() {
	double num1, num2, result;
	char op;

	printf("Enter numbers num1 num2: ");
	scanf("%lf %lf", &num1, &num2);

	printf("Specify operation (+,-,*,/,%%): ");
	scanf(" %c", &op);

	switch(op) {
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			result = num1 / num2;
			break;
		case '%':
			result = (int)num1 % (int)num2;
			break;
		default:
			printf("Invalid operation\n");
	}

	printf("Result = %lf\n", result);
}

void ques7() {
	int monthNum;

	printf("Enter month number: ");
	scanf("%d", &monthNum);

	switch(monthNum) {
	case 1:
		printf("Jan");
		break;
	case 2:
		printf("Feb");
		break;
	case 3:
		printf("Mar");
		break;
	case 4:
		printf("Apr");
		break;
	case 5:
		printf("May");
		break;
	case 6:
		printf("Jun");
		break;
	case 7:
		printf("Jul");
		break;
	case 8:
		printf("Aug");
		break;
	case 9:
		printf("Sep");
		break;
	case 10:
		printf("Oct");
		break;
	case 11:
		printf("Nov");
		break;
	case 12:
		printf("Dec");
		break;
	default:
		printf("Invalid");
	}
}

void ques8() {
	double num1, num2, num3, num4, num5;

	printf("Enter 5 numbers: ");
	scanf("%lf %lf %lf %lf %lf", &num1, &num2, &num3, &num4, &num5);

	double average = (num1+num2+num3+num4+num5)/5;

	printf("average = %lf\n", average);

	double max1, overallMax, min1, overallMin;

	// computing max	
	max1 = (num1 > num2)?((num1 < num3)?(num3):(num1)):((num2 < num3)?(num3):(num2));
	overallMax = (max1 > num4)?((max1 < num5)?(num5):(max1)):((num4 < num5)?(num5):(num4));

	printf("Maximum = %lf\n", overallMax);

	// computing min
	min1 = (num1 > num2)?((num2 < num3)?(num2):(num3)):((num1 < num3)?(num1):(num3));
	overallMin = (min1 < num4)?((min1 < num5)?(min1):(num5)):((num4 < num5)?(num4):(num5));

	printf("Minimum = %lf\n", overallMin);

	// computing standard deviation
	double sd = pow(((pow(num1 - average, 2))+(pow(num2 - average,
		2))+(pow(num3 - average, 2))+(pow(num4 - average,
		2))+(pow(num5 - average, 2))/5, 2), 0.5);

	printf("Standard Deviation = %lf", sd);
}

int main() {
	ques8();
	return 0;
}