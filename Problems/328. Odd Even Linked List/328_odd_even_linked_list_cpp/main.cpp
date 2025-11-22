#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
    ListNode* odd = new ListNode();
    ListNode* even = new ListNode();
    ListNode* oddTail = odd;
    ListNode* evenTail = even;

    while(head) {
        oddTail->next = head;
        head = head->next;
        oddTail = oddTail->next;
        oddTail->next = nullptr;

        if(head) {
            evenTail->next = head;
            head = head->next;
            evenTail = evenTail->next;
            evenTail->next = nullptr;
        }
    }

    if(odd->next) {
        oddTail->next = even->next;
    }

    return odd->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

void test(ListNode* head, ListNode* expected) {
    cout << "List: ";
    printList(head);

    cout << "Expected: ";
    printList(expected);

    cout << "Result: ";
    printList(oddEvenList(head));

    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    ListNode* expected1 = new ListNode(1);
    expected1->next = new ListNode(3);
    expected1->next->next = new ListNode(5);
    expected1->next->next->next = new ListNode(2);
    expected1->next->next->next->next = new ListNode(4);
    test(head1, expected1);

    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(5);
    head2->next->next->next->next = new ListNode(6);
    head2->next->next->next->next->next = new ListNode(4);
    head2->next->next->next->next->next->next = new ListNode(7);
    ListNode* expected2 = new ListNode(2);
    expected2->next = new ListNode(3);
    expected2->next->next = new ListNode(6);
    expected2->next->next->next = new ListNode(7);
    expected2->next->next->next->next = new ListNode(1);
    expected2->next->next->next->next->next = new ListNode(5);
    expected2->next->next->next->next->next->next = new ListNode(4);
    test(head2, expected2);

    ListNode* head3 = new ListNode(1);
    ListNode* expected3 = new ListNode(1);
    test(head3, expected3);

    ListNode* head4 = new ListNode(1);
    head4->next = new ListNode(2);
    ListNode* expected4 = new ListNode(1);
    expected4->next = new ListNode(2);
    test(head4, expected4);

    ListNode* head5 = new ListNode(10);
    head5->next = new ListNode(20);
    head5->next->next = new ListNode(30);
    head5->next->next->next = new ListNode(40);
    head5->next->next->next->next = new ListNode(50);
    head5->next->next->next->next->next = new ListNode(60);
    ListNode* expected5 = new ListNode(10);
    expected5->next = new ListNode(30);
    expected5->next->next = new ListNode(50);
    expected5->next->next->next = new ListNode(20);
    expected5->next->next->next->next = new ListNode(40);
    expected5->next->next->next->next->next = new ListNode(60);
    test(head5, expected5);

    ListNode* head6 = nullptr;
    ListNode* expected6 = nullptr;
    test(head6, expected6);

    return 0;
}
