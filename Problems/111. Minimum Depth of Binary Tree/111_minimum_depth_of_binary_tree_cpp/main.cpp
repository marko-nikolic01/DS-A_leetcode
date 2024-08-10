#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int minDepth(TreeNode* root) {
    if(!root) {
        return 0;
    }

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if(left != 0 && right == 0){
        return ++left;
    } else if(right != 0 && left == 0) {
        return ++right;
    }

    if(left < right) {
        return ++left;
    }
    return ++right;
}

int main()
{
    TreeNode* root1 = nullptr;
    cout << "Test case 1: " << (minDepth(root1) == 0) << endl;

    TreeNode* root2 = new TreeNode(1);
    cout << "Test case 2: " << (minDepth(root2) == 1) << endl;

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(5);
    root3->right->left = new TreeNode(6);
    root3->right->right = new TreeNode(7);
    cout << "Test case 3: " << (minDepth(root3) == 2) << endl;

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->left->left = new TreeNode(3);
    root4->left->left->left = new TreeNode(4);
    root4->right = new TreeNode(5);
    cout << "Test case 4: " << (minDepth(root4) == 2) << endl;

    TreeNode* root5 = new TreeNode(1);
    root5->right = new TreeNode(2);
    root5->right->right = new TreeNode(3);
    root5->right->right->right = new TreeNode(4);
    root5->left = new TreeNode(5);
    cout << "Test case 5: " << (minDepth(root5) == 2) << endl;

    return 0;
}
