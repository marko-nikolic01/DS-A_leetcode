#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

void printList(ListNode* head) {
    cout << "";
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

void test(ListNode* head, ListNode* node, ListNode* expected) {
    cout << "List: ";
    printList(head);

    cout << "Node: " << node->val << endl;

    cout << "Expected: ";
    printList(expected);

    deleteNode(node);
    cout << "Result: ";
    printList(head);

    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(4);
    head1->next = new ListNode(5);
    head1->next->next = new ListNode(1);
    head1->next->next->next = new ListNode(9);
    ListNode* expected1 = new ListNode(4);
    expected1->next = new ListNode(1);
    expected1->next->next = new ListNode(9);
    test(head1, head1->next, expected1);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    ListNode* expected2 = new ListNode(1);
    expected2->next = new ListNode(2);
    expected2->next->next = new ListNode(4);
    test(head2, head2->next->next, expected2);

    ListNode* head3 = new ListNode(7);
    head3->next = new ListNode(3);
    head3->next->next = new ListNode(5);
    head3->next->next->next = new ListNode(2);
    ListNode* expected3 = new ListNode(7);
    expected3->next = new ListNode(5);
    expected3->next->next = new ListNode(2);
    test(head3, head3->next, expected3);

    ListNode* head4 = new ListNode(6);
    head4->next = new ListNode(8);
    head4->next->next = new ListNode(10);
    head4->next->next->next = new ListNode(12);
    ListNode* expected4 = new ListNode(6);
    expected4->next = new ListNode(8);
    expected4->next->next = new ListNode(12);
    test(head4, head4->next->next, expected4);

    ListNode* head5 = new ListNode(9);
    head5->next = new ListNode(11);
    head5->next->next = new ListNode(13);
    head5->next->next->next = new ListNode(15);
    ListNode* expected5 = new ListNode(9);
    expected5->next = new ListNode(11);
    expected5->next->next = new ListNode(15);
    test(head5, head5->next->next, expected5);

    return 0;
}
