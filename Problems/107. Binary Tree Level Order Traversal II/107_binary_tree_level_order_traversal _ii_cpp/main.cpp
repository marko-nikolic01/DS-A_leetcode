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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if(!root) {
        return {};
    }

    vector<vector<int>> levels;

    queue<TreeNode*> levelNodes;
    levelNodes.push(root);

    while(!levelNodes.empty()) {
        vector<int> level;

        int n = levelNodes.size();
        for(n; n > 0; --n) {
            level.push_back(levelNodes.front()->val);

            if(levelNodes.front()->left) {
                levelNodes.push(levelNodes.front()->left);
            }

            if(levelNodes.front()->right) {
                levelNodes.push(levelNodes.front()->right);
            }

            levelNodes.pop();
        }

        levels.push_back(level);
    }

    int n = levels.size();
    for(int i = 0; i < n/2; ++i) {
        vector<int> temp = levels[i];
        levels[i] = levels[n - i - 1];
        levels[n - i - 1] = temp;
    }

    return levels;
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void testLevelOrderBottom(TreeNode* root, const vector<vector<int>>& expected) {
    vector<vector<int>> result = levelOrderBottom(root);

    cout << "Tree:" << endl;
    printLevelOrder(root);

    cout << "Expected: ";
    for (const auto& level : expected) {
        cout << "[";
        for (size_t i = 0; i < level.size(); ++i) {
            cout << level[i];
            if (i < level.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Result: ";
    for (const auto& level : result) {
        cout << "[";
        for (size_t i = 0; i < level.size(); ++i) {
            cout << level[i];
            if (i < level.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    testLevelOrderBottom(NULL, {});

    TreeNode* root2 = new TreeNode(1);
    testLevelOrderBottom(root2, {{1}});

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(5);
    root3->right->left = new TreeNode(6);
    root3->right->right = new TreeNode(7);
    testLevelOrderBottom(root3, {{4, 5, 6, 7}, {2, 3}, {1}});

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    root4->left->left = new TreeNode(4);
    root4->right->right = new TreeNode(5);
    testLevelOrderBottom(root4, {{4, 5}, {2, 3}, {1}});

    return 0;
}
