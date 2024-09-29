#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int doubleItHelper(ListNode* head) {
    head->val += head->val + (head->next ? doubleItHelper(head->next) : 0);

    if(head->val > 9) {
        head->val %= 10;
        return 1;
    }

    return 0;
}

ListNode* doubleIt(ListNode* head) {
    return doubleItHelper(head) == 0 ? head : new ListNode(1, head);
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

void testDoubleIt(ListNode* head, ListNode* expected) {
    cout << "List: ";
    printList(head);

    cout << "Expected: ";
    printList(expected);

    cout << "Result: ";
    printList(doubleIt(head));

    cout << endl;
}

int main()
{
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(3)));
    ListNode* expected1 = new ListNode(2, new ListNode(4, new ListNode(6)));
    testDoubleIt(head1, expected1);

    ListNode* head2 = new ListNode(9, new ListNode(9, new ListNode(9)));
    ListNode* expected2 = new ListNode(1, new ListNode(9, new ListNode(9, new ListNode(8))));
    testDoubleIt(head2, expected2);

    ListNode* head3 = new ListNode(5);
    ListNode* expected3 = new ListNode(1, new ListNode(0));
    testDoubleIt(head3, expected3);

    ListNode* head4 = new ListNode(0);
    ListNode* expected4 = new ListNode(0);
    testDoubleIt(head4, expected4);

    ListNode* head5 = new ListNode(1);
    ListNode* expected5 = new ListNode(2);
    testDoubleIt(head5, expected5);

    return 0;
}
