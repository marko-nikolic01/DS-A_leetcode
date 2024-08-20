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

int diameterOfBinaryTree(TreeNode* root, int& diameter) {
    if(!root) {
        return 0;
    }

    int left = diameterOfBinaryTree(root->left, diameter);
    int right = diameterOfBinaryTree(root->right, diameter);

    if(left + right > diameter) {
        diameter = left + right;
    }

    return left > right ? ++left : ++right;
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;

    diameterOfBinaryTree(root, diameter);

    return diameter;
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl;
    }
}

void test() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    cout << "Tree 1:" << endl;
    printTree(root1);
    int expected1 = 3;
    int result1 = diameterOfBinaryTree(root1);
    cout << "Expected: " << expected1 << endl;
    cout << "Result: " << result1 << endl;
    cout << endl;

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    root2->left->left->left->left = new TreeNode(5);
    cout << "Tree 2:" << endl;
    printTree(root2);
    int expected2 = 4;
    int result2 = diameterOfBinaryTree(root2);
    cout << "Expected: " << expected2 << endl;
    cout << "Result: " << result2 << endl;
    cout << endl;

    TreeNode* root3 = new TreeNode(4);
    root3->left = new TreeNode(-7);
    root3->right = new TreeNode(-3);
    root3->right->left = new TreeNode(-9);
    root3->right->right = new TreeNode(-3);
    root3->right->left->left = new TreeNode(9);
    root3->right->left->right = new TreeNode(-7);
    root3->right->right->left = new TreeNode(-4);
    root3->right->right->right = new TreeNode(6);
    root3->right->right->left->left = new TreeNode(-6);
    root3->right->right->left->right = new TreeNode(-6);
    root3->right->right->right->left = new TreeNode(0);
    root3->right->right->right->right = new TreeNode(6);
    root3->right->right->left->left->left = new TreeNode(5);
    root3->right->right->left->left->left->left = new TreeNode(-1);
    root3->right->right->left->left->left->left->left = new TreeNode(-4);
    root3->right->right->left->left->left->left->left->left = new TreeNode(-2);
    cout << "Tree 3:" << endl;
    printTree(root3);
    int expected3 = 9;
    int result3 = diameterOfBinaryTree(root3);
    cout << "Expected: " << expected3 << endl;
    cout << "Result: " << result3 << endl;
}

int main() {
    test();
    return 0;
}
