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

bool isUnivalTree(TreeNode* root) {
    if(root->left) {
        if(root->left->val != root->val || !isUnivalTree(root->left)) {
            return false;
        }
    }

    if(root->right) {
        if(root->right->val != root->val || !isUnivalTree(root->right)) {
            return false;
        }
    }

    return true;
}

void printTree(TreeNode* root) {
    if (!root) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

// Function to run a test case
void runTest(TreeNode* root, bool expected) {
    cout << "Tree:" << endl;
    printTree(root);


    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isUnivalTree(root) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    TreeNode* test1 = new TreeNode(1, new TreeNode(1), new TreeNode(1));
    runTest(test1, true);

    TreeNode* test2 = new TreeNode(1, new TreeNode(1), new TreeNode(2));
    runTest(test2, false);

    TreeNode* test3 = new TreeNode(5, new TreeNode(5, new TreeNode(5), new TreeNode(5)), new TreeNode(5));
    runTest(test3, true);

    TreeNode* test4 = new TreeNode(1, new TreeNode(1), new TreeNode(1, new TreeNode(1), new TreeNode(2)));
    runTest(test4, false);

    TreeNode* test5 = new TreeNode(1);
    runTest(test5, true);

    return 0;
}
