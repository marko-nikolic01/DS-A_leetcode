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


void countNodes(TreeNode* root, int& count) {
    if(!root) {
        return;
    }

    count++;

    countNodes(root->left, count);
    countNodes(root->right, count);
}

int countNodes(TreeNode* root) {
    int count = 0;

    countNodes(root, count);

    return count;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    TreeNode* root2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* root3 = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    TreeNode* root4 = nullptr;

    cout << "Test case 1: Expected: 1 Result: " << countNodes(root1) << endl << endl;
    cout << "Test case 2: Expected: 3 Result: " << countNodes(root2) << endl << endl;
    cout << "Test case 3: Expected: 5 Result: " << countNodes(root3) << endl << endl;
    cout << "Test case 4: Expected: 0 Result: " << countNodes(root4) << endl << endl;

    return 0;
}
