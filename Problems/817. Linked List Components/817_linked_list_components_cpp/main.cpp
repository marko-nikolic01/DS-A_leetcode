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

int numComponents(ListNode* head, vector<int>& nums) {
    unordered_set<int> componentParts;
    for(int i = nums.size() - 1; i > -1; --i) {
        componentParts.insert(nums[i]);
    }

    nums[0] = 0;

    while(head) {
        if(componentParts.find(head->val) != componentParts.end()) {
            nums[0]++;

            while(head->next && componentParts.find(head->next->val) != componentParts.end()) {
                head = head->next;
            }
        }

        head = head->next;
    }

    return nums[0];
}

void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

void test(ListNode* head, vector<int> nums, int expected) {
    cout << "List: ";
    printLinkedList(head);

    cout << "Components: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numComponents(head, nums) << endl;

    cout << endl;
}

int main() {
    ListNode* list1 = new ListNode(0);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(2);
    list1->next->next->next = new ListNode(3);
    test(list1, {0, 1, 3}, 2);

    ListNode* list2 = new ListNode(0);
    list2->next = new ListNode(1);
    list2->next->next = new ListNode(2);
    list2->next->next->next = new ListNode(3);
    list2->next->next->next->next = new ListNode(4);
    test(list2, {0, 1, 2, 3, 4}, 1);

    ListNode* list3 = new ListNode(0);
    list3->next = new ListNode(1);
    list3->next->next = new ListNode(2);
    list3->next->next->next = new ListNode(3);
    list3->next->next->next->next = new ListNode(4);
    list3->next->next->next->next->next = new ListNode(5);
    test(list3, {1, 3, 5}, 3);

    ListNode* list4 = new ListNode(7);
    test(list4, {7}, 1);

    ListNode* list5 = new ListNode(10);
    test(list5, {7}, 0);

    ListNode* list6 = new ListNode(5);
    list6->next = new ListNode(6);
    list6->next->next = new ListNode(7);
    test(list6, {1, 2, 3}, 0);

    ListNode* list7 = new ListNode(1);
    list7->next = new ListNode(2);
    list7->next->next = new ListNode(3);
    list7->next->next->next = new ListNode(4);
    test(list7, {1, 2, 3}, 1);

    ListNode* list8 = new ListNode(8);
    list8->next = new ListNode(3);
    list8->next->next = new ListNode(0);
    list8->next->next->next = new ListNode(7);
    list8->next->next->next->next = new ListNode(1);
    list8->next->next->next->next->next = new ListNode(9);
    test(list8, {3, 7, 9}, 3);

    return 0;
}
