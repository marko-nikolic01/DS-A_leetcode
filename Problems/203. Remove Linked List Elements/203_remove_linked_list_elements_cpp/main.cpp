#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* newHead = new ListNode();
    ListNode* current = newHead;

    while(head) {
        if(head->val != val) {
           current->next = new ListNode(head->val);
           current = current->next;
        }
        head = head->next;
    }

    return newHead->next;
}

void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    int val1 = 6;
    cout << "Test Case 1:\n";
    cout << "Original list: ";
    printList(list1);
    cout << "Value to remove: " << val1 << endl;
    ListNode* result1 = removeElements(list1, val1);
    cout << "New list: ";
    printList(result1);
    cout << endl;

    ListNode* list2 = new ListNode(1, new ListNode(2, new ListNode(3)));
    int val2 = 4;
    cout << "Test Case 2:\n";
    cout << "Original list: ";
    printList(list2);
    cout << "Value to remove: " << val2 << endl;
    ListNode* result2 = removeElements(list2, val2);
    cout << "New list: ";
    printList(result2);
    cout << endl;

    ListNode* list3 = new ListNode(7, new ListNode(7, new ListNode(7, new ListNode(7))));
    int val3 = 7;
    cout << "Test Case 3:\n";
    cout << "Original list: ";
    printList(list3);
    cout << "Value to remove: " << val3 << endl;
    ListNode* result3 = removeElements(list3, val3);
    cout << "New list: ";
    printList(result3);
    cout << endl;

    return 0;
}
