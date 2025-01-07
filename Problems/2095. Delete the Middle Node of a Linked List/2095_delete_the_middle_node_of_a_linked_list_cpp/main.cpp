#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    head = new ListNode(0, head);
    ListNode* halfEnd = head;

    while(fast && fast->next) {
        halfEnd = slow;

        slow = slow->next;
        fast = fast->next->next;
    }

    halfEnd->next = slow->next;

    return head->next;
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
    printList(deleteMiddle(head));

    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(4);
    head1->next->next->next = new ListNode(7);
    head1->next->next->next->next = new ListNode(1);
    head1->next->next->next->next->next = new ListNode(2);
    head1->next->next->next->next->next->next = new ListNode(6);
    ListNode* expected1 = new ListNode(1);
    expected1->next = new ListNode(3);
    expected1->next->next = new ListNode(4);
    expected1->next->next->next = new ListNode(1);
    expected1->next->next->next->next = new ListNode(2);
    expected1->next->next->next->next->next = new ListNode(6);
    test(head1, expected1);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    ListNode* expected2 = new ListNode(1);
    expected2->next = new ListNode(2);
    expected2->next->next = new ListNode(4);
    test(head2, expected2);

    ListNode* head3 = new ListNode(2);
    head3->next = new ListNode(1);
    ListNode* expected3 = new ListNode(2);
    test(head3, expected3);

    ListNode* head4 = new ListNode(5);
    ListNode* expected4 = nullptr;
    test(head4, expected4);

    ListNode* head5 = new ListNode(1);
    head5->next = new ListNode(1);
    head5->next->next = new ListNode(1);
    head5->next->next->next = new ListNode(1);
    head5->next->next->next->next = new ListNode(1);
    ListNode* expected5 = new ListNode(1);
    expected5->next = new ListNode(1);
    expected5->next->next = new ListNode(1);
    expected5->next->next->next = new ListNode(1);
    test(head5, expected5);

    ListNode* head6 = new ListNode(1);
    head6->next = new ListNode(2);
    head6->next->next = new ListNode(3);
    head6->next->next->next = new ListNode(4);
    head6->next->next->next->next = new ListNode(5);
    head6->next->next->next->next->next = new ListNode(6);
    head6->next->next->next->next->next->next = new ListNode(7);
    head6->next->next->next->next->next->next->next = new ListNode(8);
    head6->next->next->next->next->next->next->next->next = new ListNode(9);
    ListNode* expected6 = new ListNode(1);
    expected6->next = new ListNode(2);
    expected6->next->next = new ListNode(3);
    expected6->next->next->next = new ListNode(4);
    expected6->next->next->next->next = new ListNode(6);
    expected6->next->next->next->next->next = new ListNode(7);
    expected6->next->next->next->next->next->next = new ListNode(8);
    expected6->next->next->next->next->next->next->next = new ListNode(9);
    test(head6, expected6);

    ListNode* head7 = new ListNode(100000);
    head7->next = new ListNode(99999);
    head7->next->next = new ListNode(88888);
    head7->next->next->next = new ListNode(77777);
    head7->next->next->next->next = new ListNode(66666);
    ListNode* expected7 = new ListNode(100000);
    expected7->next = new ListNode(99999);
    expected7->next->next = new ListNode(77777);
    expected7->next->next->next = new ListNode(66666);
    test(head7, expected7);

    ListNode* head8 = new ListNode(10);
    head8->next = new ListNode(10);
    head8->next->next = new ListNode(10);
    head8->next->next->next = new ListNode(10);
    head8->next->next->next->next = new ListNode(10);
    head8->next->next->next->next->next = new ListNode(10);
    ListNode* expected8 = new ListNode(10);
    expected8->next = new ListNode(10);
    expected8->next->next = new ListNode(10);
    expected8->next->next->next = new ListNode(10);
    expected8->next->next->next->next = new ListNode(10);
    test(head8, expected8);
}
