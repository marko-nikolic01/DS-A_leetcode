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

void postorderTraversal(TreeNode* root, vector<int>& traversal) {
        if(!root) {
            return;
        }

        postorderTraversal(root->left, traversal);
        postorderTraversal(root->right, traversal);
        traversal.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> traversal;

    postorderTraversal(root, traversal);

    return traversal;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = postorderTraversal(root);

    cout << "Expected: 4 5 2 3 1" << endl;
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
