#include <iostream>
#include <vector>
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

vector<double> averageOfLevels(TreeNode* root) {
    queue<TreeNode*> level;
    level.push(root);

    vector<double> averages;

    while(!level.empty()) {
        int n = level.size();
        long sum = 0;

        for(int i = 0; i < n; ++i) {
            sum += level.front()->val;

            if(level.front()->left) {
                level.push(level.front()->left);
            }

            if(level.front()->right) {
                level.push(level.front()->right);
            }

            level.pop();
        }

        averages.push_back((double)sum / n);
    }

    return averages;
}

void printTree(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
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

void runTest(TreeNode* root, const vector<double>& expected) {
    cout << "Tree:" << endl;
    printTree(root);

    cout << "Expected: ";
    for(double val : expected) {
        cout << val << " ";
    }
    cout << endl;

    vector<double> result = averageOfLevels(root);
    cout << "Result: ";
    for(double val : result) {
        cout << val << " ";
    }
    cout << endl << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    vector<double> expected1 = {3.00000, 14.50000, 11.00000};
    runTest(root1, expected1);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(7);
    vector<double> expected2 = {1.00000, 2.50000, 5.50000};
    runTest(root2, expected2);

    TreeNode* root3 = new TreeNode(5);
    root3->left = new TreeNode(10);
    root3->right = new TreeNode(20);
    root3->right->left = new TreeNode(15);
    root3->right->right = new TreeNode(25);
    vector<double> expected3 = {5.00000, 15.00000, 20.00000};
    runTest(root3, expected3);

    TreeNode* root4 = new TreeNode(7);
    vector<double> expected4 = {7.00000};
    runTest(root4, expected4);

    return 0;
}
