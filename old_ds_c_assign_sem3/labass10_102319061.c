#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20

struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
};

int visited[MAX_NODES];
int graph[MAX_NODES][MAX_NODES];
int total_nodes;

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct Queue* q, int value) {
    if(q->rear == MAX_NODES-1) {
        printf("Queue is full!\n");
        return;
    }
    if(q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if(q->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    for(int i = 0; i < q->rear; i++) {
        q->items[i] = q->items[i+1];
    }
    q->rear--;
    if(q->rear == -1) {
        q->front = -1;
    }
    return item;
}

void createGraph() {
    printf("Enter number of nodes (max %d): ", MAX_NODES);
    scanf("%d", &total_nodes);
    
    printf("Enter adjacency matrix (1 if connected, 0 if not):\n");
    for(int i = 0; i < total_nodes; i++) {
        printf("Enter connections for node %d:\n", i);
        for(int j = 0; j < total_nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void BFS(int start_node) {
    struct Queue q;
    initQueue(&q);
    
    for(int i = 0; i < MAX_NODES; i++) {
        visited[i] = 0;
    }
    
    printf("BFS starting from node %d: ", start_node);
    printf("%d ", start_node);
    visited[start_node] = 1;
    enqueue(&q, start_node);
    
    while(q.front != -1) {
        int current = dequeue(&q);
        for(int i = 0; i < total_nodes; i++) {
            if(graph[current][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

void DFS(int node) {
    visited[node] = 1;
    printf("%d ", node);
    
    for(int i = 0; i < total_nodes; i++) {
        if(graph[node][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int choice, start_node;
    
    printf("SAKSHAM MITTAL, 102319061, GRAPH, DFS, BFS\n");
    createGraph();
    
    do {
        for(int i = 0; i < MAX_NODES; i++) {
            visited[i] = 0;
        }
        
        printf("\n1. Perform BFS");
        printf("\n2. Perform DFS");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter starting node (0 to %d): ", total_nodes-1);
                scanf("%d", &start_node);
                if(start_node >= 0 && start_node < total_nodes) {
                    BFS(start_node);
                } else {
                    printf("Invalid node!\n");
                }
                break;
                
            case 2:
                printf("\nEnter starting node (0 to %d): ", total_nodes-1);
                scanf("%d", &start_node);
                if(start_node >= 0 && start_node < total_nodes) {
                    printf("\nDFS starting from node %d: ", start_node);
                    DFS(start_node);
                    printf("\n");
                } else {
                    printf("Invalid node.\n");
                }
                break;
                
            case 3:
                printf("Bye!\n");
                break;
                
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 3);
    
    return 0;
}
