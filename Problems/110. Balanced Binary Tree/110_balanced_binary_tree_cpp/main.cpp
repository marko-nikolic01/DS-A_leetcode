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

int isTreeBalanced(TreeNode* root) {
    if(!root) {
        return 0;
    }

    if(root->left || root->right) {
        int leftDepth = isTreeBalanced(root->left);
        int rightDepth = isTreeBalanced(root->right);

        if(leftDepth == -1 || rightDepth == -1 || leftDepth - rightDepth < -1 || leftDepth - rightDepth > 1) {
            return -1;
        }

        if(leftDepth > rightDepth) {
            return ++leftDepth;
        }

        return ++rightDepth;
    }

    return 1;
}

bool isBalanced(TreeNode* root) {
    return isTreeBalanced(root) != -1;
}

int main() {
    TreeNode* root1 = nullptr;
    cout << "Test Case 1 - Expected: true, Actual: " << (isBalanced(root1) ? "true" : "false") << endl;

    TreeNode* root2 = new TreeNode(1);
    cout << "Test Case 2 - Expected: true, Actual: " << (isBalanced(root2) ? "true" : "false") << endl;

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(5);
    root3->right->left = new TreeNode(6);
    root3->right->right = new TreeNode(7);
    cout << "Test Case 3 - Expected: true, Actual: " << (isBalanced(root3) ? "true" : "false") << endl;

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->left->left = new TreeNode(3);
    cout << "Test Case 4 - Expected: false, Actual: " << (isBalanced(root4) ? "true" : "false") << endl;

    TreeNode* root5 = new TreeNode(1);
    root5->right = new TreeNode(2);
    root5->right->right = new TreeNode(3);
    cout << "Test Case 5 - Expected: false, Actual: " << (isBalanced(root5) ? "true" : "false") << endl;

    TreeNode* root6 = new TreeNode(1);
    root6->left = new TreeNode(2);
    root6->right = new TreeNode(3);
    root6->left->left = new TreeNode(4);
    cout << "Test Case 6 - Expected: true, Actual: " << (isBalanced(root6) ? "true" : "false") << endl;

    return 0;
}
