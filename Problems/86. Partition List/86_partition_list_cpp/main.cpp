#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode* startLess = new ListNode();
    ListNode* currentLess = startLess;

    ListNode* startGreater = new ListNode();
    ListNode* currentGreater = startGreater;

    while(head) {
        if(head->val < x) {
            currentLess->next = head;
            currentLess = currentLess->next;
        } else {
            currentGreater->next = head;
            currentGreater = currentGreater->next;
        }
        head = head->next;
    }

    currentLess->next = startGreater->next;
    currentGreater->next = nullptr;

    return startLess->next;
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

void runTest(ListNode* head, int x, const string& expected) {
    cout << "List: ";
    printList(head);

    cout << "x: " << x << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: ";
    printList(partition(head, x));

    cout << endl;
}

int main() {
    ListNode* test1 = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
    runTest(test1, 3, "[1 -> 2 -> 2 -> 4 -> 3 -> 5]");

    ListNode* test2 = new ListNode(1, new ListNode(2, new ListNode(1)));
    runTest(test2, 3, "[1 -> 2 -> 1]");

    ListNode* test3 = new ListNode(4, new ListNode(5, new ListNode(6)));
    runTest(test3, 3, "[4 -> 5 -> 6]");

    ListNode* test4 = new ListNode(5, new ListNode(2, new ListNode(2, new ListNode(5, new ListNode(7)))));
    runTest(test4, 5, "[2 -> 2 -> 5 -> 5 -> 7]");

    ListNode* test5 = new ListNode(1);
    runTest(test5, 2, "[1]");

    return 0;
}
