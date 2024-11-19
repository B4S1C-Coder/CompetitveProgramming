#include <stdlib.h>

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
    Node* node = init_node(data);
    Node* temp = parent;    

    while ((temp->left != NULL) && (temp->right != NULL)) {
        if (temp->data == data) {
            free(node);
            return temp;
        } else if (temp->data > data) {
            if (temp->left == NULL) {
                temp->left = node;
                return node;
            }
            temp = temp->left;
            continue;
        } else if (temp->data < data) {
            if (temp->right == NULL) {
                temp->right = node;
                return node;
            }
            temp = temp->right;
            continue;
        }
    }

    if (temp->data < data) {
        temp->right = node;
    } else {
        temp->left = node;
    }

    return node;
}

int main() {

    int arr[9] = {8, 3, 1, 10, 6, 14, 4, 7, 13};

    Node* root = init_node(8);

    for (int i = 1; i < 10; i++) {
        insert(root, arr[i]);
    }

    return 0;
}
