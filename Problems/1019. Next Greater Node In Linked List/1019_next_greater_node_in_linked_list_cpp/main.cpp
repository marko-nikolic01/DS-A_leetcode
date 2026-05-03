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

vector<int> nextLargerNodes(ListNode* head) {
    vector<int> nextGreater;
    vector<pair<short, int>> pending;

    while(head) {
        while(!pending.empty() && pending.back().second < head->val) {
            nextGreater[pending.back().first] = head->val;
            pending.pop_back();
        }

        pending.push_back({nextGreater.size(), head->val});
        nextGreater.push_back(0);
        head = head->next;
    }

    return nextGreater;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printList(ListNode* head) {
    while(head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

void test(ListNode* head, vector<int> expected) {
    cout << "List: ";
    printList(head);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(nextLargerNodes(head));

    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(2);
    head1->next = new ListNode(1);
    head1->next->next = new ListNode(5);
    test(head1, {5, 5, 0});

    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(7);
    head2->next->next = new ListNode(4);
    head2->next->next->next = new ListNode(3);
    head2->next->next->next->next = new ListNode(5);
    test(head2, {7, 0, 5, 5, 0});

    ListNode* head3 = new ListNode(42);
    test(head3, {0});

    ListNode* head4 = new ListNode(5);
    head4->next = new ListNode(4);
    head4->next->next = new ListNode(3);
    head4->next->next->next = new ListNode(2);
    head4->next->next->next->next = new ListNode(1);
    test(head4, {0, 0, 0, 0, 0});

    ListNode* head5 = new ListNode(1);
    head5->next = new ListNode(2);
    head5->next->next = new ListNode(3);
    head5->next->next->next = new ListNode(4);
    head5->next->next->next->next = new ListNode(5);
    test(head5, {2, 3, 4, 5, 0});

    return 0;
}


