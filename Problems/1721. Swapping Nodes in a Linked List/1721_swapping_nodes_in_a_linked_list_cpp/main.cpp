#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapNodes(ListNode* head, int k) {
    ListNode* node;

    ListNode* current = head;
    int n = 0;
    while(n < k - 1) {
        ++n;
        current = current->next;
    }
    node = current;

    current = current->next;
    while(current) {
        ++n;
        current = current->next;
    }

    n -= k;
    current = head;
    while(n > -1) {
        --n;
        current = current->next;
    }

    n = node->val;
    node->val = current->val;
    current->val = n;

    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

void test(ListNode* head, int k, ListNode* expected) {
    cout << "List: ";
    printList(head);

    cout << "k: " << k << endl;

    cout << "Expected: ";
    printList(expected);

    cout << "Result: ";
    printList(swapNodes(head, k));

    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    ListNode* expected1 = new ListNode(1);
    expected1->next = new ListNode(4);
    expected1->next->next = new ListNode(3);
    expected1->next->next->next = new ListNode(2);
    expected1->next->next->next->next = new ListNode(5);
    test(head1, 2, expected1);

    ListNode* head2 = new ListNode(7);
    head2->next = new ListNode(9);
    head2->next->next = new ListNode(6);
    head2->next->next->next = new ListNode(6);
    head2->next->next->next->next = new ListNode(7);
    head2->next->next->next->next->next = new ListNode(8);
    head2->next->next->next->next->next->next = new ListNode(3);
    head2->next->next->next->next->next->next->next = new ListNode(0);
    head2->next->next->next->next->next->next->next->next = new ListNode(9);
    head2->next->next->next->next->next->next->next->next->next = new ListNode(5);
    ListNode* expected2 = new ListNode(7);
    expected2->next = new ListNode(9);
    expected2->next->next = new ListNode(6);
    expected2->next->next->next = new ListNode(6);
    expected2->next->next->next->next = new ListNode(8);
    expected2->next->next->next->next->next = new ListNode(7);
    expected2->next->next->next->next->next->next = new ListNode(3);
    expected2->next->next->next->next->next->next->next = new ListNode(0);
    expected2->next->next->next->next->next->next->next->next = new ListNode(9);
    expected2->next->next->next->next->next->next->next->next->next = new ListNode(5);
    test(head2, 5, expected2);

    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    head3->next->next = new ListNode(3);
    head3->next->next->next = new ListNode(4);
    head3->next->next->next->next = new ListNode(5);
    ListNode* expected3 = new ListNode(5);
    expected3->next = new ListNode(2);
    expected3->next->next = new ListNode(3);
    expected3->next->next->next = new ListNode(4);
    expected3->next->next->next->next = new ListNode(1);
    test(head3, 1, expected3);

    ListNode* head4 = new ListNode(10);
    head4->next = new ListNode(20);
    head4->next->next = new ListNode(30);
    head4->next->next->next = new ListNode(40);
    head4->next->next->next->next = new ListNode(50);
    ListNode* expected4 = new ListNode(10);
    expected4->next = new ListNode(20);
    expected4->next->next = new ListNode(30);
    expected4->next->next->next = new ListNode(40);
    expected4->next->next->next->next = new ListNode(50);
    test(head4, 3, expected4);

    ListNode* head5 = new ListNode(2);
    head5->next = new ListNode(4);
    head5->next->next = new ListNode(6);
    head5->next->next->next = new ListNode(8);
    head5->next->next->next->next = new ListNode(10);
    head5->next->next->next->next->next = new ListNode(12);
    ListNode* expected5 = new ListNode(2);
    expected5->next = new ListNode(4);
    expected5->next->next = new ListNode(8);
    expected5->next->next->next = new ListNode(6);
    expected5->next->next->next->next = new ListNode(10);
    expected5->next->next->next->next->next = new ListNode(12);
    test(head5, 4, expected5);

    ListNode* head6 = new ListNode(1);
    head6->next = new ListNode(2);
    ListNode* expected6 = new ListNode(2);
    expected6->next = new ListNode(1);
    test(head6, 1, expected6);

    return 0;
}
