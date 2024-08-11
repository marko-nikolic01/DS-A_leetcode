#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode*, bool> occurences;

    while(headA || headB) {
        if(headA) {
            if(occurences.find(headA) == occurences.end()) {
                occurences[headA] = false;
                headA = headA->next;
            } else {
                return headA;
            }
        }

        if(headB) {
            if(occurences.find(headB) == occurences.end()) {
                occurences[headB] = false;
                headB = headB->next;
            } else {
                return headB;
            }
        }
    }

    return nullptr;
}

void printResult(ListNode* node) {
    if (node) {
        cout << "Intersection at node with value: " << node->val << endl;
    } else {
        cout << "No intersection" << endl;
    }
}

void printTestCase(ListNode* headA, ListNode* headB, ListNode* expected) {
    ListNode* result = getIntersectionNode(headA, headB);
    cout << "Expected: ";
    printResult(expected);
    cout << "Result: ";
    printResult(result);
}

int main() {
    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(4);
    intersect->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersect;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersect;

    ListNode* expected1 = intersect;
    printTestCase(headA, headB, expected1);

    ListNode* headA2 = new ListNode(1);
    headA2->next = new ListNode(2);

    ListNode* headB2 = new ListNode(3);
    headB2->next = new ListNode(4);

    ListNode* expected2 = nullptr;
    printTestCase(headA2, headB2, expected2);

    ListNode* headA3 = new ListNode(1);
    headA3->next = new ListNode(2);

    ListNode* headB3 = nullptr;

    ListNode* expected3 = nullptr;
    printTestCase(headA3, headB3, expected3);

    ListNode* headA4 = nullptr;
    ListNode* headB4 = nullptr;

    ListNode* expected4 = nullptr;
    printTestCase(headA4, headB4, expected4);

    return 0;
}
