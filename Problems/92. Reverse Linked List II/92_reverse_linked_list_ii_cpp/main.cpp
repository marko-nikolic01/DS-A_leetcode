#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(!head || left == right) {
        return head;
    }

    ListNode* start = new ListNode();
    ListNode* startCurrent = start;
    for(int i = 1; i < left; ++i) {
        startCurrent->next = head;
        startCurrent = startCurrent->next;
        head = head->next;
    }

    ListNode* reconnect = head;
    ListNode* previous = nullptr;
    for(int i = left; i <= right; ++i) {
        ListNode* temp = head->next;

        head->next = previous;
        previous = head;

        head = temp;
    }

    startCurrent->next = previous;
    reconnect->next = head;

    return start->next;
}

void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << "]" << endl;
}

void runTestCase(ListNode* head, int left, int right, const string& expected) {
    cout << "List: ";
    printList(head);

    cout << "Left: " << left << endl;

    cout << "Right: " << right << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: ";
    printList(reverseBetween(head, left, right));

    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    runTestCase(head1, 2, 4, "[1 -> 4 -> 3 -> 2 -> 5]");

    ListNode* head2 = new ListNode(1, new ListNode(2));
    runTestCase(head2, 1, 2, "[2 -> 1]");

    ListNode* head3 = new ListNode(1);
    runTestCase(head3, 1, 1, "[1]");

    ListNode* head4 = new ListNode(1, new ListNode(2, new ListNode(3)));
    runTestCase(head4, 2, 3, "[1 -> 3 -> 2]");

    return 0;
}
