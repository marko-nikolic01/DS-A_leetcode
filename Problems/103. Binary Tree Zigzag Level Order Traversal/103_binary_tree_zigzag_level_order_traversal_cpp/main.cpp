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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(!root) {
        return {};
    }

    queue<TreeNode*> nodes;
    nodes.push(root);

    bool direction = false;

    vector<vector<int>> levelOrders;

    while(!nodes.empty()) {
        int n = nodes.size();
        vector<int> levelOrder(n);

        for(int i = 0; i < n; ++i) {
            int index = direction ? n - i - 1 : i;
            levelOrder[index] = nodes.front()->val;

            if(nodes.front()->left) {
                nodes.push(nodes.front()->left);
            }

            if(nodes.front()->right) {
                nodes.push(nodes.front()->right);
            }

            nodes.pop();
        }

        direction = !direction;

        levelOrders.push_back(levelOrder);
    }

    return levelOrders;
}

void printLevelOrder(const vector<vector<int>>& result) {
    for (const auto& level : result) {
        cout << "[ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "]";
    }
    cout << endl;
}

void printTreeLevelByLevel(TreeNode* root) {
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

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        cout << endl;
    }
}

void testLevelOrder(TreeNode* root, const vector<vector<int>>& expected) {
    cout << "Tree:" << endl;
    printTreeLevelByLevel(root);

    cout << "Expected: ";
    printLevelOrder(expected);

    cout << "Result:   ";
    printLevelOrder(zigzagLevelOrder(root));

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);

    vector<vector<int>> expected1 = {{1}, {3, 2}, {4, 5, 6, 7}};
    testLevelOrder(root1, expected1);

    TreeNode* root2 = new TreeNode(10);

    vector<vector<int>> expected2 = {{10}};
    testLevelOrder(root2, expected2);

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(5);
    root3->right->left = new TreeNode(6);
    root3->right->right = new TreeNode(7);
    root3->left->left->left = new TreeNode(8);
    root3->left->left->right = new TreeNode(9);

    vector<vector<int>> expected3 = {{1}, {3, 2}, {4, 5, 6, 7}, {9, 8}};
    testLevelOrder(root3, expected3);

    TreeNode* root4 = nullptr;
    vector<vector<int>> expected4 = {};
    testLevelOrder(root4, expected4);

    return 0;
}
