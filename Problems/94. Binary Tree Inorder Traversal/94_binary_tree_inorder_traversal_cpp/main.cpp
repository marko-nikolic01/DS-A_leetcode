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

void inorderTraversal(TreeNode* root, vector<int>& traversal) {
    if(!root) {
        return;
    }

    inorderTraversal(root->left, traversal);
    traversal.push_back(root->val);
    inorderTraversal(root->right, traversal);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> traversal;

    inorderTraversal(root, traversal);

    return traversal;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    root->right = new TreeNode(6, new TreeNode(5), new TreeNode(7));

    vector<int> result = inorderTraversal(root);
    cout << "Inorder traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
