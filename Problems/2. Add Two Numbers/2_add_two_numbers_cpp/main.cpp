#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carryOver = 0;
    ListNode* result = nullptr;
    ListNode* current;
    while(l1 || l2 || carryOver == 1) {
        int num = carryOver;

        if(l1) {
            num += l1->val;
            l1 = l1->next;
        }

        if(l2) {
            num += l2->val;
            l2 = l2->next;
        }

        if(num >= 10) {
            carryOver = 1;
            num %= 10;
        } else {
            carryOver = 0;
        }

        ListNode* node = new ListNode(num);
        if(result) {
            current->next = node;
        } else {
            result = node;
        }
        current = node;
    }

    return result;
}

void printList(ListNode* node) {
    while (node) {
        cout << node->val;
        if (node->next) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    while (l1) {
        ListNode* temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (l2) {
        ListNode* temp = l2;
        l2 = l2->next;
        delete temp;
    }
    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
