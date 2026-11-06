
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x) {
    Node* n = new Node{x, NULL};

    if (head == NULL) {
        head = n;
        n->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = n;
    n->next = head;
}

void deleteNode(int x) {
    if (head == NULL)
        return;

    Node *temp = head, *prev = NULL;

    do {
        if (temp->data == x) {
            if (temp == head && temp->next == head) {
                head = NULL;
            }
            else {
                if (temp == head) {
                    Node* last = head;

                    while (last->next != head)
                        last = last->next;

                    head = head->next;
                    last->next = head;
                }
                else {
                    prev->next = temp->next;
                }
            }

            delete temp;
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != head);
}

void display() {
    if (head == NULL)
        return;

    Node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(HEAD)\n";
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    display();

    deleteNode(20);
    display();

    return 0;
}
