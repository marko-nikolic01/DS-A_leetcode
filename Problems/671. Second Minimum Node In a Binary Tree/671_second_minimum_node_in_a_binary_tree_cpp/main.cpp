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

int findSecondMinimumValue(TreeNode* root) {
    if(!root->left) {
        return -1;
    }

    int min1;
    int min2;

    if(root->left->val != root->val) {
        min1 = root->left->val;
    } else {
        min1 = findSecondMinimumValue(root->left);
    }

    if(root->right->val != root->val) {
        min2 = root->right->val;
    } else {
        min2 = findSecondMinimumValue(root->right);
    }

    if(min1 == -1) {
        return min2;
    } else if (min2 == -1) {
        return min1;
    }

    return min1 < min2 ? min1 : min2;
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

int main() {
    TreeNode* root1 = new TreeNode(2, new TreeNode(2), new TreeNode(5, new TreeNode(5), new TreeNode(7)));
    cout << "Tree 1:" << endl;
    printTree(root1);
    cout << "Expected: 5" << endl;
    cout << "Result: " << findSecondMinimumValue(root1) << endl;
    cout << endl;

    TreeNode* root2 = new TreeNode(2, new TreeNode(2), new TreeNode(2));
    cout << "Tree 2:" << endl;
    printTree(root2);
    cout << "Expected: -1" << endl;
    cout << "Result: " << findSecondMinimumValue(root2) << endl;
    cout << endl;

    TreeNode* root3 = new TreeNode(1, new TreeNode(1), new TreeNode(3));
    cout << "Tree 3:" << endl;
    printTree(root3);
    cout << "Expected: 3" << endl;
    cout << "Result: " << findSecondMinimumValue(root3) << endl;
    cout << endl;

    TreeNode* root4 = new TreeNode(1, new TreeNode(1), new TreeNode(1, new TreeNode(1), new TreeNode(4)));
    cout << "Tree 4:" << endl;
    printTree(root4);
    cout << "Expected: 4" << endl;
    cout << "Result: " << findSecondMinimumValue(root4) << endl;
    cout << endl;

    TreeNode* root5 = new TreeNode(5);
    cout << "Tree 5:" << endl;
    printTree(root5);
    cout << "Expected: -1" << endl;
    cout << "Result: " << findSecondMinimumValue(root5) << endl;

    return 0;
}
