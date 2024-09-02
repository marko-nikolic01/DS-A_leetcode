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

ListNode* rotateRight(ListNode* head, int k) {
    if(!head || k == 0) {
        return head;
    }

    vector<ListNode*> nodes = {head};

    ListNode* first = head;

    while(head->next) {
        nodes.push_back(head->next);
        head = head->next;
    }

    int n = nodes.size();
    k = k % n;
    if(k == 0) {
        return first;
    }

    head->next = first;
    nodes[n - k - 1]->next = nullptr;

    return nodes[n - k];
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

void test(const vector<int>& vals, int k, const vector<int>& expectedVals) {
    ListNode* head = createList(vals);
    ListNode* expected = createList(expectedVals);

    cout << "List: ";
    printList(createList(vals));
    cout << "k = " << k << endl;

    cout << "Expected: ";
    printList(expected);

    cout << "Result: ";
    printList(rotateRight(head, k));

    cout << endl;
}

int main() {
    test({1, 2, 3, 4, 5}, 2, {4, 5, 1, 2, 3});

    test({0, 1, 2}, 4, {2, 0, 1});

    test({1}, 99, {1});

    return 0;
}
