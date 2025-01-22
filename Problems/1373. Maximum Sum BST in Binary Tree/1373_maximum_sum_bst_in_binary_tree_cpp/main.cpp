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

int maxSumBST(TreeNode* root, bool& isBinarySearchTree, int& maxSum, int& min, int& max) {
    if(root->val > max) {
        max = root->val;
    }

    if(root->val < min) {
        min = root->val;
    }

    int left = 0;

    if(root->left) {
        bool isLeftBinarySearchTree = true;
        int leftMin = 40001;
        int leftMax = -40001;

        left = maxSumBST(root->left, isLeftBinarySearchTree, maxSum, leftMin, leftMax);

        if(isLeftBinarySearchTree && left > maxSum) {
            maxSum = left;
        }

        isBinarySearchTree = isBinarySearchTree && isLeftBinarySearchTree && leftMax < root->val;

        if(leftMax > max) {
            max = leftMax;
        }

        if(leftMin < min) {
            min = leftMin;
        }
    }

    int right = 0;

    if(root->right) {
        bool isRightBinarySearchTree = true;
        int rightMin = 40001;
        int rightMax = -40001;

        right = maxSumBST(root->right, isRightBinarySearchTree, maxSum, rightMin, rightMax);

        if(isRightBinarySearchTree && right > maxSum) {
            maxSum = right;
        }

        isBinarySearchTree = isBinarySearchTree && isRightBinarySearchTree && rightMin > root->val;

        if(rightMax > max) {
            max = rightMax;
        }

        if(rightMin < min) {
            min = rightMin;
        }
    }

    if(isBinarySearchTree) {
        left += right + root->val;

        if(left > maxSum) {
            maxSum = left;
        }

        return left;
    }

    return 0;
}

int maxSumBST(TreeNode* root) {
    int maxSum = 0;
    bool isBinarySearchTree = true;
    int min = 0;
    int max = 0;

    maxSumBST(root, isBinarySearchTree, maxSum, min, max);

    return maxSum;
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

    cout << "Result: " << maxSumBST(root) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(2);
    root1->right->right = new TreeNode(5);
    root1->right->right->left = new TreeNode(4);
    root1->right->right->right = new TreeNode(6);
    test(root1, 20);

    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(3);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(2);
    test(root2, 2);

    TreeNode* root3 = new TreeNode(-4);
    root3->left = new TreeNode(-2);
    root3->right = new TreeNode(-5);
    test(root3, 0);

    TreeNode* root4 = new TreeNode(1);
    root4->right = new TreeNode(10);
    root4->right->left = new TreeNode(-5);
    root4->right->right = new TreeNode(20);
    test(root4, 25);

    TreeNode* root5 = new TreeNode(5);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(10);
    root5->left->left = new TreeNode(1);
    root5->left->right = new TreeNode(3);
    root5->right->left = new TreeNode(7);
    root5->right->right = new TreeNode(15);
    test(root5, 43);

    TreeNode* root6 = new TreeNode(0);
    root6->left = new TreeNode(-3);
    root6->right = new TreeNode(4);
    root6->left->left = new TreeNode(-5);
    root6->left->right = new TreeNode(-1);
    root6->right->left = new TreeNode(3);
    root6->right->right = new TreeNode(6);
    test(root6, 13);

    return 0;
}
