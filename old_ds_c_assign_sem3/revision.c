#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* init_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

typedef struct Stack {
    struct Node* bottom;
    struct Node* top;
    int numNodes;
} Stack;

Stack* init_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->bottom = NULL;
    stack->numNodes = 0;
    return stack;
}

bool isEmpty(Stack* stack) {
    return ((stack->top == NULL) && (stack->bottom == NULL) && (stack->numNodes == 0));
}

void push(Stack* stack, int data) {
    Node* node = init_node(data);
    
    if (isEmpty(stack)) {
        stack->bottom = node;
        stack->top = node;
        return;
    }

    stack->top->next = node;
    stack->top = node;

    stack->numNodes++;

    return;
}

Node* pop(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }

    // Stack has only one node
    if (stack->numNodes == 1) {
        stack->bottom = NULL;
        stack->top = NULL;
        stack->numNodes = 0;
        return NULL;
    }

    Node* temp = stack->top;
    stack->top = temp->next;
    stack->numNodes--;

    return temp;
}

int main() {
    Stack* myStack = init_stack();

    for (int i = 0; i < 5; i++) {
        push(myStack, i);
        printf("Pushed %d\n", i);
    }

    printf("Push success.\n");

    for (int j = 0; j < 5; j++) {
        printf("Popped %d\n", myStack->top->data);
        pop(myStack);
    }

    printf("Pop success.\n");
}
