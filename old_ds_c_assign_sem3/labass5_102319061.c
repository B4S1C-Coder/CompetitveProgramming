// ========== [ LAB ASSIGNMENT - 5 ] ==========
// +--------------------------+
// |  Name: SAKSHAM MITTAL    |
// |  Roll Number: 102319061  |
// +--------------------------+
// ============================================
// IMPORTANT
// --------------------------------------------
// Each function of the form:     void container_ass5_quesN() { ... }
// is to be treated as an isolated container for Assignment - 5, Question - N.
// --------------------------------------------
// COMPILATION
// --------------------------------------------
// This code has been developed and tested with the following gcc version:
// gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
// --------------------------------------------
// COMMAND USED FOR COMPILATION (Make sure you have created a directory named bin before compiling)
// --------------------------------------------
// gcc -Wall -Wno-unused-result -O3 labass5_102319061.c -o ./bin/labass5 -lm && ./bin/labass5
// --------------------------------------------
// The platform on which the code has been developed and tested:
// Linux 5.15.153.1-microsoft-standard-WSL2 #1 SMP Fri Mar 29 23:14:13 UTC 2024 x86_64 x86_64 x86_64 GNU/Linux

// Used for compilation: gcc -Wall -Wno-unused-result -O3 labass5_102319061.c -o ./bin/labass5 -lm && ./bin/labass5

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

// ####### STACKS VIA ARRAY #######

typedef struct stackViaArray {
	int numElements;
	int* array;
	int maxElements;
	bool allowMaxBreach;
} stackViaArray;

stackViaArray* viaArray_createStack(int maxElements, bool allowMaxBreach) {
	stackViaArray* stack = (stackViaArray*)malloc(sizeof(stackViaArray));
	int* array = (int*)malloc(maxElements * sizeof(int));
	
	stack->allowMaxBreach = allowMaxBreach;
	stack->maxElements = maxElements;
	stack->numElements = 0;
	stack->array = array;
	
	return stack;
}

int viaArray_push(stackViaArray* stack, int element) {
	if ((stack->numElements >= stack->maxElements)&&(stack->allowMaxBreach != true)) {
		printf("Stack is full and breaching the limit is not allowed. Push rejected.\n");
		return -1;
	}
	
	if ((stack->numElements >= stack->maxElements)&&(stack->allowMaxBreach == true)) {
		printf("Reallocating array. Max limit breaching is allowed.\n");
		stack->array = (int*)realloc(stack->array, (stack->maxElements + 1)*sizeof(int));
		stack->array[stack->maxElements] = element;
		stack->numElements++;
		stack->maxElements++;
		return 1;
	}
	
	stack->array[stack->numElements] = element;
	stack->numElements++;
	return 1;
}

int viaArray_pop(stackViaArray* stack) {
	if (stack->numElements == 0) {
		printf("Empty stack nothing to pop.\n");
		return -1;
	}
	// There is no direct mechanism to remove the last element of array in C, so I have
    // decremented numElements, so this element would not be included when printing the
    // stack and would get overwritten on the next push.
    int toReturn = stack->array[stack->numElements];
	stack->numElements--;
	
	return toReturn;
}

void viaArray_display(stackViaArray* stack) {
	printf("TOP -> ");
	
	for (int i = stack->numElements - 1; i >= 0; i--) {
		printf("%d -> ", stack->array[i]);
	}
	
	printf(" BOTTOM\n");
}

