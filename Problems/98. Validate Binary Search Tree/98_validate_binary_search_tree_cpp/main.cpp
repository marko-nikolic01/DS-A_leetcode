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

bool isValidBST(TreeNode* root, TreeNode*& last) {
    if (!root) {
        return true;
    }

    if (!isValidBST(root->left, last)) {
        return false;
    }

    if (last && root->val <= last->val) {
        return false;
    }
    last = root;

    return isValidBST(root->right, last);
}

bool isValidBST(TreeNode* root) {
    TreeNode* last = nullptr;

    return isValidBST(root, last);
}

void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

void testTree(TreeNode* root, bool expected) {
    cout << "Tree: ";
    printTree(root);
    cout << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isValidBST(root) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    testTree(root1, true);

    TreeNode* root2 = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
    testTree(root2, false);

    TreeNode* root3 = new TreeNode(-2147483648);
    testTree(root3, true);

    TreeNode* root4 = new TreeNode(1, new TreeNode(1), nullptr);
    testTree(root4, false);

    TreeNode* root5 = nullptr;
    testTree(root5, true);

    return 0;
}
