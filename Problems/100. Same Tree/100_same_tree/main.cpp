#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) {
        return true;
    } else if(!p || !q) {
        return false;
    }

    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    TreeNode* p1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << "Test Case 1: " << (isSameTree(p1, q1) ? "True" : "False")
         << " | Expected: True" << endl;

    TreeNode* p2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q2 = new TreeNode(1, new TreeNode(2), nullptr);
    cout << "Test Case 2: " << (isSameTree(p2, q2) ? "True" : "False")
         << " | Expected: False" << endl;

    TreeNode* p3 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q3 = new TreeNode(1, new TreeNode(4), new TreeNode(3));
    cout << "Test Case 3: " << (isSameTree(p3, q3) ? "True" : "False")
         << " | Expected: False" << endl;

    TreeNode* p4 = nullptr;
    TreeNode* q4 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << "Test Case 4: " << (isSameTree(p4, q4) ? "True" : "False")
         << " | Expected: False" << endl;

    TreeNode* p5 = nullptr;
    TreeNode* q5 = nullptr;
    cout << "Test Case 5: " << (isSameTree(p5, q5) ? "True" : "False")
         << " | Expected: True" << endl;

    return 0;
}
