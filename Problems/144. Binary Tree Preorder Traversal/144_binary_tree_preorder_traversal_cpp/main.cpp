#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preorderTraversal(TreeNode* root, vector<int>& traversal) {
    if(!root) {
        return;
    }

    traversal.push_back(root->val);
    preorderTraversal(root->left, traversal);
    preorderTraversal(root->right, traversal);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> traversal;

    preorderTraversal(root, traversal);

    return traversal;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = preorderTraversal(root);

    cout << "Expected: 1 2 4 5 3" << endl;
    cout << "Result: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
