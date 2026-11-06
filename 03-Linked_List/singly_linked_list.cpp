
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int x) {
    Node* newNode = new Node{x, head};
    head = newNode;
}

void insertEnd(int x) {
    Node* newNode = new Node{x, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void deleteNode(int x) {
    if (head == NULL)
        return;

    if (head->data == x) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL &&
           temp->next->data != x)
        temp = temp->next;

    if (temp->next != NULL) {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

void search(int x) {
    Node* temp = head;
    int pos = 0;

    while (temp != NULL) {
        if (temp->data == x) {
            cout << "Found at position " << pos;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Not found";
}

void reverseList() {
    Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    display();

    insertBeginning(5);
    display();

    search(20);

    cout << "\nAfter deletion:\n";
    deleteNode(20);
    display();

    cout << "After reversing:\n";
    reverseList();
    display();

    return 0;
}
