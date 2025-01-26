#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* prev;
    struct Node* children[2];
    int data;
} Node;

typedef struct BST {
    struct Node* root;
    int nodes;
} BST;

Node* init_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->prev = NULL;
    node->children[0] = NULL; // left child
    node->children[1] = NULL; // right child
    node->data = data;
    return node;
}

BST* init_bst(int data) {
    Node* node = init_node(data);
    BST* bst = (BST*)malloc(sizeof(BST));
    bst->root = node;
    bst->nodes = 1;
    return bst;
}

Node* locate_node(Node* node, int data) {
    if ((node == NULL) || (data == node->data)) {
        return node;
    }
    if (data < node->data) {
        return locate_node(node->children[0], data);
    } else {
        return locate_node(node->children[1], data);
    }
}

void insert_node(BST* bst, int data) {
    Node* new_node = init_node(data);
    if (bst->root == NULL) {
        bst->root = new_node;
        bst->nodes++;
        return;
    }

    Node* current = bst->root;
    while (1) {
        if (data < current->data) {
            if (current->children[0] == NULL) {
                current->children[0] = new_node;
                new_node->prev = current;
                bst->nodes++;
                return;
            }
            current = current->children[0];
        } else {
            if (current->children[1] == NULL) {
                current->children[1] = new_node;
                new_node->prev = current;
                bst->nodes++;
                return;
            }
            current = current->children[1];
        }
    }
}

Node* find_min(Node* node) {
    while (node->children[0] != NULL) {
        node = node->children[0];
    }
    return node;
}

void delete_node(BST* bst, int data) {
    Node* node = locate_node(bst->root, data);
    if (node == NULL) {
        printf("Node with value %d not found in the tree.\n", data);
        return;
    }

    // Case 1: Node has no children
    if (node->children[0] == NULL && node->children[1] == NULL) {
        if (node->prev->children[0] == node) {
            node->prev->children[0] = NULL;
        } else {
            node->prev->children[1] = NULL;
        }
        free(node);
        bst->nodes--;
    }
    // Case 2: Node has one child
    else if (node->children[0] == NULL || node->children[1] == NULL) {
        Node* child = (node->children[0] != NULL) ? node->children[0] : node->children[1];
        if (node->prev->children[0] == node) {
            node->prev->children[0] = child;
        } else {
            node->prev->children[1] = child;
        }
        child->prev = node->prev;
        free(node);
        bst->nodes--;
    }
    // Case 3: Node has two children
    else {
        Node* successor = find_min(node->children[1]);
        node->data = successor->data;
        if (successor->prev->children[0] == successor) {
            successor->prev->children[0] = successor->children[1];
        } else {
            successor->prev->children[1] = successor->children[1];
        }
        if (successor->children[1] != NULL) {
            successor->children[1]->prev = successor->prev;
        }
        free(successor);
        bst->nodes--;
    }
}

void inorder_traversal(Node* node) {
    if (node == NULL) {
        return;
    }
    inorder_traversal(node->children[0]);
    printf("%d ", node->data);
    inorder_traversal(node->children[1]);
}

void preorder_traversal(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    preorder_traversal(node->children[0]);
    preorder_traversal(node->children[1]);
}

void postorder_traversal(Node* node) {
    if (node == NULL) {
        return;
    }
    postorder_traversal(node->children[0]);
    postorder_traversal(node->children[1]);
    printf("%d ", node->data);
}

int main() {

    printf("SAKSHAM MITTAL, 102319061\n");
    printf("Assignment - 8, Binary Search Tree\n");

    BST* bst = init_bst(50);
    insert_node(bst, 30);
    insert_node(bst, 20);
    insert_node(bst, 40);
    insert_node(bst, 70);
    insert_node(bst, 60);
    insert_node(bst, 80);

    printf("In-order Traversal: ");
    inorder_traversal(bst->root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorder_traversal(bst->root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorder_traversal(bst->root);
    printf("\n");

    delete_node(bst, 20);
    delete_node(bst, 70);

    printf("In-order Traversal after deletions: ");
    inorder_traversal(bst->root);
    printf("\n");

    return 0;
}
