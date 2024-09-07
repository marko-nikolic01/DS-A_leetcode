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

vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root) {
        return {};
    }

    queue<TreeNode*> nodes;
    nodes.push(root);

    vector<vector<int>> levelOrders;
    while(!nodes.empty()) {
        vector<int> levelOrder;

        for(int i = nodes.size(); i > 0; --i) {
            levelOrder.push_back(nodes.front()->val);

            if(nodes.front()->left) {
                nodes.push(nodes.front()->left);
            }

            if(nodes.front()->right) {
                nodes.push(nodes.front()->right);
            }

            nodes.pop();
        }

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
        cout << "Tree is empty." << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    cout << "Tree (level by level):" << endl;
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
    printLevelOrder(levelOrder(root));

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    vector<vector<int>> expected1 = {{1}, {2, 3}, {4, 5}};
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
    vector<vector<int>> expected3 = {{1}, {2, 3}, {4, 5, 6, 7}};
    testLevelOrder(root3, expected3);

    return 0;
}

