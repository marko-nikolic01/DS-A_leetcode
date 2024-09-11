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

int rangeSumBST(TreeNode* root, int low, int high) {
    if(!root) {
        return 0;
    }

    if(root->val < low) {
        return rangeSumBST(root->right, low, high);
    } else if(root->val > high) {
        return rangeSumBST(root->left, low, high);
    }

    return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high) + root->val;
}

void printTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        while (levelSize--) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "nullptr ";
            }
        }
        cout << endl;
    }
}

void runTestCase(TreeNode* root, int low, int high, int expected) {
    cout << "Tree:" << endl;
    printTree(root);

    cout << "Range: [" << low << ", " << high << "]" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << rangeSumBST(root, low, high) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(10, new TreeNode(5, new TreeNode(3), new TreeNode(7)), new TreeNode(15, nullptr, new TreeNode(18)));
    runTestCase(root1, 7, 15, 32);

    TreeNode* root2 = new TreeNode(10, new TreeNode(5, new TreeNode(3, new TreeNode(1), nullptr), new TreeNode(7)), new TreeNode(15, new TreeNode(13), new TreeNode(18)));
    runTestCase(root2, 6, 10, 17);

    TreeNode* root3 = new TreeNode(10, new TreeNode(5, new TreeNode(3), new TreeNode(7)), new TreeNode(15, new TreeNode(13), new TreeNode(18)));
    runTestCase(root3, 1, 18, 71);

    TreeNode* root4 = nullptr;
    runTestCase(root4, 1, 2, 0);

    return 0;
}