void container_ass5_ques1() {
	printf("Question - 1,, Stack via Arrays\n");
	unsigned int maxElements;
	char ans;
	
	printf("Would you like to allow the stack to breach it's limit? (y/n) > ");
	scanf("%c", &ans);
	
	printf("Enter max size of stack> ");
	scanf("%u", &maxElements);
	
	
	bool allowLimitBreach = (ans == 'y') ? (true) : (false);
	
	stackViaArray* stack = viaArray_createStack(maxElements, allowLimitBreach);
	
	printf("Operations you can perform on the stack:\n1)Push\n2)Pop\n3)Display\n4)Exit\n");
	int choice, temp;
	
	while (1) {
		
		printf("Choice> ");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				printf("Enter element to push> ");
				scanf("%d", &temp);
				
				viaArray_push(stack, temp);
				viaArray_display(stack);
				break;
				
			case 2:
				viaArray_pop(stack);
				viaArray_display(stack);
				break;
			case 3:
				viaArray_display(stack);
				break;
			case 4:
				printf("Bye!\n");
				return;
			default:
				printf("Invalid choice.\n");
		}
	}
}

// ####### STACKS VIA SINGLY-LINKED-LIST #######

typedef struct node {
	struct node* next;
	int data;
} node;

typedef struct stackViaLinkedList {
	struct node* start;
	struct node* last;
	int numNodes;
} stackViaLinkedList;

node* viaLL_createNode(int data) {
	node* mNode = (node*)malloc(sizeof(node));
	mNode->next = NULL;
	mNode->data = data;

	return mNode;
}

stackViaLinkedList* viaLL_createStack() {
	stackViaLinkedList* stack = (stackViaLinkedList*)malloc(sizeof(stackViaLinkedList));

	stack->start = NULL;
	stack->last = NULL;
	stack->numNodes = 0;

	return stack;
}

node* viaLL_peek(stackViaLinkedList* stack) {
	return stack->last; 
}

void viaLL_push(stackViaLinkedList* stack, int data) {
	node* mNode = viaLL_createNode(data);

	if ((stack->start == NULL)||(stack->numNodes == 0)) {
		stack->start = mNode;
		stack->last = mNode;
		stack->numNodes++;

		return;
	}

	stack->last->next = mNode;
	stack->last = mNode;
	stack->numNodes++;
}

int viaLL_pop(stackViaLinkedList* stack) {
	if ((stack->start == NULL)||(stack->numNodes == 0)) { return -1; }

	node* nodeUnderConsideration = stack->start;
	node* prevNode = NULL;

	while (nodeUnderConsideration->next != NULL) {
		prevNode = nodeUnderConsideration;
		nodeUnderConsideration = nodeUnderConsideration->next;
	}

	// Only one node in the underlying linked list
	if (prevNode == NULL) {
		int data = stack->start->data;
		stack->start = NULL;
		stack->last = NULL;
		stack->numNodes = 0;

		return data;
	}

	int data = nodeUnderConsideration->data;

	stack->last = prevNode;
	prevNode->next = NULL;

	stack->numNodes--;

	return data;
}

void viaLL_display(stackViaLinkedList* stack) {
	printf("BOTTOM => ");

	node* nodeUnderConsideration = stack->start;
	while (nodeUnderConsideration->next != NULL) {
		printf("%d -> ", nodeUnderConsideration->data);
		nodeUnderConsideration = nodeUnderConsideration->next;
	}

	(nodeUnderConsideration != NULL) ? 
		printf("%d => TOP\n", nodeUnderConsideration->data) : printf(" => TOP\n");
}

void container_ass5_ques2() {
	stackViaLinkedList* stack = viaLL_createStack();

	printf("Available Operations are:\n1)Push\n2)Pop\n3)Display\n4)Exit\n");
	int choice;

	while (1) {
		printf("Enter your choice> ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter element to be pushed> ");
				int elem;
				scanf("%d", &elem);
				viaLL_push(stack, elem);
				viaLL_display(stack);
				break;
			case 2:
				viaLL_pop(stack);
				viaLL_display(stack);
				break;
			case 3:
				viaLL_display(stack);
				break;
			case 4:
				printf("Bye!\n");
				return;
			default:
				printf("Invalid choice.\n");
		}
	}
}

int getPrescedenceValue(char x) {
	switch (x) {
		case '^':
			return 100;
		case '/':
			return 90;
		case '*':
			return 90;
		case '+':
			return 80;
		case '-':
			return 80;
		default:
			return -1;
	}
}

