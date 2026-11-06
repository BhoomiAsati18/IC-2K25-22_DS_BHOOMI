
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* head = NULL;

void insertEnd(int x) {
    Node* n = new Node{x, NULL, NULL};

    if (head == NULL) {
        head = n;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

void deleteNode(int x) {
    Node* temp = head;

    while (temp != NULL && temp->data != x)
        temp = temp->next;

    if (temp == NULL)
        return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL";
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    display();

    cout << "\nAfter deletion:\n";
    deleteNode(20);
    display();

    return 0;
}
