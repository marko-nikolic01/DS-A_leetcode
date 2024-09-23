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

vector<int> largestValues(TreeNode* root) {
    if(!root) {
        return {};
    }

    queue<TreeNode*> level;
    level.push(root);

    vector<int> largestValues;

    int currentLevel = 0;

    while(!level.empty()) {
        largestValues.push_back(level.front()->val);

        for(int i = level.size(); i > 0; --i) {
            if(level.front()->val > largestValues[currentLevel]) {
                largestValues[currentLevel] = level.front()->val;
            }

            if(level.front()->left) {
                level.push(level.front()->left);
            }

            if(level.front()->right) {
                level.push(level.front()->right);
            }

            level.pop();
        }

        currentLevel++;
    }

    return largestValues;
}

void printLevelOrder(TreeNode* root) {
    if (!root) {
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

void testLargestValues(TreeNode* root, const vector<int>& expected) {
    cout << "Tree:" << endl;
    printLevelOrder(root);

    cout << "Expected: ";
    for (int val : expected) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int val : largestValues(root)) {
        cout << val << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);
    root1->left->right = new TreeNode(3);
    root1->right->right = new TreeNode(9);
    vector<int> expected1 = {1, 3, 9};
    testLargestValues(root1, expected1);

    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(10);
    root2->left->left = new TreeNode(2);
    root2->right->right = new TreeNode(15);
    vector<int> expected2 = {5, 10, 15};
    testLargestValues(root2, expected2);

    TreeNode* root3 = new TreeNode(5);
    root3->left = new TreeNode(4);
    root3->left->left = new TreeNode(3);
    root3->left->left->left = new TreeNode(2);
    root3->left->left->left->left = new TreeNode(1);
    vector<int> expected3 = {5, 4, 3, 2, 1};
    testLargestValues(root3, expected3);

    TreeNode* root4 = nullptr;
    vector<int> expected4 = {};
    testLargestValues(root4, expected4);

    TreeNode* root5 = new TreeNode(1);
    vector<int> expected5 = {1};
    testLargestValues(root5, expected5);

    return 0;
}
