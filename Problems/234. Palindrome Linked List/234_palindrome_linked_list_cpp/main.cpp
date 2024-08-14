#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head, queue<int>& nums) {
    if(!head) {
        return true;
    }

    nums.push(head->val);

    if(!isPalindrome(head->next, nums) || nums.front() != head->val) {
        return false;
    }

    nums.pop();
    return true;
}

bool isPalindrome(ListNode* head) {
    queue<int> nums;

    return isPalindrome(head, nums);
}

void printList(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void printTestCase(ListNode* head, bool expected) {
    cout << "List: ";
    printList(head);
    bool result = isPalindrome(head);
    cout << "Expected: " << (expected ? "true" : "false") << endl;
    cout << "Result: " << (result ? "true" : "false") << endl << endl;
}

int main() {
    ListNode* node4 = new ListNode(1);
    ListNode* node3 = new ListNode(2, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);
    printTestCase(node1, true);

    ListNode* node8 = new ListNode(4);
    ListNode* node7 = new ListNode(3, node8);
    ListNode* node6 = new ListNode(2, node7);
    ListNode* node5 = new ListNode(1, node6);
    printTestCase(node5, false);

    ListNode* node9 = new ListNode(1);
    printTestCase(node9, true);

    ListNode* node10 = nullptr;
    printTestCase(node10, true);

    ListNode* node13 = new ListNode(1);
    ListNode* node12 = new ListNode(2, node13);
    ListNode* node11 = new ListNode(1, node12);
    printTestCase(node11, true);

    return 0;
}
