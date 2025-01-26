#include <stdio.h>
#include <math.h>

void ques1() {
	printf("sin(pi/6) = %lf\n", sin(M_PI/6));
	printf("log(100) = %lf\n", log(100));
	printf("cos(30) = %lf\n", cos(30));
	printf("sqrt(169) = %lf\n", sqrt(169));
}

// \b is backspace
void ques2() {
	printf("Line1\nLine2\tTabbed\bWhatstheB");
}

void ques3() {
	double a, b, c;
	printf("ax^2 + bx + c = 0\nSpecify a b c: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	double d = pow(b, 2) - 4*a*c;

	if (d >= 0) {
		double root1 = (-b + sqrt(d))/(2*a), root2 = (-b - sqrt(d))/(2*a);
		printf("Roots: %lf, %lf\n", root1, root2);
	} else {
		printf("The roots are complex, which are beyond the domain of this program");
	}
}

void ques4() {
	int x = 6;
	printf("%d += 9 => %d\n", x, x += 9);
	printf("%d -= 9 => %d\n", x, x -= 9);
	printf("%d *= 9 => %d\n", x, x *= 9);
	printf("%d /= 9 => %d\n", x, x /= 9);
	printf("%d %%= 9 => %d\n", x, x %= 9);
}

void ques5() {
	int x = 6, y = 9, temp;
	printf("BEFORE SWAP\nx = %d, y = %d\n", x, y);
	temp = x;
	x = y;
	y = temp;
	printf("AFTER SWAP\nx = %d, y = %d\n", x, y);
}

void ques6() {
	printf("7>>1 => %d\n", 7>>1);
	printf("7<<1 => %d\n", 7<<1);
}

void ques7() {
	int x;
	printf("Enter a number: ");
	scanf("%d", &x);

	// int isEven = (x % 2 == 0)?(isEven = 1):(isEven = 0);
	(x % 2 == 0)?(printf("The number is even.\n")):(printf("The number is odd.\n"));

	// printf("isEven = %d", isEven);
}

void ques8() {
	printf("sizeof(char) = %ld\n", sizeof(char));
	printf("sizeof(int) = %ld\n", sizeof(int));
	printf("sizeof(float) = %ld\n", sizeof(float));
	printf("sizeof(double) = %ld\n", sizeof(double));
	printf("sizeof(long int) = %ld\n", sizeof(long int));
}

void ques9() {
	int x = 69, y = 42;
	printf("Division Result - 1: %lf\n", (double)x/y);
	printf("Division Result - 2: %lf\n", (double)x/(double)y);
	printf("Division Result - 3: %lf\n", (double)(x/y));
}

void ques10() {
	char *s = "3.14159265";
	printf("float: %d\n", atof(s));
	printf("intgr: %d\n", atoi(s));
	printf("longi: %d\n", atol(s));

	// not supported by the compiler I'm using
	// itoa and ltoa are non-standard functions and
	// are not supported by every compiler

	// printf("strng: %s\n", itoa("3.69"));
	// printf("strng: %ld\n", ltoa("3.69"));
}

int main() {
	ques10();
	return 0;
}