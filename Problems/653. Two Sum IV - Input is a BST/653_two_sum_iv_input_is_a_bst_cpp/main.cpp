#include <iostream>
#include <unordered_set>
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

bool findTarget(TreeNode* root, int k, unordered_set<int>& found) {
    if(!root) {
        return false;
    }

    if(found.find(k - root->val) != found.end()) {
        return true;
    }

    found.insert(root->val);

    return findTarget(root->left, k, found) || findTarget(root->right, k, found);
}

bool findTarget(TreeNode* root, int k) {
    unordered_set<int> found;

    return findTarget(root, k, found);
}

void printTree(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
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

void runTest(TreeNode* root, int k, bool expected) {
    cout << "Tree:" << endl;
    printTree(root);

    cout << "Target k: " << k << endl;

    bool result = findTarget(root, k);
    cout << "Expected: " << (expected ? "true" : "false") << endl;
    cout << "Result: " << (result ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(7);
    runTest(root1, 9, true);

    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(6);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);
    runTest(root2, 28, false);

    TreeNode* root3 = new TreeNode(2);
    root3->left = new TreeNode(1);
    root3->right = new TreeNode(3);
    runTest(root3, 4, true);

    TreeNode* root4 = new TreeNode(2);
    root4->left = new TreeNode(1);
    root4->right = new TreeNode(3);
    runTest(root4, 1, false);

    TreeNode* root5 = new TreeNode(1);
    runTest(root5, 2, false);

    return 0;
}
