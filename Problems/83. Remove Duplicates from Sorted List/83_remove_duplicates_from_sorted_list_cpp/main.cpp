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
    if(head == nullptr) {
        return head;
    }

    ListNode* current = head;
    while(current->next != nullptr) {
        if(current->next->val == current->val) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }

    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next = new ListNode(4);

    cout << "Original list: ";
    printList(head);

    head = deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
