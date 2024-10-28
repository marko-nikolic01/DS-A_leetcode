#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> forbidden;
    for(int i = nums.size() - 1; i > -1; --i) {
        forbidden.insert(nums[i]);
    }

    while(head && forbidden.find(head->val) != forbidden.end()) {
        head = head->next;
    }

    if(head) {
        ListNode* currentEnd = head;
        ListNode* current = head->next;

        while(current) {
            if(forbidden.find(current->val) == forbidden.end()) {
                currentEnd->next = current;
                currentEnd = current;
            }
            current = current->next;
        }
        currentEnd->next = nullptr;
    }

    return head;
}

void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

void testModifiedList(vector<int>& nums, ListNode* head, ListNode* expected) {
    cout << "List: ";
    printLinkedList(head);

    ListNode* result = modifiedList(nums, head);

    cout << "Expected: ";
    printLinkedList(expected);

    cout << "Result: ";
    printLinkedList(result);

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
    expected1->next->next = new ListNode(5);
    vector<int> nums1 = {2, 3};
    testModifiedList(nums1, head1, expected1);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(5);
    head2->next->next->next = new ListNode(6);
    head2->next->next->next->next = new ListNode(1);
    ListNode* expected2 = new ListNode(5);
    expected2->next = new ListNode(6);
    vector<int> nums2 = {1, 4};
    testModifiedList(nums2, head2, expected2);

    ListNode* head3 = new ListNode(10);
    head3->next = new ListNode(20);
    head3->next->next = new ListNode(30);
    ListNode* expected3 = new ListNode(20);
    expected3->next = new ListNode(30);
    vector<int> nums3 = {10};
    testModifiedList(nums3, head3, expected3);

    ListNode* head4 = new ListNode(1);
    head4->next = new ListNode(2);
    head4->next->next = new ListNode(3);
    ListNode* expected4 = new ListNode(1);
    expected4->next = new ListNode(2);
    expected4->next->next = new ListNode(3);
    vector<int> nums4 = {};
    testModifiedList(nums4, head4, expected4);

    ListNode* head5 = new ListNode(1);
    head5->next = new ListNode(2);
    head5->next->next = new ListNode(3);
    ListNode* expected5 = nullptr;
    vector<int> nums5 = {1, 2, 3};
    testModifiedList(nums5, head5, expected5);

    return 0;
}
