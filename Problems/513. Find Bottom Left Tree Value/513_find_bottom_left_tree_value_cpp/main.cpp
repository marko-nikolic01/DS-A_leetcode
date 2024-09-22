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

void findBottomLeftValue(TreeNode* root, int& left, int& maxDepth, int depth) {
    if(!root) {
        return;
    }

    if(++depth > maxDepth) {
        maxDepth = depth;
        left = root->val;
    }

    findBottomLeftValue(root->left, left, maxDepth, depth);
    findBottomLeftValue(root->right, left, maxDepth, depth);
}

int findBottomLeftValue(TreeNode* root) {
    int left = root->val;
    int maxDepth = -1;

    findBottomLeftValue(root, left, maxDepth, 0);

    return left;
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

void runTest(TreeNode* root, int expected) {
    cout << "Tree:" << endl;
    printTree(root);


    cout << "Expected: " << expected << endl;

    cout << "Result: " << findBottomLeftValue(root) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    runTest(root1, 1);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(4);
    root2->right = new TreeNode(3);
    runTest(root2, 4);

    TreeNode* root3 = new TreeNode(3);
    root3->left = new TreeNode(9);
    root3->right = new TreeNode(20);
    root3->right->left = new TreeNode(15);
    root3->right->right = new TreeNode(7);
    runTest(root3, 15);

    return 0;
}
