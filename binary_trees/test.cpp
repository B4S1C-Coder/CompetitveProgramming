#include <iostream>
#include <queue>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data, Node* left = nullptr,  Node* right = nullptr)
    : data(data), left(left), right(right) {};
};

Node* createTree(Node* parent) {
    std::cout << "Enter data> ";
    int data;
    std::cin >> data;

    parent = new Node(data);

    if (data == -1) {
        return nullptr;
    }

    std::cout << "Left child of " << data << std::endl;
    parent->left = createTree(parent->left);

    std::cout << "Right child of " << data << std::endl;
    parent->right = createTree(parent->right);

    return parent;
}

void levelOrderTraversal(Node* root) {
    std::queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node* temp = q.front();
        // std::cout << temp->data << " ";
        q.pop();

        if (temp == nullptr) {
            std::cout << std::endl;

            if (!q.empty()) {
                q.push(nullptr);
            }
        } else {
            std::cout << temp->data << " ";

            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    Node* root = nullptr;
    root = createTree(root);
    
    levelOrderTraversal(root);
    return 0;
}
