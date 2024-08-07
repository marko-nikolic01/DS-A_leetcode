#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL)
        return list2;

    if(list2 == NULL)
        return list1;


    ListNode *merged;
    if(list1->val <= list2->val) {
        merged = new ListNode(list1->val);
        list1 = list1->next;
    } else {
        merged = new ListNode(list2->val);
        list2 = list2->next;
    }
    ListNode *mergedTemp = merged;

    while(list1 != nullptr || list2 != nullptr) {
        ListNode *node = new ListNode();

        if(list1 != nullptr && list2 == nullptr) {
            node->val = list1->val;
            list1 = list1->next;
        } else if(list2 != nullptr && list1 == nullptr) {
            node->val = list2->val;
            list2 = list2->next;
        } else if(list1->val < list2->val) {
            node->val = list1->val;
            list1 = list1->next;
        } else {
            node->val = list2->val;
            list2 = list2->next;
        }
        mergedTemp->next = node;
        mergedTemp = node;
    }

    return merged;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* mergedList = mergeTwoLists(list1, list2);

    cout << "Merged list: ";
    printList(mergedList);

    ListNode* temp;
    while (mergedList != nullptr) {
        temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
