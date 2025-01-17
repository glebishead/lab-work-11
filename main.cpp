#include <iostream>

struct Node {
    // двусвязный список
    unsigned int value;
    Node* next = nullptr;
    Node* prev = nullptr;
};

void printNodes(Node* head) {
    // печатает узлы двусвязного списка
    Node* current = head->next;
    while (current != head) {
        std::cout << current->value << " ";
        current = current->next;
    }
}

void sortNodes(Node* head) {
    // сортирует список по возрастанию
    for (Node* a = head->next; a->next != head; a = a->next) {
        for (Node* b = a->next; b->next != head; b = b->next) {
            if (a->value > b->value) {
                std::swap(a->value, b->value);
            }
        }
    }
}

bool isNodesSorted(Node* head) {
    Node* current = head->next;
    while (current->next != head->next) {
        if (current->value > current->next->value) {
            return false;
        }
        current = current->next;
    }
    return true;
}

void duplicateDevidedByN(Node* head, int n) {
    Node* current = head->next;
    while (current != head) {
        if (current->value % n == 0) {
            Node* newNode = new Node;
            newNode->value = current->value;
            newNode->next = current->next;
            newNode->prev = current;

            current->next = newNode; // ссылка на следующий -> новый
            current->next->next->prev = newNode; // у узла через один от текущего предыдущий -> новый
            current = newNode->next;
        }
    }
}

void deleteNodes(Node* head) {
    Node* current = head;
    Node* nextNode = head->next;
    while (current != head) {
        /**/
    }
}

int main() {
    
    return 0;

}


