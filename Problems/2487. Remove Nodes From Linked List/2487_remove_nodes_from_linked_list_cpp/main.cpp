#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNodes(ListNode* head) {
    if(!head->next) {
        return head;
    }

    head->next = removeNodes(head->next);

    return head->val < head->next->val ? head->next : head;
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
    printList(removeNodes(head));

    cout << endl;
}


int main() {
    ListNode* head1 = new ListNode(5);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(13);
    head1->next->next->next = new ListNode(3);
    head1->next->next->next->next = new ListNode(8);
    ListNode* expected1 = new ListNode(13);
    expected1->next = new ListNode(8);
    test(head1, expected1);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(1);
    head2->next->next->next = new ListNode(1);
    ListNode* expected2 = new ListNode(1);
    expected2->next = new ListNode(1);
    expected2->next->next = new ListNode(1);
    expected2->next->next->next = new ListNode(1);
    test(head2, expected2);

    ListNode* head3 = new ListNode(3);
    head3->next = new ListNode(4);
    head3->next->next = new ListNode(2);
    head3->next->next->next = new ListNode(5);
    head3->next->next->next->next = new ListNode(1);
    ListNode* expected3 = new ListNode(5);
    expected3->next = new ListNode(1);
    test(head3, expected3);

    ListNode* head4 = new ListNode(10);
    ListNode* expected4 = new ListNode(10);
    test(head4, expected4);

    ListNode* head5 = new ListNode(7);
    head5->next = new ListNode(2);
    head5->next->next = new ListNode(5);
    head5->next->next->next = new ListNode(3);
    head5->next->next->next->next = new ListNode(6);
    ListNode* expected5 = new ListNode(7);
    expected5->next = new ListNode(6);
    test(head5, expected5);

    ListNode* head6 = new ListNode(1);
    head6->next = new ListNode(2);
    head6->next->next = new ListNode(3);
    head6->next->next->next = new ListNode(4);
    head6->next->next->next->next = new ListNode(5);
    ListNode* expected6 = new ListNode(5);
    test(head6, expected6);

    return 0;
}
