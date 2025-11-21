#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    return (!root1 && !root2) ? true : ((root1 && !root2) || (!root1 && root2) || (root1->val != root2->val)) ? false : (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
}

void printTree(TreeNode* root) {
    if(!root) {
        cout << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        cout << endl;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            }
        }
    }
}

void test(TreeNode* root1, TreeNode* root2, bool expected) {
    cout << "Tree 1: ";
    printTree(root1);

    cout << "Tree 2: ";
    printTree(root2);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (flipEquiv(root1, root2) ? "true" : "false") << endl;

    cout << endl;
}


int main() {
    TreeNode* root11 = new TreeNode(1);
    root11->left = new TreeNode(2);
    root11->right = new TreeNode(3);
    root11->left->left = new TreeNode(4);
    root11->left->right = new TreeNode(5);
    root11->right->left = new TreeNode(6);
    root11->left->right->left = new TreeNode(7);
    root11->left->right->right = new TreeNode(8);
    TreeNode* root21 = new TreeNode(1);
    root21->left = new TreeNode(3);
    root21->right = new TreeNode(2);
    root21->left->right = new TreeNode(6);
    root21->right->left = new TreeNode(4);
    root21->right->right = new TreeNode(5);
    root21->right->right->right = new TreeNode(8);
    root21->right->right->left = new TreeNode(7);
    test(root11, root21, true);

    TreeNode* root12 = nullptr;
    TreeNode* root22 = nullptr;
    test(root12, root22, true);

    TreeNode* root13 = nullptr;
    TreeNode* root23 = new TreeNode(1);
    test(root13, root23, false);

    TreeNode* root14 = new TreeNode(3);
    root14->left = new TreeNode(9);
    root14->right = new TreeNode(20);
    root14->right->left = new TreeNode(15);
    root14->right->right = new TreeNode(7);
    TreeNode* root24 = new TreeNode(3);
    root24->right = new TreeNode(9);
    root24->left = new TreeNode(20);
    root24->left->right = new TreeNode(15);
    root24->left->left = new TreeNode(7);
    test(root14, root24, true);

    TreeNode* root15 = new TreeNode(5);
    root15->left = new TreeNode(1);
    root15->right = new TreeNode(2);
    TreeNode* root25 = new TreeNode(5);
    root25->left = new TreeNode(2);
    root25->right = new TreeNode(1);
    test(root15, root25, true);

    return 0;
}

