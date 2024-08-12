#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head, ListNode* tail) {
    if(!head) {
        return tail;
    }

    ListNode* newHead = head->next;
    head->next = tail;

    return reverseList(newHead, head);
}

ListNode* reverseList(ListNode* head) {
    return reverseList(head, nullptr);
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(3)));
    cout << "Original list: ";
    printList(head1);

    ListNode* reversedHead1 = reverseList(head1);
    cout << "Reversed list: ";
    printList(reversedHead1);
    cout << "\n";

    ListNode* head2 = new ListNode(5, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(1)))));
    cout << "Original list: ";
    printList(head2);

    ListNode* reversedHead2 = reverseList(head2);
    cout << "Reversed list: ";
    printList(reversedHead2);
    cout << "\n";

    return 0;
}
