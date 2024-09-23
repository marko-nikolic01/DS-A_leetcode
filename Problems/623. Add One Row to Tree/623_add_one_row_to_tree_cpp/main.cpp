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

TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if(depth == 1) {
        return new TreeNode(val, root, nullptr);
    }

    if(depth-- == 2) {
        root->left = new TreeNode(val, root->left, nullptr);
        root->right = new TreeNode(val, nullptr, root->right);
    } else {
        if(root->left) {
            addOneRow(root->left, val, depth);
        }

        if(root->right) {
            addOneRow(root->right, val, depth);
        }
    }

    return root;
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

void test(TreeNode* root, int val, int depth, TreeNode* expected) {
    cout << "Tree: " << endl;
    printLevelOrder(root);

    cout << "Value: " << val << endl;

    cout << "Depth: " << depth << endl;

    cout << "Expected:" << endl;
    printLevelOrder(expected);

    cout << "Result:" << endl;
    printLevelOrder(addOneRow(root, val, depth));

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(4, new TreeNode(2, new TreeNode(3), new TreeNode(1)), new TreeNode(6, new TreeNode(5), nullptr));
    TreeNode* expected1 = new TreeNode(4, new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(1)), nullptr), new TreeNode(1, nullptr, new TreeNode(6, new TreeNode(5), nullptr)));
    test(root1, 1, 2, expected1);

    TreeNode* root2 = new TreeNode(4);
    TreeNode* expected2 = new TreeNode(1, new TreeNode(4), nullptr);
    test(root2, 1, 1, expected2);

    TreeNode* root3 = new TreeNode(4, new TreeNode(2), nullptr);
    TreeNode* expected3 = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(1)), nullptr);
    test(root3, 1, 3, expected3);

    TreeNode* root4 = new TreeNode(1, new TreeNode(1), new TreeNode(1));
    TreeNode* expected4 = new TreeNode(1, new TreeNode(1), new TreeNode(1));
    test(root4, 100, 100, expected4);

    return 0;
}
