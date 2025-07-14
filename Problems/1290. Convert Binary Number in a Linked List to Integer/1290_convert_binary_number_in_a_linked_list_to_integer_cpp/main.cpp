#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getDecimalValue(ListNode* head) {
    int value = 0;
    short shift = 30;

    while(head) {
        if(head->val > 0) {
            value |= 1 << shift;
        }

        head = head->next;
        --shift;
    }

    return value >> ++shift;
}

void printList(ListNode* head) {
    while(head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

void test(ListNode* head, int expected) {
    cout << "List: ";
    printList(head);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << getDecimalValue(head) << endl;

    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(1, new ListNode(0, new ListNode(1)));
    test(head1, 5);

    ListNode* head2 = new ListNode(0);
    test(head2, 0);

    ListNode* head3 = new ListNode(1, new ListNode(1, new ListNode(1, new ListNode(1))));
    test(head3, 15);

    ListNode* head4 = new ListNode(1, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0)))));
    test(head4, 16);

    ListNode* head5 = new ListNode(1, new ListNode(0, new ListNode(1, new ListNode(1, new ListNode(0, new ListNode(1))))));
    test(head5, 45);

    return 0;
}
