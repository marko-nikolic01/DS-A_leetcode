#include <iostream>

using namespace std;

class Node {
    public:
        int val;
        Node* prev;
        Node* next;
        Node* child;
};

Node* flattenHelper(Node* head) {
    Node* tail = head->next;

    if(head->child) {
        head->next = head->child;
        head->child->prev = head;
        head->child = nullptr;
        head = flattenHelper(head->next);
    }

    if(tail) {
        head->next = tail;
        tail->prev = head;

        return flattenHelper(tail);
    }

    return head;
}

Node* flatten(Node* head) {
    if(head) {
        flattenHelper(head);
    }

    return head;
}

void printList(Node* head) {
    while(head) {
        cout << "[" << head->val << ", ";
        printList(head->child);
        cout << "]" << " -> ";
        head = head->next;
    }
    cout << "nullptr";
}

void test(Node* head, Node* expected) {
    cout << "List: ";
    printList(head);
    cout << endl;

    cout << "Expected: ";
    printList(expected);
    cout << endl;

    cout << "Result:   ";
    printList(flatten(head));
    cout << endl;

    cout << endl;
}

int main() {
    Node* head1 = new Node();
    head1->val = 1;
    head1->next = new Node();
    head1->next->val = 2;
    head1->next->prev = head1;
    head1->next->next = new Node();
    head1->next->next->val = 3;
    head1->next->next->prev = head1->next;
    head1->next->next->next = new Node();
    head1->next->next->next->val = 4;
    head1->next->next->next->prev = head1->next->next;
    head1->next->next->next->next = new Node();
    head1->next->next->next->next->val = 5;
    head1->next->next->next->next->prev = head1->next->next->next;
    head1->next->next->next->next->next = new Node();
    head1->next->next->next->next->next->val = 6;
    head1->next->next->next->next->next->prev = head1->next->next->next->next;
    head1->next->next->child = new Node();
    head1->next->next->child->val = 7;
    head1->next->next->child->next = new Node();
    head1->next->next->child->next->val = 8;
    head1->next->next->child->next->prev = head1->next->next->child;
    head1->next->next->child->next->next = new Node();
    head1->next->next->child->next->next->val = 9;
    head1->next->next->child->next->next->prev = head1->next->next->child->next;
    head1->next->next->child->next->next->next = new Node();
    head1->next->next->child->next->next->next->val = 10;
    head1->next->next->child->next->next->next->prev = head1->next->next->child->next->next;
    head1->next->next->child->next->child = new Node();
    head1->next->next->child->next->child->val = 11;
    head1->next->next->child->next->child->next = new Node();
    head1->next->next->child->next->child->next->val = 12;
    head1->next->next->child->next->child->next->prev = head1->next->next->child->next->child;
    Node* expected1 = new Node();
    expected1->val = 1;
    expected1->next = new Node();
    expected1->next->val = 2;
    expected1->next->prev = expected1;
    expected1->next->next = new Node();
    expected1->next->next->val = 3;
    expected1->next->next->prev = expected1->next;
    expected1->next->next->next = new Node();
    expected1->next->next->next->val = 7;
    expected1->next->next->next->prev = expected1->next->next;
    expected1->next->next->next->next = new Node();
    expected1->next->next->next->next->val = 8;
    expected1->next->next->next->next->prev = expected1->next->next->next;
    expected1->next->next->next->next->next = new Node();
    expected1->next->next->next->next->next->val = 11;
    expected1->next->next->next->next->next->prev = expected1->next->next->next->next;
    expected1->next->next->next->next->next->next = new Node();
    expected1->next->next->next->next->next->next->val = 12;
    expected1->next->next->next->next->next->next->prev = expected1->next->next->next->next->next;
    expected1->next->next->next->next->next->next->next = new Node();
    expected1->next->next->next->next->next->next->next->val = 9;
    expected1->next->next->next->next->next->next->next->prev = expected1->next->next->next->next->next->next;
    expected1->next->next->next->next->next->next->next->next = new Node();
    expected1->next->next->next->next->next->next->next->next->val = 10;
    expected1->next->next->next->next->next->next->next->next->prev = expected1->next->next->next->next->next->next->next;
    expected1->next->next->next->next->next->next->next->next->next = new Node();
    expected1->next->next->next->next->next->next->next->next->next->val = 4;
    expected1->next->next->next->next->next->next->next->next->next->prev = expected1->next->next->next->next->next->next->next->next;
    expected1->next->next->next->next->next->next->next->next->next->next = new Node();
    expected1->next->next->next->next->next->next->next->next->next->next->val = 5;
    expected1->next->next->next->next->next->next->next->next->next->next->prev = expected1->next->next->next->next->next->next->next->next->next;
    expected1->next->next->next->next->next->next->next->next->next->next->next = new Node();
    expected1->next->next->next->next->next->next->next->next->next->next->next->val = 6;
    expected1->next->next->next->next->next->next->next->next->next->next->next->prev = expected1->next->next->next->next->next->next->next->next->next->next;
    test(head1, expected1);

    Node* head2 = new Node();
    head2->val = 1;
    head2->next = new Node();
    head2->next->val = 2;
    head2->next->prev = head2;
    head2->child = new Node();
    head2->child->val = 3;
    Node* expected2 = new Node();
    expected2->val = 1;
    expected2->next = new Node();
    expected2->next->val = 3;
    expected2->next->prev = expected2;
    expected2->next->next = new Node();
    expected2->next->next->val = 2;
    expected2->next->next->prev = expected2->next;
    test(head2, expected2);

    Node* head3 = nullptr;
    Node* expected3 = nullptr;
    test(head3, expected3);

    Node* head4 = new Node();
    head4->val = 1;
    Node* expected4 = new Node();
    expected4->val = 1;
    test(head4, expected4);

    Node* head5 = new Node();
    head5->val = 1;
    head5->next = new Node();
    head5->next->val = 2;
    head5->next->prev = head5;
    head5->next->next = new Node();
    head5->next->next->val = 3;
    head5->next->next->prev = head5->next;
    head5->next->next->child = new Node();
    head5->next->next->child->val = 4;
    head5->next->next->child->next = new Node();
    head5->next->next->child->next->val = 5;
    head5->next->next->child->next->prev = head5->next->next->child;
    Node* expected5 = new Node();
    expected5->val = 1;
    expected5->next = new Node();
    expected5->next->val = 2;
    expected5->next->prev = expected5;
    expected5->next->next = new Node();
    expected5->next->next->val = 3;
    expected5->next->next->prev = expected5->next;
    expected5->next->next->next = new Node();
    expected5->next->next->next->val = 4;
    expected5->next->next->next->prev = expected5->next->next;
    expected5->next->next->next->next = new Node();
    expected5->next->next->next->next->val = 5;
    expected5->next->next->next->next->prev = expected5->next->next->next;
    test(head5, expected5);

    return 0;
}
