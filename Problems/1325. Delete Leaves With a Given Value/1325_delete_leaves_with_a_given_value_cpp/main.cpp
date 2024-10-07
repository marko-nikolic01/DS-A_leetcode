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

TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if(root->left) {
        root->left = removeLeafNodes(root->left, target);
    }

    if(root->right) {
        root->right = removeLeafNodes(root->right, target);
    }

    if(!root->left && !root->right && root->val == target) {
        return nullptr;
    }

    return root;
}

void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "null" << endl;
        return;
    }

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

void testRemoveLeafNodes(TreeNode* root, TreeNode* expected, int target) {
    cout << "Tree: " << endl;
    printLevelOrder(root);

    cout << "Target: " << target << endl;

    cout << "Expected: " << endl;
    printLevelOrder(expected);

    cout << "Result: " << endl;
    printLevelOrder(removeLeafNodes(root, target));

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1, new TreeNode(2, new TreeNode(2), nullptr), new TreeNode(3, new TreeNode(2), new TreeNode(4)));
    TreeNode* expected1 = new TreeNode(1, nullptr, new TreeNode(3, nullptr, new TreeNode(4)));
    testRemoveLeafNodes(root1, expected1, 2);

    TreeNode* root2 = new TreeNode(1, new TreeNode(3, new TreeNode(3), nullptr), new TreeNode(3, new TreeNode(3), new TreeNode(4)));
    TreeNode* expected2 = new TreeNode(1, nullptr, new TreeNode(3, nullptr, new TreeNode(4)));
    testRemoveLeafNodes(root2, expected2, 3);

    TreeNode* root3 = new TreeNode(2, new TreeNode(2), new TreeNode(2));
    TreeNode* expected3 = nullptr;
    testRemoveLeafNodes(root3, expected3, 2);

    TreeNode* root4 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* expected4 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    testRemoveLeafNodes(root4, expected4, 4);

    return 0;
}
