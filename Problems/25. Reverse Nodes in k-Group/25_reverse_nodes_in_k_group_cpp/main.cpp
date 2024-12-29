#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* current = head;
    int n = 0;
    while(current) {
        ++n;
        current = current->next;
    }

    ListNode* start = new ListNode(0, head);
    ListNode* previousSection = start;
    while(n >= k) {
        ListNode* nextSection = head;
        current = head;
        head = head->next;

        for(int i = 1; i < k; ++i) {
            ListNode* temp = head->next;
            head->next = current;
            current = head;
            head = temp;
        }

        previousSection->next = current;
        previousSection = nextSection;

        n -= k;
    }
    previousSection->next = head;

    return start->next;
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
    printList(reverseKGroup(head, k));

    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    ListNode* expected1 = new ListNode(2);
    expected1->next = new ListNode(1);
    expected1->next->next = new ListNode(4);
    expected1->next->next->next = new ListNode(3);
    expected1->next->next->next->next = new ListNode(5);
    test(head1, 2, expected1);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    ListNode* expected2 = new ListNode(3);
    expected2->next = new ListNode(2);
    expected2->next->next = new ListNode(1);
    expected2->next->next->next = new ListNode(4);
    expected2->next->next->next->next = new ListNode(5);
    test(head2, 3, expected2);

    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    head3->next->next = new ListNode(3);
    head3->next->next->next = new ListNode(4);
    head3->next->next->next->next = new ListNode(5);
    ListNode* expected3 = new ListNode(1);
    expected3->next = new ListNode(2);
    expected3->next->next = new ListNode(3);
    expected3->next->next->next = new ListNode(4);
    expected3->next->next->next->next = new ListNode(5);
    test(head3, 1, expected3);

    ListNode* head4 = new ListNode(1);
    head4->next = new ListNode(2);
    head4->next->next = new ListNode(3);
    head4->next->next->next = new ListNode(4);
    head4->next->next->next->next = new ListNode(5);
    ListNode* expected4 = new ListNode(5);
    expected4->next = new ListNode(4);
    expected4->next->next = new ListNode(3);
    expected4->next->next->next = new ListNode(2);
    expected4->next->next->next->next = new ListNode(1);
    test(head4, 5, expected4);

    ListNode* head5 = new ListNode(1);
    head5->next = new ListNode(2);
    ListNode* expected5 = new ListNode(2);
    expected5->next = new ListNode(1);
    test(head5, 2, expected5);

    ListNode* head6 = new ListNode(1);
    head6->next = new ListNode(2);
    head6->next->next = new ListNode(3);
    ListNode* expected6 = new ListNode(3);
    expected6->next = new ListNode(2);
    expected6->next->next = new ListNode(1);
    test(head6, 3, expected6);

    ListNode* head7 = new ListNode(1);
    head7->next = new ListNode(2);
    head7->next->next = new ListNode(3);
    ListNode* expected7 = new ListNode(2);
    expected7->next = new ListNode(1);
    expected7->next->next = new ListNode(3);
    test(head7, 2, expected7);

    ListNode* head8 = new ListNode(1);
    ListNode* expected8 = new ListNode(1);
    test(head8, 1, expected8);

    return 0;
}
