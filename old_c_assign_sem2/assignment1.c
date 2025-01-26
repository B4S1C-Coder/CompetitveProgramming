// Example command for compilation:
// gcc -o ./bin/assignment1 assignment1.c -lm && ./bin/assignment1
// -lm flag required to link math library (libm.a)

#include <stdio.h>
#include <math.h>

void ques1() {
    printf("Hello, world!");
}

void ques2() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    printf("Received number: %d", x);
}

void ques3() {
    double x;
    float y;

    printf("Enter a double: ");
    scanf("%lf", &x);
    printf("Enter a float: ");
    scanf("%f", &y);
    printf("Received double: %lf\nReceived float: %f", x, y);
}

void ques4() {
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    printf("Received char: %c", c);
}


void ques5() {
    int n, d;
    printf("Enter numerator: ");
    scanf("%d", &n);
    printf("Enter denominator: ");
    scanf("%d", &d);
    printf("Fraction: (%d)/(%d)", n, d);
}

void ques6() {
    int x, y;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);

    printf("Sum x + y = %d\n", x + y);
    printf("Dif x - y = %d\n", x - y);
    printf("Mul x * y = %d\n", x * y);
    printf("Div x / y = %f\n", (float)(x)/(float)(y));
}

// compile with -lm flag
void ques7() {
    int a, n;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Specify n for n-th root of %d: ", a);
    scanf("%d", &n);
    printf("Result: %f", pow(a, (float)(1)/(float)(n)));
}

void ques8() {
    double r;
    printf("Enter radius: ");
    scanf("%lf", &r);
    printf("Area: %lf", M_PI*pow(r, 2));
}

void ques9() {
    double p,r,t;
    printf("Principal(assumed INR) Rate(in percentage) Time(in Years): ");
    scanf("%lf %lf %lf", &p, &r, &t);
    printf("Simple Interest: %lf", (p*r*t)/100);
}

void ques10() {
    double p,r,t;
    int n;
    printf("Principal(assumed INR) Rate(in percentage) Time(in Years) Number of times interest is compunded per year: ");
    scanf("%lf %lf %lf %d", &p, &r, &t, &n);
    printf("Coumpound Interest: %lf", p*pow(1 + (0.01*r)/(double)(n), (double)(n)*t) - p);
}

void ques11() {
    double basic;
    printf("Enter basic salary: ");
    scanf("%lf", &basic);
    printf("Gross Salary = %lf", basic + 0.1*basic + 0.12*basic);
}

int main() {
    ques11();
    return 0;
}
