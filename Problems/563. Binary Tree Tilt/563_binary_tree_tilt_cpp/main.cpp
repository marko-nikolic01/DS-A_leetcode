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

int findTilt(TreeNode* root, int& sum) {
    if(!root) {
        return 0;
    }

    int left = findTilt(root->left, sum);
    int right = findTilt(root->right, sum);

    int tilt = left - right;
    if(tilt < 0) {
        tilt = -tilt;
    }

    sum += tilt;

    return left + right + root->val;
}

int findTilt(TreeNode* root) {
    int sum = 0;

    findTilt(root, sum);

    return sum;
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << "Tree is empty!" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            TreeNode* current = q.front();
            q.pop();

            if (current) {
                cout << current->val << " ";
                q.push(current->left);
                q.push(current->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl;
    }
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    cout << "Test Case 1:" << endl;
    printTree(root1);
    cout << "Expected: 1" << endl;
    cout << "Result: " << findTilt(root1) << endl;
    cout << endl;

    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(9);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(5);
    root2->right->right = new TreeNode(7);
    cout << "Test Case 2:" << endl;
    printTree(root2);
    cout << "Expected: 15" << endl;
    cout << "Result: " << findTilt(root2) << endl;
    cout << endl;

    TreeNode* root3 = new TreeNode(21);
    root3->left = new TreeNode(7);
    root3->right = new TreeNode(14);
    root3->left->left = new TreeNode(1);
    root3->left->right = new TreeNode(1);
    root3->right->left = new TreeNode(2);
    root3->right->right = new TreeNode(2);
    cout << "Test Case 3:" << endl;
    printTree(root3);
    cout << "Expected: 9" << endl;
    cout << "Result: " << findTilt(root3) << endl;

    return 0;
}
