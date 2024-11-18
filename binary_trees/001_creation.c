#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* init_node(int data) {
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

node* createTree_recursiveInput(node* parent) {
    printf("Enter data> ");
    
    int data;
    scanf("%d", &data);
    
    parent = init_node(data);

    if (data == -1) {
        return NULL;
    }

    printf("Left child of %d, ", data);
    parent->left = createTree_recursiveInput(parent->left);

    printf("Right child of %d, ", data);
    parent->right = createTree_recursiveInput(parent->right);

    return parent;
}

int main() {
    node* root = NULL;
    createTree_recursiveInput(root);
}
