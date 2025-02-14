#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = 0;
    priority_queue<ListNode*, vector<ListNode*>, bool(*)(ListNode*, ListNode*)> nodes(
        [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    );

    for(int i = lists.size() - 1; i > -1; --i) {
        if(lists[i]) {
            ++n;
            nodes.push(lists[i]);
        }
    }

    if(n < 1) {
        return nullptr;
    }

    ListNode* list = nodes.top();
    nodes.pop();

    ListNode* current = list;

    if(current->next) {
        nodes.push(current->next);
    } else {
        --n;
    }

    while(n > 0) {
        current->next = nodes.top();
        nodes.pop();

        current = current->next;

        if(current->next) {
            nodes.push(current->next);
        } else {
            --n;
        }
    }

    return list;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr";
}

void test(vector<ListNode*> lists, ListNode* expected) {
    cout << "Lists: ";
    for(ListNode* list : lists) {
        cout << "[";
        printList(list);
        cout << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printList(expected);
    cout << endl;

    cout << "Result: ";
    printList(mergeKLists(lists));
    cout << endl;

    cout << endl;
}

int main() {
    vector<ListNode*> lists1 = {};
    test(lists1, nullptr);

    vector<ListNode*> lists2 = {nullptr, nullptr, nullptr};
    test(lists2, nullptr);

    ListNode* list31 = new ListNode(1);
    list31->next = new ListNode(3);
    list31->next->next = new ListNode(5);
    vector<ListNode*> lists3 = {list31};
    ListNode* expected3 = new ListNode(1);
    expected3->next = new ListNode(3);
    expected3->next->next = new ListNode(5);
    test(lists3, expected3);

    ListNode* list41 = new ListNode(2);
    list41->next = new ListNode(4);
    list41->next->next = new ListNode(6);
    ListNode* list42 = new ListNode(1);
    list42->next = new ListNode(3);
    list42->next->next = new ListNode(5);
    vector<ListNode*> lists4 = {list41, list42};
    ListNode* expected4 = new ListNode(1);
    expected4->next = new ListNode(2);
    expected4->next->next = new ListNode(3);
    expected4->next->next->next = new ListNode(4);
    expected4->next->next->next->next = new ListNode(5);
    expected4->next->next->next->next->next = new ListNode(6);
    test(lists4, expected4);

    ListNode* list51 = nullptr;
    ListNode* list52 = new ListNode(1);
    list52->next = new ListNode(3);
    list52->next->next = new ListNode(5);
    ListNode* list53 = new ListNode(0);
    list53->next = new ListNode(7);
    list53->next->next = new ListNode(8);
    vector<ListNode*> lists5 = {list51, list52, list53};
    ListNode* expected5 = new ListNode(0);
    expected5->next = new ListNode(1);
    expected5->next->next = new ListNode(3);
    expected5->next->next->next = new ListNode(5);
    expected5->next->next->next->next = new ListNode(7);
    expected5->next->next->next->next->next = new ListNode(8);
    test(lists5, expected5);

    ListNode* list61 = new ListNode(1);
    list61->next = new ListNode(1);
    list61->next->next = new ListNode(2);
    ListNode* list62 = new ListNode(1);
    list62->next = new ListNode(3);
    list62->next->next = new ListNode(4);
    vector<ListNode*> lists6 = {list61, list62};
    ListNode* expected6 = new ListNode(1);
    expected6->next = new ListNode(1);
    expected6->next->next = new ListNode(1);
    expected6->next->next->next = new ListNode(2);
    expected6->next->next->next->next = new ListNode(3);
    expected6->next->next->next->next->next = new ListNode(4);
    test(lists6, expected6);

    ListNode* list71 = new ListNode(10);
    ListNode* list72 = new ListNode(5);
    list72->next = new ListNode(15);
    ListNode* list73 = new ListNode(2);
    list73->next = new ListNode(7);
    list73->next->next = new ListNode(20);
    vector<ListNode*> lists7 = {list71, list72, list73};
    ListNode* expected7 = new ListNode(2);
    expected7->next = new ListNode(5);
    expected7->next->next = new ListNode(7);
    expected7->next->next->next = new ListNode(10);
    expected7->next->next->next->next = new ListNode(15);
    expected7->next->next->next->next->next = new ListNode(20);
    test(lists7, expected7);

    return 0;
}
