
#include <iostream>
using namespace std;

struct Node {
    int coeff, power;
    Node* next;
};

Node* insert(Node* head, int c, int p) {
    Node* n = new Node{c, p, NULL};

    if (head == NULL)
        return n;

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    return head;
}

Node* add(Node* a, Node* b) {
    Node* result = NULL;

    while (a != NULL && b != NULL) {
        if (a->power == b->power) {
            result = insert(result,
                a->coeff + b->coeff, a->power);
            a = a->next;
            b = b->next;
        }
        else if (a->power > b->power) {
            result = insert(result, a->coeff, a->power);
            a = a->next;
        }
        else {
            result = insert(result, b->coeff, b->power);
            b = b->next;
        }
    }

    while (a != NULL) {
        result = insert(result, a->coeff, a->power);
        a = a->next;
    }

    while (b != NULL) {
        result = insert(result, b->coeff, b->power);
        b = b->next;
    }

    return result;
}

void display(Node* p) {
    while (p != NULL) {
        cout << p->coeff << "x^" << p->power;

        if (p->next != NULL)
            cout << " + ";

        p = p->next;
    }
}

int main() {
    Node *p1 = NULL, *p2 = NULL;

    p1 = insert(p1, 5, 2);
    p1 = insert(p1, 3, 1);
    p1 = insert(p1, 2, 0);

    p2 = insert(p2, 4, 2);
    p2 = insert(p2, 2, 1);
    p2 = insert(p2, 1, 0);

    Node* result = add(p1, p2);

    cout << "Result: ";
    display(result);

    return 0;
}
