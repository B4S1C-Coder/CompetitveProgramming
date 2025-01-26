#include <stdio.h>

void ques1_sayHello(const char* person) { printf("Hello, %s\n", person); }
int ques1_counta(const char* string, const int strSize) {
    int count = 0;
    int strLen = strSize / sizeof(char);
    for (int i = 0; i < strLen; i++) {
        if ((string[i] == 'a')||(string[i] == 'A')) {
            count++;
        }
    }
    return count;
}

float ques1_divide(float a, float b) { return a / b; }

void ques1() {
    char name[40];
    printf("Enter your name: ");
    fgets(name, 40, stdin);

    ques1_sayHello(name);
    int no_a = ques1_counta(name, sizeof(name));

    float result = ques1_divide(no_a, 69.42);

    printf("Count of a: %d\n", no_a);
    printf("Result: %f", result);
}

void ques2_meta() {
    static int insideQues2Meta = 74799292;
    printf("[META] %d\n", insideQues2Meta);
    insideQues2Meta++;
}

void ques2() {
    auto int ex1 = 69;
    register int ex69 = 420;
    printf("Outermost scope: %d %d\n", ex1, ex69);
    {
        {
            int ex1 = 42;
            printf("Inner most scope: %d %d\n", ex1, ex69);
        }
        printf("Inner Scope: %d %d\n", ex1, ex69);
    }
    printf("Outermost scope again: %d %d\n", ex1, ex69);
    for (int i = 0; i < 4; i++)
        ques2_meta();
}

void ques3_swapWithoutTemp(int *x, int *y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void ques3_swapWithTemp(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void ques3() {
    int a = 69, b = 42;
    printf("Before swap:\na = %d, b = %d\n", a, b);
    ques3_swapWithoutTemp(&a, &b);
    printf("After swap:\na = %d, b = %d\n", a, b);

    printf("Before another swap:\na = %d, b = %d\n", a, b);
    ques3_swapWithTemp(&a, &b);
    printf("After another swap:\na = %d, b = %d\n", a, b);
}

int factorialRecursive(int n) {
    if ((n == 1) || (n == 0)) {
        return 1;
    } else {
        return n*factorialRecursive(n - 1);
    }
}

int factorialNonRecursive(int n) {
    int fact = 1;

    for (int i = n; i > 0; i--) {
        fact = fact*i;
    }
    return fact;
}

void ques4() {
    int n = 4;
    printf("Factorial with recursion   : %d\n", factorialRecursive(4));
    printf("Factorial without recursion: %d\n", factorialNonRecursive(4));
}

int checkPrime(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i <= n/2; i++) {
        // printf("[ DEBUG ] %d mod %d = %d\n", n, i, n % i);
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void ques5() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int isPrime = checkPrime(n);

    if (isPrime) {
        printf("Prime Number!\n");
    } else {
        printf("Not a prime number!\n");
    }
}

void ques6() {
    int n, isPrime;
    printf("Enter limit: ");
    scanf("%d", &n);

    for (int i = 0; i < n + 1; i++) {
        isPrime = checkPrime(i);

        if (isPrime) {
            printf("%d\n", i);
        }
    }
}

int hcf(int x, int y) {
    // if (x < y) {
    //     for (int i = x; i >= 1; i--) {
    //         if ((x % i == 0) && (y % i == 0)) {
    //             return i;
    //         }
    //     }
    // } else if (x > y) {
    //     for (int i = y; i >= 1; i--) {
    //         if ((x % i == 0) && (y % i == 0)) {
    //             return i;
    //         }
    //     }
    // } else {
    //     // Both numbers are same, therefore hcf is the number itself
    //     return x;
    // }

    int min = (x < y) ? x : y;

    for (int i = min; i >= 1; i--) {
        if ((x % i == 0) && (y % i == 0)) {
            return i;
        }
    }
}

int lcm(int x, int y) {
    int max = (x > y) ? x : y;

    while (1) {
        if ((max % x == 0) && (max % y == 0)) {
            return max;
        }
        max++;
    }
}

void ques7() {
    int a = 12, b = 48;
    printf("HCF of %d and %d = %d\n", a, b, hcf(a, b));
}

void ques8() {
    int a = 15, b = 25;
    printf("LCM of %d and %d = %d\n", a, b, lcm(15, 25));
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int result = fibonacci(n - 1) + fibonacci(n - 2);
        return result;
    }
}

void ques9() {
    int n;
    printf("Enter number of terms of fibonacci series: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");
}

void ques10() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int sumOfDigits = 0;

    while (n > 0) {
        int digit = n % 10;
        sumOfDigits += digit;
        // Since n is an int, when we divide by 10 the last digit goes beyond
        // the decimal point and since n is an int on division, the decimal
        // part will be dropped from the result.
        n = n/10;
    }

    printf("Sum of digits: %d\n", sumOfDigits);
}



int main() {
    ques10();
    return 0;
}
