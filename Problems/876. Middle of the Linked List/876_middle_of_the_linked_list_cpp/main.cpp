#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* fast = head;

    while(fast && fast->next) {
        head = head->next;
        fast = fast->next->next;
    }

    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

void testMiddleNode(ListNode* head, ListNode* expected) {
    cout << "Input List: ";
    printList(head);

    cout << "Expected: ";
    printList(expected);

    cout << "Result: ";
    printList(middleNode(head));

    cout << endl;
}

int main() {
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(3)));
    ListNode* expected1 = new ListNode(2, new ListNode(3));
    testMiddleNode(list1, expected1);

    ListNode* list2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    ListNode* expected2 = new ListNode(3, new ListNode(4));
    testMiddleNode(list2, expected2);

    ListNode* list3 = new ListNode(1);
    ListNode* expected3 = new ListNode(1);
    testMiddleNode(list3, expected3);

    ListNode* list4 = new ListNode(1, new ListNode(2));
    ListNode* expected4 = new ListNode(2);
    testMiddleNode(list4, expected4);

    ListNode* list5 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* expected5 = new ListNode(3, new ListNode(4, new ListNode(5)));
    testMiddleNode(list5, expected5);

    return 0;
}
