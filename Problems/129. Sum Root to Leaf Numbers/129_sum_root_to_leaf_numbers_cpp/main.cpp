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

int sumNumbers(TreeNode* root, int sum) {
    sum = 10 * sum + root->val;

    if(root->left) {
        return sumNumbers(root->left, sum) + (root->right ? sumNumbers(root->right, sum) : 0);
    } else if(root->right) {
        return sumNumbers(root->right, sum);
    }

    return sum;
}

int sumNumbers(TreeNode* root) {
    return sumNumbers(root, 0);
}

void printTreeLevelByLevel(TreeNode* root) {
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

void runTest(TreeNode* root, int expected) {
    cout << "Tree:" << endl;
    printTreeLevelByLevel(root);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << sumNumbers(root) << endl;


    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    runTest(root1, 25);

    TreeNode* root2 = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    runTest(root2, 1026);

    TreeNode* root3 = new TreeNode(1);
    runTest(root3, 1);

    TreeNode* root4 = new TreeNode(1, new TreeNode(0), nullptr);
    runTest(root4, 10);

    return 0;
}
