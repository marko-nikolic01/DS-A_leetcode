#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int goodNodes(TreeNode* root, int max) {
    int goodNodesCount = 0;

    if(root->val >= max) {
        goodNodesCount++;
        max = root->val;
    }

    if(root->left) {
        goodNodesCount += goodNodes(root->left, max);
    }

    if(root->right) {
        goodNodesCount += goodNodes(root->right, max);
    }

    return goodNodesCount;
}

int goodNodes(TreeNode* root) {
    return goodNodes(root, INT_MIN);
}

void printTreeLevelByLevel(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "nullptr ";
            }
        }
        cout << endl;
    }
}

void runTestCase(TreeNode* root, int expectedGoodNodes) {
    cout << "Tree:" << endl;
    printTreeLevelByLevel(root);

    cout << "Expected: " << expectedGoodNodes << endl;

    cout << "Result: " << goodNodes(root) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->left = new TreeNode(3);
    root1->right->left = new TreeNode(1);
    root1->right->right = new TreeNode(5);
    runTestCase(root1, 4);

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(3);
    runTestCase(root2, 2);

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(5);
    root3->right = new TreeNode(2);
    runTestCase(root3, 3);

    TreeNode* root4 = new TreeNode(1);
    runTestCase(root4, 1);

    return 0;
}
