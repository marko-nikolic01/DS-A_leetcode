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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* sortedListToBST(ListNode* start, ListNode* end) {
    ListNode* slow = start;
    ListNode* fast = start;

    while(fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }

    TreeNode* node = new TreeNode(slow->val);

    if(slow != start) {
        node->left = sortedListToBST(start, slow);
    }

    if(slow->next != end) {
        node->right = sortedListToBST(slow->next, end);
    }

    return node;
}

TreeNode* sortedListToBST(ListNode* head) {
    if(!head) {
        return nullptr;
    }

    return sortedListToBST(head, nullptr);
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        cout << endl;
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

            if (current) {
                cout << current->val << " ";
                q.push(current->left);
                q.push(current->right);
            }
        }
    }
}

void test(ListNode* head, TreeNode* expected) {
    cout << "List: ";
    printList(head);

    cout << "Expected: ";
    printTree(expected);

    cout << "Result: ";
    printTree(sortedListToBST(head));

    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(-10);
    head1->next = new ListNode(-3);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(5);
    head1->next->next->next->next = new ListNode(9);
    TreeNode* expected1 = new TreeNode(0);
    expected1->left = new TreeNode(-3);
    expected1->left->left = new TreeNode(-10);
    expected1->right = new TreeNode(9);
    expected1->right->left = new TreeNode(5);
    test(head1, expected1);

    ListNode* head2 = nullptr;
    TreeNode* expected2 = nullptr;
    test(head2, expected2);

    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(3);
    TreeNode* expected3 = new TreeNode(3);
    expected3->left = new TreeNode(1);
    test(head3, expected3);

    ListNode* head4 = new ListNode(-5);
    head4->next = new ListNode(-2);
    head4->next->next = new ListNode(0);
    head4->next->next->next = new ListNode(3);
    head4->next->next->next->next = new ListNode(8);
    TreeNode* expected4 = new TreeNode(0);
    expected4->left = new TreeNode(-2);
    expected4->left->right = new TreeNode(-5);
    expected4->right = new TreeNode(8);
    expected4->right->left = new TreeNode(3);
    test(head4, expected4);

    ListNode* head5 = new ListNode(2);
    head5->next = new ListNode(4);
    head5->next->next = new ListNode(6);
    head5->next->next->next = new ListNode(8);
    head5->next->next->next->next = new ListNode(10);
    TreeNode* expected5 = new TreeNode(6);
    expected5->left = new TreeNode(4);
    expected5->left->left = new TreeNode(2);
    expected5->right = new TreeNode(10);
    expected5->right->left = new TreeNode(8);
    test(head5, expected5);

    ListNode* head6 = new ListNode(0);
    head6->next = new ListNode(1);
    TreeNode* expected6 = new TreeNode(1);
    expected6->left = new TreeNode(0);
    test(head6, expected6);

    ListNode* head7 = new ListNode(0);
    TreeNode* expected7 = new TreeNode(0);
    test(head7, expected7);

    return 0;
}
