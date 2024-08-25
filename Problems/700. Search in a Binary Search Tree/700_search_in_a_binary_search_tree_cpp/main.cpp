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

TreeNode* searchBST(TreeNode* root, int val) {
    if(!root || val == root->val) {
        return root;
    } else if (val < root->val) {
        return searchBST(root->left, val);
    }
    return searchBST(root->right, val);
}

void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

void runTest(TreeNode* root, int searchValue, TreeNode* expectedSubtree) {
    cout << "Tree: ";
    printTree(root);
    cout << endl;

    cout << "Searching for: " << searchValue << endl;

    cout << "Expected: ";
    printTree(expectedSubtree);
    cout << endl;

    TreeNode* result = searchBST(root, searchValue);
    cout << "Result: ";
    printTree(result);
    cout << endl << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    runTest(root1, 2, root1->left);

    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(7);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);
    runTest(root2, 7, root2->right);

    TreeNode* root3 = new TreeNode(4);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(7);
    root3->left->left = new TreeNode(1);
    root3->left->right = new TreeNode(3);
    runTest(root3, 5, nullptr);

    TreeNode* root4 = new TreeNode(6);
    root4->left = new TreeNode(3);
    root4->right = new TreeNode(8);
    root4->left->left = new TreeNode(2);
    root4->left->right = new TreeNode(4);
    root4->right->right = new TreeNode(9);
    runTest(root4, 3, root4->left);

    TreeNode* root5 = new TreeNode(5);
    root5->left = new TreeNode(3);
    root5->right = new TreeNode(7);
    root5->left->left = new TreeNode(2);
    root5->left->right = new TreeNode(4);
    root5->right->left = new TreeNode(6);
    root5->right->right = new TreeNode(8);
    runTest(root5, 1, nullptr);

    return 0;
}
