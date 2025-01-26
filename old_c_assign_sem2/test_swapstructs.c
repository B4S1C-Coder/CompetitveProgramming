#include <stdio.h>

struct Rectangle {
    float length;
    float breadth;
};

void printRectangle(struct Rectangle* rect) {
    printf("Length: %f, Breadth: %f\n", rect->length, rect->breadth);
}

int main() {
    struct Rectangle rect1;
    rect1.length = 69;
    rect1.breadth = 42;
    
    printf("====[ Before Swap ]====\n");
    printf("First Rectangle: ");
    printRectangle(&rect1);

    struct Rectangle rect2;
    rect2.length = 52;
    rect2.breadth = 25;

    printf("Second Rectangle: ");
    printRectangle(&rect2);

    struct Rectangle temp;
    temp = rect1;
    rect1 = rect2;
    rect2 = temp;
    
    printf("====[ After Swap ]====\n");
    printf("First Rectangle: ");
    printRectangle(&rect1);

    printf("Second Rectangle: ");
    printRectangle(&rect2);

    printf("done\n");

    return 0;
}
