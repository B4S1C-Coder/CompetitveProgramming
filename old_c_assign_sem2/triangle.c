#include <stdio.h>

void bottomLeftTriangle(int n) {
    for (int i = 1; i <=n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void upperLeftTriangle(int n) {
    for (int i = n; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void lowerRightTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (n - i); j++) {
            printf("  ");
        }
        for (int k = 1; k <= i; k++) {
            printf("%d ", k);
        }
        printf("\n");        
    }
}

void upperRightTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            printf("  ");
        }
        for (int k = 1; k <= (n - i) + 1; k++) {
            printf("%d ", k);
        }
        printf("\n");
    }
}

int main() {
    // bottomLeftTriangle(7);
    // upperLeftTriangle(7);
    // lowerRightTriangle(7);
    upperRightTriangle(7);
    return 0;
}