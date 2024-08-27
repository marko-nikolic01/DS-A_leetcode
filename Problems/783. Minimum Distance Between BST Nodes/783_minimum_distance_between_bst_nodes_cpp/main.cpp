#include <iostream>
#include <vector>
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

void minDiffInBST(TreeNode* root, vector<int>& traversal) {
    if(!root) {
        return;
    }

    minDiffInBST(root->left, traversal);
    traversal.push_back(root->val);
    minDiffInBST(root->right, traversal);
}

int minDiffInBST(TreeNode* root) {
    vector<int> traversal;

    minDiffInBST(root, traversal);

    int difference = INT_MAX;

    for(int n = traversal.size() - 1; n > 0; --n) {
        if(traversal[n] - traversal[n - 1] < difference) {
            difference = traversal[n] - traversal[n - 1];
        }
    }

    return difference;
}
void printTree(TreeNode* root) {
    if (root == nullptr) {
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

void runTest(TreeNode* root, int expected) {
    cout << "Tree structure:" << endl;
    printTree(root);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minDiffInBST(root) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);

    runTest(root1, 1);

    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(5);
    root2->right->left = new TreeNode(3);

    runTest(root2, 2);

    TreeNode* root3 = new TreeNode(10);
    root3->left = new TreeNode(5);
    root3->right = new TreeNode(15);
    root3->right->left = new TreeNode(12);
    root3->right->right = new TreeNode(18);

    runTest(root3, 2);

    TreeNode* root4 = new TreeNode(27);
    root4->left = new TreeNode(14);
    root4->left->left = new TreeNode(10);
    root4->left->right = new TreeNode(19);
    root4->left->right->left = new TreeNode(16);
    root4->left->right->right = new TreeNode(22);

    runTest(root4, 2);

    TreeNode* root5 = new TreeNode(40);
    root5->left = new TreeNode(20);
    root5->right = new TreeNode(60);
    root5->right->left = new TreeNode(50);
    root5->right->right = new TreeNode(70);

    runTest(root5, 10);

    return 0;
}
