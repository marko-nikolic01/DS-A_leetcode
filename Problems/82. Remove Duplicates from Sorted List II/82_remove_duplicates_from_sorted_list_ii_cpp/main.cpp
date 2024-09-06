#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head->next) {
        return head;
    }

    ListNode* start = new ListNode();
    ListNode* current = start;

    int count = 1;

    while(head->next) {
        if(head->val == head->next->val) {
            count++;
        } else {
            if(count == 1) {
                current->next = head;
                current = head;
            }
            count = 1;
        }

        head = head->next;
    }
    if(count == 1) {
        current->next = head;
        current = head;
    }
    current->next = nullptr;

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

void runTest(ListNode* head, const string& expected) {
    cout << "List: ";
    printList(head);

    cout << "Expected: " << expected << endl;

    cout << "Result: ";
    printList(deleteDuplicates(head));

    cout << endl;
}

int main() {
    ListNode* test1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, nullptr))));
    runTest(test1, "[1 -> 2 -> 3 -> 4]");

    ListNode* test2 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(3, nullptr))));
    runTest(test2, "[1 -> 3]");

    ListNode* test3 = new ListNode(2, new ListNode(2, new ListNode(2, new ListNode(2, nullptr))));
    runTest(test3, "[]");

    ListNode* test4 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, nullptr))))));
    runTest(test4, "[1 -> 4]");

    ListNode* test5 = new ListNode(1, nullptr);
    runTest(test5, "[1]");

    return 0;
}
