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

void maxProduct(TreeNode* root, int& sum) {
    sum += root->val;

    if(root->left) {
        maxProduct(root->left, sum);
    }

    if(root->right) {
        maxProduct(root->right, sum);
    }
}

int maxProduct(TreeNode* root, int& sum, long& product) {
    int leftSum = 0;
    int rightSum = 0;

    if(root->left) {
        leftSum = maxProduct(root->left, sum, product);

        if((long)(sum - leftSum) * leftSum > product) {
            product = (long)(sum - leftSum) * leftSum;
        }
    }

    if(root->right) {
        rightSum = maxProduct(root->right, sum, product);

        if((long)(sum - rightSum) * rightSum > product) {
            product = (long)(sum - rightSum) * rightSum;
        }
    }

    return leftSum + rightSum + root->val;
}

int maxProduct(TreeNode* root) {
    int sum = 0;
    long product = 0;

    maxProduct(root, sum);
    maxProduct(root, sum, product);

    return product % 1000000007;
}

void printTree(TreeNode* root) {
    if(!root) {
        cout << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
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
    cout << "Tree: ";
    printTree(root);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxProduct(root) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    test(root1, 110);

    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(4);
    root2->right->right->left = new TreeNode(5);
    root2->right->right->right = new TreeNode(6);
    test(root2, 90);

    TreeNode* root3 = new TreeNode(2);
    root3->left = new TreeNode(3);
    root3->right = new TreeNode(9);
    test(root3, 45);

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    root4->left->left = new TreeNode(4);
    root4->right->right = new TreeNode(5);
    test(root4, 56);

    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(5);
    root5->left->left = new TreeNode(3);
    root5->left->right = new TreeNode(4);
    root5->right->left = new TreeNode(6);
    root5->right->right = new TreeNode(7);
    test(root5, 180);

    return 0;
}
