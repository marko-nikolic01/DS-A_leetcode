#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    unordered_map<ListNode *, int> occurences;

    while(head != nullptr) {
        if(occurences.find(head) != occurences.end()) {
            return true;
        }
        occurences[head] = 0;
        head = head->next;
    }
    return false;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    cout << "Test Case 1 - Expected: false, Result: " << (hasCycle(head1) ? "true" : "false") << endl;

    delete head1->next->next->next;
    delete head1->next->next;
    delete head1->next;
    delete head1;

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = head2->next->next;

    cout << "Test Case 2 - Expected: true, Result: " << (hasCycle(head2) ? "true" : "false") << endl;

    delete head2->next->next->next->next;
    delete head2->next->next->next;
    delete head2->next->next;
    delete head2->next;
    delete head2;

    return 0;
}
