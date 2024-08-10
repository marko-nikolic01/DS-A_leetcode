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

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
        return false;
    }

    targetSum -= root->val;
    if (targetSum == 0 && !root->left && !root->right) {
        return true;
    }
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

int main() {
    TreeNode* root1 = nullptr;
    int targetSum1 = 0;
    bool expected1 = false;
    bool result1 = hasPathSum(root1, targetSum1);
    cout << "Test case 1: Expected: " << (expected1 ? "true" : "false") << ", Result: " << (result1 ? "true" : "false") << endl;

    TreeNode* root2 = new TreeNode(5);
    int targetSum2 = 5;
    bool expected2 = true;
    bool result2 = hasPathSum(root2, targetSum2);
    cout << "Test case 2: Expected: " << (expected2 ? "true" : "false") << ", Result: " << (result2 ? "true" : "false") << endl;

    TreeNode* root3 = new TreeNode(5);
    int targetSum3 = 10;
    bool expected3 = false;
    bool result3 = hasPathSum(root3, targetSum3);
    cout << "Test case 3: Expected: " << (expected3 ? "true" : "false") << ", Result: " << (result3 ? "true" : "false") << endl;

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    root4->left->left = new TreeNode(4);
    root4->left->right = new TreeNode(5);
    int targetSum4 = 7;
    bool expected4 = true;
    bool result4 = hasPathSum(root4, targetSum4);
    cout << "Test case 4: Expected: " << (expected4 ? "true" : "false") << ", Result: " << (result4 ? "true" : "false") << endl;

    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(3);
    root5->left->left = new TreeNode(4);
    root5->left->right = new TreeNode(5);
    int targetSum5 = 10;
    bool expected5 = false;
    bool result5 = hasPathSum(root5, targetSum5);
    cout << "Test case 5: Expected: " << (expected5 ? "true" : "false") << ", Result: " << (result5 ? "true" : "false") << endl;

    return 0;
}
