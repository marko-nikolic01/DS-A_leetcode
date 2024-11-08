#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int pairSum(ListNode* head) {
    ListNode* middle = head;
    ListNode* current = head;

    while(current) {
        current = current->next;
        if(current) {
            middle = middle->next;
            current = current->next;
        }
    }

    current = middle->next;
    middle->next = nullptr;
    while(current) {
        ListNode* next = current->next;
        current->next = middle;
        middle = current;
        current = next;
    }

    int maxTwinSum = middle->val + head->val;

    head = head->next;
    middle = middle->next;

    while(middle) {
        if(middle->val + head->val > maxTwinSum) {
            maxTwinSum = middle->val + head->val;
        }

        head = head->next;
    middle = middle->next;
    }

    return maxTwinSum;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        current = current->next;
        if(current) {
            cout << " -> ";
        }
    }
    cout << endl;
}

void test(ListNode* head, int expected) {
    cout << "List: ";
    printList(head);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << pairSum(head) << endl;

    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    test(head1, 3);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    test(head2, 5);

    ListNode* head3 = new ListNode(2);
    head3->next = new ListNode(2);
    head3->next->next = new ListNode(2);
    head3->next->next->next = new ListNode(2);
    test(head3, 4);

    ListNode* head4 = new ListNode(1);
    head4->next = new ListNode(3);
    head4->next->next = new ListNode(5);
    head4->next->next->next = new ListNode(7);
    test(head4, 8);

    ListNode* head5 = new ListNode(1);
    head5->next = new ListNode(10);
    head5->next->next = new ListNode(5);
    head5->next->next->next = new ListNode(3);
    test(head5, 15);

    ListNode* head6 = new ListNode(1);
    head6->next = new ListNode(2);
    head6->next->next = new ListNode(2);
    head6->next->next->next = new ListNode(1);
    test(head6, 4);

    ListNode* head7 = new ListNode(1);
    head7->next = new ListNode(2);
    head7->next->next = new ListNode(3);
    head7->next->next->next = new ListNode(4);
    head7->next->next->next->next = new ListNode(5);
    head7->next->next->next->next->next = new ListNode(6);
    head7->next->next->next->next->next->next = new ListNode(7);
    head7->next->next->next->next->next->next->next = new ListNode(8);
    test(head7, 9);

    ListNode* head8 = new ListNode(2);
    head8->next = new ListNode(4);
    head8->next->next = new ListNode(5);
    head8->next->next->next = new ListNode(7);
    test(head8, 9);

    return 0;
}
