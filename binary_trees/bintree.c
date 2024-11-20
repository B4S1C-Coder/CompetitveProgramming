#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* init_node(int data) {
    Node* node  = (Node*)malloc(sizeof(Node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;

    return node;
}

Node* insert(Node* parent, int data) {
    if (parent == NULL) {
        return init_node(data);
    }

    Node* current = parent;

    while (1) {
        if (current->data == data) {
            return current;
        }

        if (data < current->data) {
            // We needed to go to the left child, but since there is no left child,
            // therefore the node should be inserted to the left of current node as
            // node to be inserted is smaller than current node.
            if (current->left == NULL) {
                current->left = init_node(data);
                return current->left;
            }

            current = current->left;
        } else {
            // We needed to go to the right child, but since there is no right child
            // therefore the node should be inserted to the right of current node as
            // node to be inserted is greater than current node.
            if (current->right == NULL) {
                current->right = init_node(data);
                return current->right;
            }
            current = current->right;
        }
    }
}

Node* createBST(int* arr, int size) {
    Node* root = init_node(arr[0]);
    
    for (int i = 1; i < size; i++) {
        insert(root, arr[i]);
    }

    return root;
}

void preOrder(Node* parent) {
    if (parent == NULL) { return; }
    printf("%d ", parent->data);
    preOrder(parent->left);
    preOrder(parent->right);
}

void inOrder(Node* parent) {
    if (parent == NULL) { return; }
    inOrder(parent->left);
    printf("%d ", parent->data);
    inOrder(parent->right);
}

void postOrder(Node* parent) {
    if (parent == NULL) { return; }
    postOrder(parent->left);
    postOrder(parent->right);
    printf("%d ", parent->data);
}

Node* removeNode(Node* root, int data) {
    Node* current = root;
    Node* prev = NULL;

    while(current != NULL) {
        prev = current;
        if (current->data == data) { break; }

        if (current->data < data) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    if (current == NULL) {
        printf("Value: '%d' not found in BST.\n", data);
        return root;
    }

    printf("[ DEBUG ] Node found.\n");

    // Node has no children
    if ((current->left == NULL) && (current->right == NULL)) {
        // Simply remove the current node from the BST
        prev->left = (prev->left->data == data) ? NULL : prev->left;
        prev->right = (prev->right->data == data) ? NULL : prev->right;
        return root;
    }

    printf("[ DEBUG ] Past the no child condition.\n");
    
    // Node has two children
    if ((current->left) && (current->right)) {
        // ...
    } else {
        // Node has one child
        printf("[ DEBUG ] Inside the one child condition.\n");
        // Determine and proceed if current node is left child or right child of prev node
        Node* childOfCurr = (current->left != NULL) ? current->left : current->right;
        printf("[ DEBUG ] Determined child node.\n");
        // Current node is left child of prev node
        if ((prev->left) && (prev->left->data == data)) {
            prev->left = childOfCurr;
        } else {
            // Current node is right child of prev node
            prev->right = childOfCurr;
        }
    }

    return root;

}

int main() {

    int arr[9] = {8, 3, 1, 10, 6, 14, 4, 7, 13};
    Node* root = createBST(arr, 9);

    printf("Before deletion INORDER: ");
    inOrder(root);
    root = removeNode(root, 10);
    printf("\nAfter deletion INORDER: ");
    inOrder(root);
    printf("\n");

    return 0;
}
