#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    stack<ListNode*> nodes;
    ListNode* current = head;
    while(current) {
        nodes.push(current);
        current = current->next;
    }

    while(n > 0) {
        current = nodes.top();
        nodes.pop();
        n--;
    }

    if(nodes.empty()) {
        return current->next;
    }

    current = nodes.top();
    current->next = current->next->next;

    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while(current) {
        cout << current->val;
        if(current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

void runTest(ListNode* head, int n) {
    cout << "List: ";
    printList(head);

    cout << "n: " << n << endl;

    cout << "Result: ";
    printList(removeNthFromEnd(head, n));

    cout << endl;
}

int main() {
    // Test case 1: Removing 2nd node from end in 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    runTest(head1, 2);

    // Test case 2: Removing 1st node from end in 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    runTest(head2, 1);

    // Test case 3: Removing 5th node from end in 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    head3->next->next = new ListNode(3);
    head3->next->next->next = new ListNode(4);
    head3->next->next->next->next = new ListNode(5);
    runTest(head3, 5);

    // Test case 4: Removing 1st node from end in 1
    ListNode* head4 = new ListNode(1);
    runTest(head4, 1);

    return 0;
}

