#include <stdio.h>
#include <stdlib.h>

// Queue implementation via static array

#define ALLOWED_MAX_LEN 12

typedef struct staticArrayQueue {
   int staticArr[ALLOWED_MAX_LEN];
   int front;
   int rear;
} staticArrayQueue;

staticArrayQueue init_saq() {
    staticArrayQueue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

void enqueue_saq(staticArrayQueue* q, int data) {
    // Check if full
    if (q->rear == ALLOWED_MAX_LEN - 1) {
        printf("Overflow, enqueue rejected.\n");
        return;
    }
    
    // Check if empty
    if ((q->front == -1) || (q->rear < q->front)) {
        q->front = 0;
        q->staticArr[q->front] = data;
        q->rear = 0;
        return;
    }

    ++q->rear;
    q->staticArr[q->rear] = data;
}

int dequeue_saq(staticArrayQueue* q) {
    // Check if empty
    if ((q->front == -1) || (q->rear < q->front)) {
        printf("Underflow, dequeue rejected.\n");
        return -69;
    }

    return q->staticArr[q->front++];
}

void print_saq(staticArrayQueue* q) {
    printf("FRONT <- ");

    // Check if empty
    if ((q->front == -1) || (q->rear < q-> front)) {
        printf("REAR\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        printf("%d <- ", q->staticArr[i]);
    }

    printf("REAR\n");
}

void usage_saq() {
    staticArrayQueue myQueue = init_saq();
    printf("Ques - 1, Queue via Static Array\n-----------\n");
    
    printf("Operations:\n1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\n");
    int choice;

    while (1) {
        printf("Enter your choice> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int data;
                printf("Enter data (int) to enqueue> ");
                scanf("%d", &data);

                enqueue_saq(&myQueue, data);
                break;
            case 2:
                int poppedData = dequeue_saq(&myQueue);
                printf("Removed --> %d\n", poppedData);
                break;
            case 3:
                print_saq(&myQueue);
                break;
            case 4:
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

// Queue implementation via Linked Lists

typedef struct linkedListQueueNode {
    struct linkedListQueueNode* prev;
    struct linkedListQueueNode* next;
    int data;
} linkedListQueueNode;

linkedListQueueNode* createNode(int data) {
    linkedListQueueNode* np = (linkedListQueueNode*)malloc(sizeof(linkedListQueueNode));
    np->prev = NULL;
    np->next = NULL;
    np->data = data;

    return np;
}

typedef struct linkedListQueue {
    struct linkedListQueueNode* front;
    struct linkedListQueueNode* rear;
} linkedListQueue;

linkedListQueue init_llq() {
    linkedListQueue q;
    q.front = NULL;
    q.rear = NULL;
    return q;
}

unsigned char isEmpty_llq(linkedListQueue* q) {
    return ((q->front == NULL) || (q->rear == NULL));
}

void enqueue_llq(linkedListQueue* q, int data) {
    linkedListQueueNode* node = createNode(data);
    
    if (isEmpty_llq(q)) {
        q->front = node;
        q->rear = node;
        return;
    }

    node->prev = q->rear;
    q->rear->next = node;
    q->rear = node;
}

int dequeue_llq(linkedListQueue* q) {
    if (isEmpty_llq(q)) {
        return -69; // Nothing to do if queue is empty
    }

    linkedListQueueNode* temp = q->front;
    int data = temp->data;

    q->front = q->front->next;
    q->front->prev = NULL;
    
    free(temp);
    return data;
}

void print_llq(linkedListQueue* q) {
    printf("FRONT <- ");

    if (isEmpty_llq(q)) {
        printf("REAR\n");
        return;
    }

    linkedListQueueNode* currentNode = q->front;

    while (currentNode != NULL) {
        printf("%d <- ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("REAR\n");
}

void ass6_ques1() {
    linkedListQueue myQueue = init_llq();
    printf("Ques - 1, Queue via Linked List\n-----------\n");
    
    printf("Operations:\n1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\n");
    int choice;

    while (1) {
        printf("Enter your choice> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int data;
                printf("Enter data (int) to enqueue> ");
                scanf("%d", &data);

                enqueue_llq(&myQueue, data);
                break;
            case 2:
                int poppedData = dequeue_llq(&myQueue);
                printf("Removed --> %d\n", poppedData);
                break;
            case 3:
                print_llq(&myQueue);
                break;
            case 4:
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

typedef struct staticArrayCirclularQueue {
   int staticArr[ALLOWED_MAX_LEN];
   int front;
   int rear;
} staticArrayCirclularQueue;

staticArrayCirclularQueue init_sacq() {
    staticArrayCirclularQueue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

unsigned char isOverflow_sacq(staticArrayCirclularQueue* q) {
    // Queue is full when front is at index 0 and rear at last index
    // OR when front is at i+1 and rear at i
    return ((q->front == 0 && q->rear == ALLOWED_MAX_LEN - 1) ||
            (q->front == q->rear + 1));
}

unsigned char isUnderflow_sacq(staticArrayCirclularQueue* q) {
    return (q->front == -1);  // Queue is empty when front is -1
}

void enqueue_sacq(staticArrayCirclularQueue* q, int data) {
    if (isOverflow_sacq(q)) {
        printf("Overflow, enqueue rejected.\n");
        return;
    }
    
    if (q->front == -1) {  // First element
        q->front = 0;
        q->rear = 0;
    }
    else if (q->rear == ALLOWED_MAX_LEN - 1 && q->front != 0) {
        q->rear = 0;  // Wrap around
    }
    else {
        q->rear = (q->rear + 1) % ALLOWED_MAX_LEN;
    }
    
    q->staticArr[q->rear] = data;
}

int dequeue_sacq(staticArrayCirclularQueue* q) {
    if (isUnderflow_sacq(q)) {
        printf("Underflow, dequeue rejected.\n");
        return -69;
    }
    
    int data = q->staticArr[q->front];
    
    if (q->front == q->rear) {  // Last element
        q->front = -1;
        q->rear = -1;
    }
    else {
        q->front = (q->front + 1) % ALLOWED_MAX_LEN;
    }
    
    return data;
}

void print_sacq(staticArrayCirclularQueue* q) {
    if (isUnderflow_sacq(q)) {
        printf("=] FRONT <- REAR [= (Empty Queue)\n");
        return;
    }
    
    printf("=] FRONT <- ");
    int i = q->front;
    
    if (q->front <= q->rear) {
        while (i <= q->rear) {
            printf("%d <- ", q->staticArr[i]);
            i++;
        }
    }
    else {
        while (i < ALLOWED_MAX_LEN) {  // Print from front to end
            printf("%d <- ", q->staticArr[i]);
            i++;
        }
        i = 0;
        while (i <= q->rear) {  // Print from start to rear
            printf("%d <- ", q->staticArr[i]);
            i++;
        }
    }
    printf("REAR [=\n");
}

void ass6_ques2() {
    staticArrayCirclularQueue myQueue = init_sacq();
    printf("Ques - 2, Circular Queue via Static Array\n-----------\n");
    
    printf("Operations:\n1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\n");
    int choice;

    while (1) {
        printf("Enter your choice> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int data;
                printf("Enter data (int) to enqueue> ");
                scanf("%d", &data);

                enqueue_sacq(&myQueue, data);
                break;
            case 2:
                int poppedData = dequeue_sacq(&myQueue);
                printf("Removed --> %d\n", poppedData);
                break;
            case 3:
                print_sacq(&myQueue);
                break;
            case 4:
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}
int main() {
    printf("SAKSHAM MITTAL, 102319061\n-----------\n");
    ass6_ques2();
    return 0;
}
