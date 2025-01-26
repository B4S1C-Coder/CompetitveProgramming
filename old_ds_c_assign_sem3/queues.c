// +----------------------------------------------------------------------+
// | Author: B4S1C-Coder                                                  |
// +----------------------------------------------------------------------+
// | Compiled via: gcc -o ./bin/queues -O3 -Wall queues.c && ./bin/queues |
// | ensure bin directory exists for above to work.                       |
// +----------------------------------------------------------------------+
// | gcc info: gcc version 11.4.0 (Ubuntu 11.4.0-1ubuntu1~22.04)          |
// +----------------------------------------------------------------------+
// | This code comes with ABSOLUTELY NO WARRANTY, to the extent permitted | 
// | by applicable law. The user bears the entire risk of running,        |
// | distributing and bearing any damages (if caused) by this code.       |
// +----------------------------------------------------------------------+

#include <stdio.h>
#include <stdlib.h>

// The static array implementation can have a maximum of 69 elements
#define QUEUE_STATIC_MAX_LEN 69

// This allows the queue to support more than one data-type whilst still
// being an Abstract Data Type since each queue will essentially contain
// the instances of the below union only.

// This would be used by the print function to accurately determine the
// actual data type of each element in the queue.
typedef enum dType {
    INT, FLOAT, CHAR, INTP, FLOATP, CHARP
} dType;

typedef struct queueData {
    union {
        int    dataI;   // Integer element
        float  dataF;   // Float element
        char   dataC;   // Char element
        int*   dataIP;  // Integer Pointer
        float* dataFP;  // Float Pointer
        char*  dataCP;  // Character Pointer
    };
    dType  dataTy;  // The data type used
} queueData;

typedef struct staticQueue {
    struct queueData staticArr[QUEUE_STATIC_MAX_LEN];
    int front;
    int rear;
} staticQueue;

// Operations on Static Queue
staticQueue init_staticQueue() {
    staticQueue queue;
    queue.front = -1;
    queue.rear = -1;
    return queue;
}

int enqueue_static(staticQueue* q, queueData data) {
    // Check if full
    if (q->rear == QUEUE_STATIC_MAX_LEN - 1) {
        printf("Overflow, operation rejected.\n");
        return -1;
    }

    // Check if empty
    if ((q->front == -1) || (q->front > q->rear)) {
        q->front = 0;
        q->staticArr[q->front] = data;
        q->rear = 0;
        return 0;
    }

    ++q->rear;
    q->staticArr[q->rear] = data;
    return 1;
}

queueData* dequeue_static(staticQueue* q) {
    queueData* qdp = NULL;
    // Check if empty
    if ((q->front == -1)||(q->front > q->rear)) {
        printf("Underflow, operation rejected.\n");
        return qdp;
    }

    qdp = &(q->staticArr[q->front]);
    q->front++;

    return qdp;
}

queueData* front_static(staticQueue* q) {
    queueData* qdp = ((q->front == -1) && (q->front > q->rear)) ? (NULL) : (&(q->staticArr[q->front]));
    return qdp;
}

void print_static(staticQueue* q) {
    printf("FRONT <- ");
    // Check if empty
    if ((q->front == -1)||(q->front > q->rear)) {
        printf("REAR\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        queueData data = q->staticArr[i];

        switch (data.dataTy) {
            case INT:
                printf("%d <- ", data.dataI);
                break;
            case FLOAT:
                printf("%f <- ", data.dataF);
                break;
            case CHAR:
                printf("%c <- ", data.dataC);
                break;
            case INTP:
                printf("%d <- ", *(data.dataIP));
                break;
            case FLOATP:
                printf("%f <- ", *(data.dataFP));
                break;
            case CHARP:
                printf("%p <- ", data.dataCP);
                break;
            default:
                printf("? <- ");
        }
    }
    printf("REAR\n");
}

int main() {
    
    // Create queue
    staticQueue queue = init_staticQueue();

    // Create data entries to be inserted
    queueData data1 = {.dataI = 69,    .dataTy = INT};
    queueData data2 = {.dataF = 42.69f, .dataTy = FLOAT};
    queueData data3 = {.dataC = 'X',   .dataTy = CHAR};
    
    // Add the fckers
    enqueue_static(&queue, data1);
    enqueue_static(&queue, data2);
    enqueue_static(&queue, data3);

    print_static(&queue);

    // Remove the fckers
    dequeue_static(&queue);
    dequeue_static(&queue);

    print_static(&queue);

    dequeue_static(&queue);

    // Trigger the underflow
    dequeue_static(&queue);

    // Print the empty queue (dry af)
    print_static(&queue);

    return 0;
}
