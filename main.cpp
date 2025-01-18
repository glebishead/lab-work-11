#include <iostream>

bool hasThreeUniqueDigits(unsigned int n) {
    short ones = n % 10;
    short decades = n / 10 % 10;
    short hundreds = n / 100 % 10;
    if (ones != decades && ones != hundreds && 
        decades != hundreds && hundreds != 0) {
            return true;
    }
    return false;
}

bool hasOnlyEvenDigits(unsigned int n) {
    while (n != 0) {
        if ((n % 10) % 2 == 0) {
            n /= 10;
            continue;
        }
        return false;
    }
    return true;
}

bool hasOnlyOddDigits(unsigned int n) {
    while (n != 0) {
        if ((n % 10) % 2 == 1) {
            n /= 10;
            continue;
        }
        return false;
    }
    return true;
}

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

void sortNodes(Node* head) {
    // сортирует список по возрастанию
    for (Node* a = head->right; a != head; a = a->right) {
        for (Node* b = a->right; b != head; b = b->right) {
            if (a->value > b->value) {
                std::swap(a->value, b->value);
            }
        }
    }
}

bool isNodesSorted(Node* head) {
    Node* current = head->right;
    while (current->right != head->right) {
        if (current->value > current->right->value) {
            return false;
        }
        current = current->right;
    }
    return true;
}

void deleteNodesWithOnlyEvenDigits(Node* head) {
    Node* prev = head;
    Node* current = prev->right;
    while (current != head) {
        if (hasOnlyEvenDigits(current->value)) {
            prev->right = current->right;
            current->right->left = prev;
            delete current;
            current = prev->right;
        }
        else {
            prev = current;
            current = current->right;
        }
    }
}

void duplicateNodesWithOnlyOddDigits(Node* head) {
    Node* current = head->right;
    while (current != head) {
        if (hasOnlyOddDigits(current->value)) {
            Node* newNode = new Node;
            newNode->value = current->value;
            newNode->left = current;
            newNode->right = current->right;

            current->right->left = newNode;
            current->right = newNode;
            
            current = newNode->right;
        }
        else {
            current = current->right;
        }
    }
}

void deleteNodes(Node* head) {
    Node* current = head->right;
    Node* nextNode = current->right;
    while (current != head) {
        Node* nextNode = current->right;
        delete current;
        current = nextNode;
    }
    delete head;
}

int main() {
    Node* head = createHeadNode();
    bool condition = false;
    
    // 1 has number with three unique digits
    addRightNode(head, 513);

    // 2 has not
    addRightNode(head, 515);
    addRightNode(head, 242);
    addRightNode(head, 121);
    addRightNode(head, 1);
    addRightNode(head, 424);
    addRightNode(head, 646);
    addRightNode(head, 828);
    addRightNode(head, 442);
    addRightNode(head, 2);
    addRightNode(head, 3);
    addRightNode(head, 4);

    for (Node* current = head->right; current != head; current = current->right) {
        if (hasThreeUniqueDigits(current->value)) {
            condition = true;
            break;
        }
    }
    if (condition) {
        sortNodes(head);
    }
    else {
        deleteNodesWithOnlyEvenDigits(head);
        duplicateNodesWithOnlyOddDigits(head);
    }

    printNodes(head);
    deleteNodes(head);
    return 0;
}
