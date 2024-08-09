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

int maxDepth(TreeNode* root) {
    if(!root) {
        return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    if(left > right) {
        return ++left;
    }

    return ++right;
}

int main() {
    TreeNode* t1 = new TreeNode(1);
    cout << "Test Case 1: " << maxDepth(t1)
         << " | Expected: 1" << endl;

    TreeNode* t2 = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    cout << "Test Case 2: " << maxDepth(t2)
         << " | Expected: 3" << endl;

    TreeNode* t3 = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4), nullptr), nullptr), nullptr);
    cout << "Test Case 3: " << maxDepth(t3)
         << " | Expected: 4" << endl;

    TreeNode* t4 = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3, nullptr, new TreeNode(4))));
    cout << "Test Case 4: " << maxDepth(t4)
         << " | Expected: 4" << endl;

    TreeNode* t5 = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3));
    cout << "Test Case 5: " << maxDepth(t5)
         << " | Expected: 3" << endl;

    TreeNode* t6 = nullptr;
    cout << "Test Case 6: " << maxDepth(t6)
         << " | Expected: 0" << endl;

    return 0;
}
