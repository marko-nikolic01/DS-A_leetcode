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

int longestUnivaluePath(TreeNode* root, int& longestPath) {
    int left = 0;
    if(root->left) {
        if(root->left->val == root->val) {
            left = 1 + longestUnivaluePath(root->left, longestPath);
        } else {
            longestUnivaluePath(root->left, longestPath);
        }
    }

    int right = 0;
    if(root->right) {
        if(root->right->val == root->val) {
            right = 1 + longestUnivaluePath(root->right, longestPath);
        } else {
            longestUnivaluePath(root->right, longestPath);
        }
    }

    if(left + right > longestPath) {
        longestPath = left + right;
    }

    return left > right ? left : right;
}

int longestUnivaluePath(TreeNode* root) {
    if(!root) {
        return 0;
    }

    int longestPath = 0;

    longestUnivaluePath(root, longestPath);

    return longestPath;
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << endl;;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        cout << endl;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            }
        }
    }
}

void test(TreeNode* root, int expected) {
    cout << "Tree:";
    printTree(root);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestUnivaluePath(root) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(1);
    root1->right->right = new TreeNode(5);
    test(root1, 2);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(5);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(5);
    test(root2, 2);

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(1);
    root3->right = new TreeNode(1);
    root3->left->left = new TreeNode(1);
    root3->left->right = new TreeNode(1);
    root3->right->left = new TreeNode(1);
    root3->right->right = new TreeNode(1);
    test(root3, 4);

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    test(root4, 0);

    TreeNode* root5 = new TreeNode(1);
    test(root5, 0);

    TreeNode* root6 = nullptr;
    test(root6, 0);

    return 0;
}
