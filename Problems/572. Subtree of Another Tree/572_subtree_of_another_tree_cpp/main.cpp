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

bool IsSameTree(TreeNode* root, TreeNode* subRoot) {
    if(!root && !subRoot) {
        return true;
    }

    if(root && subRoot && root->val == subRoot->val) {
        return IsSameTree(root->left, subRoot->left) && IsSameTree(root->right, subRoot->right);
    }

    return false;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(!root) {
        return false;
    }

    if(IsSameTree(root, subRoot)) {
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << "null";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
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

void runTest(TreeNode* root, TreeNode* subRoot, bool expected) {
    cout << "Tree: ";
    printTree(root);
    cout << "Subtree: ";
    printTree(subRoot);
    cout << "Expected: " << (expected ? "true" : "false") << endl;
    bool result = isSubtree(root, subRoot);
    cout << "Result: " << (result ? "true" : "false") << endl;
    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2)), new TreeNode(5));
    TreeNode* subRoot1 = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    runTest(root1, subRoot1, true);

    TreeNode* root2 = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2, new TreeNode(0), nullptr)), new TreeNode(5));
    TreeNode* subRoot2 = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    runTest(root2, subRoot2, false);

    TreeNode* root3 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* subRoot3 = new TreeNode(3);
    runTest(root3, subRoot3, true);

    TreeNode* root4 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* subRoot4 = new TreeNode(4);
    runTest(root4, subRoot4, false);

    return 0;
}
