#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    if(!head) {
        return;
    }

    vector<ListNode*> nodes;

    ListNode* current = head;
    while(current) {
        nodes.push_back(current);

        current = current->next;
    }

    current = head;

    int left = 0;
    int right = nodes.size() - 1;

    while(left < right) {
        nodes[left]->next = nodes[right];
        if(++left < right) {
            nodes[right]->next = nodes[left];
        }
        right--;
    }
    nodes[left]->next = nullptr;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

void testCase(ListNode* head, ListNode* expectedHead) {
    cout << "List: ";
    printList(head);

    cout << "Expected: ";
    printList(expectedHead);

    reorderList(head);
    cout << "Result: ";
    printList(head);

    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    ListNode* expected1 = new ListNode(1);
    expected1->next = new ListNode(4);
    expected1->next->next = new ListNode(2);
    expected1->next->next->next = new ListNode(3);
    testCase(head1, expected1);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    ListNode* expected2 = new ListNode(1);
    expected2->next = new ListNode(5);
    expected2->next->next = new ListNode(2);
    expected2->next->next->next = new ListNode(4);
    expected2->next->next->next->next = new ListNode(3);
    testCase(head2, expected2);

    ListNode* head3 = new ListNode(10);
    head3->next = new ListNode(20);
    head3->next->next = new ListNode(30);
    head3->next->next->next = new ListNode(40);
    head3->next->next->next->next = new ListNode(50);
    head3->next->next->next->next->next = new ListNode(60);
    ListNode* expected3 = new ListNode(10);
    expected3->next = new ListNode(60);
    expected3->next->next = new ListNode(20);
    expected3->next->next->next = new ListNode(50);
    expected3->next->next->next->next = new ListNode(30);
    expected3->next->next->next->next->next = new ListNode(40);
    testCase(head3, expected3);

    ListNode* head4 = new ListNode(1);
    ListNode* expected4 = new ListNode(1);
    testCase(head4, expected4);

    ListNode* head5 = nullptr;
    ListNode* expected5 = nullptr;
    testCase(head5, expected5);

    return 0;
}
