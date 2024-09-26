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

bool checkTree(TreeNode* root) {
    return root->val == root->left->val + root->right->val;
}

void printTree(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();
            cout << current->val << " ";

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl;
    }
}

void printTestCase(TreeNode* root, bool expected) {
    cout << "Tree:" << endl;
    printTree(root);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (checkTree(root) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    TreeNode* input1 = new TreeNode(5, new TreeNode(2), new TreeNode(3));
    printTestCase(input1, true);

    TreeNode* input2 = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    printTestCase(input2, false);

    TreeNode* input3 = new TreeNode(0, new TreeNode(0), new TreeNode(0));
    printTestCase(input3, true);

    TreeNode* input4 = new TreeNode(10, new TreeNode(5), new TreeNode(5));
    printTestCase(input4, true);

    TreeNode* input5 = new TreeNode(1, new TreeNode(1), new TreeNode(1));
    printTestCase(input5, false);

    return 0;
}