void container_ass5_ques3() {
	printf("Question - 3, Infix to Postfix via Stack\n------------------\n");
	printf("Enter infix> ");
	char infix[100];
	fgets(infix, 100, stdin);

	stackViaLinkedList* stack = viaLL_createStack();

	for (int i = 0; infix[i] != '\0' && infix[i] != '\n'; i++) {
		// if (infix[i] == '\0') { break; }

		int tokenASCIIcode = (int)infix[i];

		// check for operator
		if (((42 <= tokenASCIIcode) && (tokenASCIIcode <= 47))||(tokenASCIIcode == 94)) {

			if ((stack->last) && (getPrescedenceValue((char)stack->last->data) >= getPrescedenceValue(infix[i]))) {
				printf("%c", (char)stack->last->data);
				viaLL_pop(stack);

				while ((stack->last) && (getPrescedenceValue((char)stack->last->data) >= getPrescedenceValue(infix[i]))) {
					printf("%c", (char)stack->last->data);
					viaLL_pop(stack);
				}

			}

			viaLL_push(stack, tokenASCIIcode);
			continue;
		}

		// check for (
		if (tokenASCIIcode == 40) {
			viaLL_push(stack, tokenASCIIcode);
			continue;
		}

		// check for )
		if (tokenASCIIcode == 41) {
			while ((stack->last) && (stack->last->data != 40)) {
				printf("%c", (char)stack->last->data);
				viaLL_pop(stack);
			}
			// Remove the (
			viaLL_pop(stack);
			continue;
		}

		printf("%c", infix[i]);
	}

	// Empty the stack
	while (stack->last) {
    	printf("%c", (char)stack->last->data);
    	viaLL_pop(stack);
	}

	printf("\n");
}

void container_ass5_ques4() {
    printf("Enter postfix> ");
    char postfix[100];
    fgets(postfix, 100, stdin);
    stackViaLinkedList* stack = viaLL_createStack();
    
    // Evaluate the postfix expression
    for (int i = 0; postfix[i] != '\0' && postfix[i] != '\n'; i++) {
        int tokenASCIIcode = (int)postfix[i];
        // Check for operator
        if (((42 <= tokenASCIIcode) && (tokenASCIIcode <= 47)) || (tokenASCIIcode == 94)) {
            if (stack->numNodes < 2) {
                printf("Error: Invalid postfix expression\n");
                return;
            }
            int operand2 = viaLL_pop(stack);
            int operand1 = viaLL_pop(stack);
            int result;
            switch (tokenASCIIcode) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        return;
                    }
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = pow(operand1, operand2);
                    break;
                default:
                    printf("Error: Unknown operator\n");
                    return;
            }
            viaLL_push(stack, result);
        }
        // If it's an operand, push it onto the stack
        else if (isdigit(postfix[i])) {
            viaLL_push(stack, postfix[i] - '0');
        }
        // If it's not an operator or operand, it's invalid
        else if (!isspace(postfix[i])) {
            printf("Error: Invalid character in expression\n");
            return;
        }
    }
    
    // Check if the expression was valid
    if (stack->numNodes != 1) {
        printf("Error: Invalid postfix expression\n");
    } else {
        printf("Result: %d\n", stack->last->data);
    }
    
    // Clean up the stack
    while (stack->numNodes > 0) {
        viaLL_pop(stack);
    }
    free(stack);
}

int main() {
	container_ass5_ques4();
	return 0;
}

int usage() {
	stackViaArray* stack = viaArray_createStack(3, true);
	
	for (int i = 0; i < 10; i++) {
		viaArray_push(stack, 100 + i);
	}
	
	viaArray_display(stack);
	
	for (int j = 0; j < 15; j++) {
		viaArray_pop(stack);
	}
	
	viaArray_display(stack);
	return 0;
}
