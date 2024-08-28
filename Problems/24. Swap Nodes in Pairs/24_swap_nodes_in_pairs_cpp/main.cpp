#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if(head && head->next) {
        ListNode* second = head->next;
        ListNode* third = head->next->next;

        head->next = swapPairs(third);
        second->next = head;

        head = second;
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

void runTest(ListNode* head) {
    cout << "List: ";
    printList(head);

    cout << "Result: ";
    printList(swapPairs(head));

    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    runTest(head1);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    runTest(head2);

    ListNode* head3 = new ListNode(1);
    runTest(head3);

    ListNode* head4 = new ListNode(1);
    head4->next = new ListNode(2);
    runTest(head4);

    ListNode* head5 = nullptr;
    runTest(head5);

    return 0;
}
