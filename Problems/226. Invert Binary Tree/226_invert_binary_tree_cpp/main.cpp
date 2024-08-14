#include <iostream>
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

TreeNode* invertTree(TreeNode* root) {
    if(root) {
        invertTree(root->left);
        invertTree(root->right);

        TreeNode* temp = root->left;
;        root->left = temp;
        root->right = root-> left;
    }

    return root;
}

void printTree(TreeNode* root) {
    if(!root) {
        cout << "null ";
        return;
    }

    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    TreeNode* root1 = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    TreeNode* root2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* root3 = new TreeNode(1);
    TreeNode* root4 = nullptr;

    cout << "Test case 1:\nTree: ";
    printTree(root1);
    cout << "\nInverted Tree: ";
    printTree(invertTree(root1));
    cout << "\n\n";

    cout << "Test case 2:\nTree: ";
    printTree(root2);
    cout << "\nInverted Tree: ";
    printTree(invertTree(root2));
    cout << "\n\n";

    cout << "Test case 3:\nTree: ";
    printTree(root3);
    cout << "\nInverted Tree: ";
    printTree(invertTree(root3));
    cout << "\n\n";

    cout << "Test case 4:\nTree: ";
    printTree(root4);
    cout << "\nInverted Tree: ";
    printTree(invertTree(root4));
    cout << "\n";

    return 0;
}
