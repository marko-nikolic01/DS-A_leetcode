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

void maxAncestorDiff(TreeNode* root, int min, int max, int& maxAncestorDifference) {
    if(root->val < min) {
        min = root->val;
    } else if(root->val > max) {
        max = root->val;
    }

    if(!root->left && !root->right) {
        if(max - min > maxAncestorDifference) {
            maxAncestorDifference = max - min;
        }
        return;
    }

    if(root->left) {
        maxAncestorDiff(root->left, min, max, maxAncestorDifference);
    }

    if(root->right) {
        maxAncestorDiff(root->right, min, max, maxAncestorDifference);
    }
}

int maxAncestorDiff(TreeNode* root) {
    int maxAncestorDifference = 0;

    maxAncestorDiff(root, root->val, root->val, maxAncestorDifference);

    return maxAncestorDifference;
}

void printTree(TreeNode* root) {
    if(!root) {
        cout << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if(node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            }
        }
        if(!q.empty()) {
            cout << endl;
        }
    }
}

void test(TreeNode* root, int expected) {
    cout << "Tree:" << endl;;
    printTree(root);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxAncestorDiff(root) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    test(root1, 2);

    TreeNode* root2 = new TreeNode(8, new TreeNode(3, new TreeNode(1), new TreeNode(6, new TreeNode(4), new TreeNode(7))), new TreeNode(10, nullptr, new TreeNode(14, new TreeNode(13), nullptr)));
    test(root2, 7);

    TreeNode* root3 = new TreeNode(5, new TreeNode(11), nullptr);
    test(root3, 6);

    TreeNode* root4 = new TreeNode(4, new TreeNode(4), new TreeNode(4));
    test(root4, 0);

    TreeNode* root5 = new TreeNode(10, new TreeNode(5, new TreeNode(1), nullptr), new TreeNode(20, nullptr, new TreeNode(25)));
    test(root5, 15);

    return 0;
}
