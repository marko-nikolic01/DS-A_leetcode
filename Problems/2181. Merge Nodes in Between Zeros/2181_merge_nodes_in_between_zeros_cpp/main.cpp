#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeNodes(ListNode* head) {
    ListNode* previousZero = head;
    ListNode* currentZero = head;

    ListNode* current = head->next;
    while(current) {
        if(current->val == 0) {
            currentZero->next = current;
            previousZero = currentZero;
            currentZero = current;
        } else {
            currentZero->val += current->val;
        }

        current = current->next;
    }
    previousZero->next = nullptr;

    return head;
}

void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

void printTestCase(ListNode* input, ListNode* expected) {
    cout << "List: ";
    printLinkedList(input);

    cout << "Expected: ";
    printLinkedList(expected);

    cout << "Result: ";
    printLinkedList(mergeNodes(input));

    cout << endl;
}

int main() {
    ListNode* input1 = new ListNode(0, new ListNode(1, new ListNode(2, new ListNode(0, new ListNode(3, new ListNode(4, new ListNode(0)))))));
    ListNode* expected1 = new ListNode(3, new ListNode(7));
    printTestCase(input1, expected1);

    ListNode* input2 = new ListNode(0, new ListNode(5, new ListNode(0, new ListNode(4, new ListNode(1, new ListNode(0))))));
    ListNode* expected2 = new ListNode(5, new ListNode(5));
    printTestCase(input2, expected2);

    ListNode* input3 = new ListNode(0, new ListNode(1, new ListNode(0)));
    ListNode* expected3 = new ListNode(1);
    printTestCase(input3, expected3);

    ListNode* input4 = new ListNode(0, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(0)))));
    ListNode* expected4 = new ListNode(9);
    printTestCase(input4, expected4);

    ListNode* input5 = new ListNode(0, new ListNode(2, new ListNode(0, new ListNode(6, new ListNode(7, new ListNode(0))))));
    ListNode* expected5 = new ListNode(2, new ListNode(13));
    printTestCase(input5, expected5);

    ListNode* input6 = new ListNode(0, new ListNode(1, new ListNode(0, new ListNode(4, new ListNode(5, new ListNode(0))))));
    ListNode* expected6 = new ListNode(1, new ListNode(9));
    printTestCase(input6, expected6);

    return 0;
}
