#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    list1 = new ListNode(0, list1);

    ListNode* current1 = list1;
    while(a > 0) {
        --a;
        --b;
        current1 = current1->next;
    }
    ListNode* current2 = current1->next;
    current1->next = list2;

    while(b > 0) {
        --b;
        current2 = current2->next;
    }
    while(list2->next) {
        list2 = list2->next;
    }
    list2->next = current2->next;

    return list1->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

void test(ListNode* list1, int a, int b, ListNode* list2, ListNode* expected) {
    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    cout<< "a: " << a << endl;

    cout<< "b: " << b << endl;

    cout << "Expected: ";
    printList(expected);

    cout << "Result: ";
    printList(mergeInBetween(list1, a, b, list2));

    cout << endl;
}

int main() {
    ListNode* list1 = new ListNode(0, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))));
    ListNode* list2 = new ListNode(100, new ListNode(101, new ListNode(102)));
    ListNode* expected1 = new ListNode(0, new ListNode(1, new ListNode(100, new ListNode(101, new ListNode(102, new ListNode(5))))));
    test(list1, 2, 4, list2, expected1);

    ListNode* list3 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    ListNode* list4 = new ListNode(10, new ListNode(11));
    ListNode* expected2 = new ListNode(1, new ListNode(10, new ListNode(11, new ListNode(5, new ListNode(6)))));
    test(list3, 1, 3, list4, expected2);

    ListNode* list5 = new ListNode(7, new ListNode(8, new ListNode(9)));
    ListNode* list6 = new ListNode(99, new ListNode(100));
    ListNode* expected3 = new ListNode(7, new ListNode(99, new ListNode(100, new ListNode(9))));
    test(list5, 1, 1, list6, expected3);

    ListNode* list7 = new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(0))));
    ListNode* list8 = new ListNode(5, new ListNode(6));
    ListNode* expected4 = new ListNode(0, new ListNode(5, new ListNode(6, new ListNode(0, new ListNode(0)))));
    test(list7, 1, 1, list8, expected4);

    ListNode* list9 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    ListNode* list10 = new ListNode(9, new ListNode(8, new ListNode(7)));
    ListNode* expected5 = new ListNode(1, new ListNode(9, new ListNode(8, new ListNode(7, new ListNode(4)))));
    test(list9, 1, 2, list10, expected5);

    ListNode* list11 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* list12 = new ListNode(50, new ListNode(60));
    ListNode* expected6 = new ListNode(1, new ListNode(2, new ListNode(50, new ListNode(60, new ListNode(5)))));
    test(list11, 2, 3, list12, expected6);

    return 0;
}
