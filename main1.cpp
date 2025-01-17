#include <iostream>

struct Node {
    unsigned int value;
    Node* left;
    Node* right;
};

Node* createHeadNode() {
    Node* head = new Node;
    head->left = head;
    head->right = head;
    return head;
}

void addRightNode(Node* head, unsigned int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = head->left;
    newNode->right = head;

    head->left->right = newNode;
    head->left = newNode;
}

void printNodes(Node* head) {
    Node* current = head->right;
    while (current != head) {
        std::cout << current->value << " ";
        current = current->right;
    }
    std::cout << std::endl;
}

void deleteNodes(Node* head) {
    Node* current = head->right;
    Node* nextNode = current->right;
    while (current != head) {
        Node* nextNode = current->right;
        delete current;
        current = nextNode;
    }
    delete nextNode;
    delete head;
}

int main() {
    Node* head = createHeadNode();
    addRightNode(head, 1);
    addRightNode(head, 2);
    addRightNode(head, 3);

    printNodes(head);
    deleteNodes(head);
    return 0;
}
