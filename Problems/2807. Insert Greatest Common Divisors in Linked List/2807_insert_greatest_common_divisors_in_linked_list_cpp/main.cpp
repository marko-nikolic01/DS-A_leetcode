#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode* current = head;

    while(current->next) {
        int first = current->val;
        int second = current->next->val;

        while(second > 0) {
            int temp = second;
            second = first % second;
            first = temp;
        }

        current->next = new ListNode(first, current->next);

        current = current->next->next;
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        current = current->next;
        if(current) {
            cout << " -> ";
        }
    }
    cout << endl;
}

void test(ListNode* head, ListNode* expectedHead) {
    cout << "List: ";
    printList(head);

    cout << "Expected: ";
    printList(expectedHead);

    ListNode* resultHead = insertGreatestCommonDivisors(head);

    cout << "Result: ";
    printList(resultHead);

    cout << endl;
}

int main() {
    ListNode* test1 = new ListNode(2, new ListNode(4, new ListNode(8)));
    ListNode* expected1 = new ListNode(2, new ListNode(2, new ListNode(4, new ListNode(4, new ListNode(8)))));
    test(test1, expected1);

    ListNode* test2 = new ListNode(6, new ListNode(9, new ListNode(15)));
    ListNode* expected2 = new ListNode(6, new ListNode(3, new ListNode(9, new ListNode(3, new ListNode(15)))));
    test(test2, expected2);

    ListNode* test3 = new ListNode(12, new ListNode(18, new ListNode(24, new ListNode(30))));
    ListNode* expected3 = new ListNode(12, new ListNode(6, new ListNode(18, new ListNode(6, new ListNode(24, new ListNode(6, new ListNode(30)))))));
    test(test3, expected3);

    ListNode* test4 = new ListNode(5, new ListNode(5));
    ListNode* expected4 = new ListNode(5, new ListNode(5, new ListNode(5)));
    test(test4, expected4);

    ListNode* test5 = new ListNode(14, new ListNode(10));
    ListNode* expected5 = new ListNode(14, new ListNode(2, new ListNode(10)));
    test(test5, expected5);

    ListNode* test6 = new ListNode(3, new ListNode(5, new ListNode(7, new ListNode(11))));
    ListNode* expected6 = new ListNode(3, new ListNode(1, new ListNode(5, new ListNode(1, new ListNode(7, new ListNode(1, new ListNode(11)))))));
    test(test6, expected6);

    ListNode* test7 = new ListNode(18, new ListNode(9));
    ListNode* expected7 = new ListNode(18, new ListNode(9, new ListNode(9)));
    test(test7, expected7);

    ListNode* test8 = new ListNode(16, new ListNode(24, new ListNode(9, new ListNode(15))));
    ListNode* expected8 = new ListNode(16, new ListNode(8, new ListNode(24, new ListNode(3, new ListNode(9, new ListNode(3, new ListNode(15)))))));
    test(test8, expected8);

    return 0;
}
